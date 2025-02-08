#include "Intake.h"
#include "keejLib/lib.h"
#include "../robotState/robotState.h"
#include "keejLib/util.h"
#include <ostream>

namespace keejLib {

Intake::Intake(pros::Motor *motor, pros::Optical *optical,
               Color color)
    : motor(motor), optical(optical), colorToSort(color), velocityEma(0.9), colorEma(1) {
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
  velocity = 105;
  colorToStop = col;
  autoStopTimer.set(timeout);
}

Color Intake::getDetected() { return colorDetected; }

Color Intake::detectColor() {
  int check = 2;
  double hue = colorEma.out(optical->get_hue());
  Color color = none;
  while (check-- >= 0) {
    color = static_cast<Color>(check);
    if (inRange(hue, colorHues[color])) {
      colorDetected = color;
      return color;
    }
  }
  colorDetected = color;

  return none;
}

void Intake::handleAutoStop(Color col) {
  // std::cout << colorDetected << std::endl;
  if (col == colorToStop) {
    velocity = 0;
    colorToStop = none;
  }
}

void Intake::handleColorSort(Color col, bool liftClear) {
  // switch (col) {
  //     case none:
  //       break;
  //     case red:
  //       std::cout << "Color: Red" << std::endl;
  //       break;
  //     case blue:
  //       std::cout << "Color: Blue" << std::endl;
  //       break;
  //   }
    if (col != none) {
      if (col == oppositeColor(col)) taskBlocked = false;
      if (col == colorToSort) taskBlocked = true;
    }

    if (taskBlocked && liftClear) {
        motor -> tare_position();
        jamTimer.reset();
        while (motor->get_position() < sortDist && jamTimer.elapsed() < 2000) {
          // std::cout << motor -> get_position() << std::endl;
          motor->move(127);
        }
        motor->move(-50);
        pros::delay(160);
        taskBlocked = false;
        jamTimer.reset();
    }
}

bool Intake::isJammed(double actual) {
  return (velocity > 0 && (fabs(actual) < 5) && (jamTimer.elapsed() > 400));
}

void Intake::handleJamProtection(bool liftClear, RobotState * s) {
    // std::cout << "intake jammed! " <<std::endl;
    if (s->getLiftState() == LiftState::one && autoLift) {
      motor -> move(0);
      pros::delay(100);
      s->setLiftState(LiftState::two);
      pros::delay(100);
      jamTimer.reset();
    }
    else if (liftClear && jamProtection) {
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

  std::cout << vel << std::endl;
  if (colorToStop != none) {
    handleAutoStop(col);
  } 
  if (colorToSort != none && velocity > 0) {
    handleColorSort(col, liftClear);
  }
  if(isJammed(vel)) {
    handleJamProtection(liftClear, s);
  }
  else {
    motor->move(velocity);
  }
  if (velocity != 0) optical->set_led_pwm(100);
  else optical->set_led_pwm(0);

  if (velocity <= 0.5) jamTimer.reset();
} 
}// namespace keejLib