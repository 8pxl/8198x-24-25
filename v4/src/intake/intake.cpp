#include "Intake.h"
#include "keejLib/lib.h"
#include "../robotState/robotState.h"
#include "keejLib/util.h"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"
#include <ostream>

namespace keejLib {

Intake::Intake(pros::Motor *motor, pros::Optical *optical, pros::Distance *distance,
               Color color)
    : motor(motor), optical(optical), distance(distance), colorToSort(color), velocityEma(0.99), colorEma(1) {
      optical -> set_integration_time(5);
    }

void Intake::startControl() {
    if (task == nullptr) {
    task = new pros::Task{[this] {
      while (true) {
        control();
        pros::delay(10);
      }
    }};
  }
  pros::delay(20);
}

Color Intake::getColor() {
  return colorToSort;
}
void Intake::setColor(Color c) { colorToSort = c; }

void Intake::setAutoLift(bool val) {
  autoLift = val;
}

void Intake::move(double velocity) { 
  this->velocity = velocity; 
  colorToStop = none;
  }

void Intake::setJamProtection(bool val) {
  jamProtection = val;
}

void Intake::stopOnColor(Color col, int timeout) {
  // velocity = 105;
  colorToStop = col;
  autoStopTimer.set(timeout);
}

Color Intake::getDetected() { return colorDetected; }

Color Intake::detectColor() {
  int check = 2;
  double hue = optical->get_hue();
  double dist = optical ->get_proximity();
  int distRange = 40;
  int count = 2;
  // std::cout << dist << std::endl;
  if (dist > distRange) {
    if ((hue > colorHues[red].first) || (hue < colorHues[red].second)) {
        colorCount[red]++;
        if (colorCount[red] > count) {
            colorCount[red] = 0;
            return red;
        }
    }
    else if (inRange(hue, colorHues[blue])) {
        colorCount[blue]++;
        // std::cout << colorCount[blue] <<std::endl;
        if (colorCount[blue] > count) {
            colorCount[blue] = 0;
            return blue;
        }
    }
  }
  colorDetected = none;
  return none;
}

void Intake::handleAutoStop(Color col) {
  // std::cout << colorDetected << std::endl;
  if (col == colorToStop) {
    velocity = 0;
    colorToStop = none;
  }
}

bool Intake::ringSensed() {
    return (distance -> get_distance() < 40);
}

void Intake::handleColorSort(Color col, bool liftClear) {
  switch (col) {
      case none:
        break;
      case red:
        std::cout << "Color: Red" << std::endl;
        break;
      case blue:
        std::cout << "Color: Blue" << std::endl;
        break;
    }
    if (col != none) {
      if (col == oppositeColor(col)) taskBlocked = false;
      if (col == colorToSort) taskBlocked = true;
    }

    if (taskBlocked && liftClear) {
        jamTimer.reset();
        bool prev = 0;
        motor -> tare_position();
        while (jamTimer.elapsed() < 2000) {
            if (motor -> get_position() < sortDist){
                continue;
            }
            double curr = ringSensed();
            if (!curr && prev) break;
            prev = curr;
            motor->move(127);
            pros::delay(10);
        }
        motor->move(-50);
        pros::delay(160);
        taskBlocked = false;
        jamTimer.reset();
    }
}

bool Intake::isJammed(double actual, int tolerance) {
  return (velocity > 0 && (fabs(actual) < tolerance) && (jamTimer.elapsed() > 400));
}

void Intake::handleJamProtection(bool liftClear, RobotState * s) {
    // std::cout << "intake jammed! " <<std::endl;
    if (s->getLiftState() == LiftState::one && autoLift && ringSeen) {
      motor -> move(0);
      s->setLiftState(LiftState::two);
      pros::delay(200);
      jamTimer.reset();
      ringSeen = false;
    }
    else if ((!ringSeen) && jamProtection ) {
      Stopwatch sw;
      while (sw.elapsed() < 200) {
        motor->move(-127);
      }
      jamTimer.reset();
    }
}

void Intake::control() {
  auto s = RobotState::getInstance();
  auto liftState = s->getInstance()->getLiftState();
  bool liftClear = !(liftState == LiftState::one || liftState == LiftState::two);
  Color col = detectColor();
  double vel = velocityEma.out(motor->get_actual_velocity());
  std::cout << distance->get_distance() << std::endl;

  if (ringSensed()) {
    ringSeen = true;
  }
  if (colorToStop != none) {
    handleAutoStop(col);
  } 
  if (colorToSort != none && velocity > 0) {
    handleColorSort(col, liftClear);
  }
  int tolerance = liftClear ? 5 : 9;
  if(isJammed(vel, tolerance)) {
    handleJamProtection(liftClear, s);
  }
  else {
    motor->move(velocity);
  }
  if (velocity != 0) optical->set_led_pwm(100);
  else {
      optical->set_led_pwm(0);
      colorCount[blue] = 0;
      colorCount[red] = 0;
  }

  if (velocity <= 0) {
    jamTimer.reset();
    ringSeen = false;
  }
} 
}// namespace keejLib