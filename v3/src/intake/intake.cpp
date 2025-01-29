#include "Intake.h"
#include "keejLib/lib.h"
#include "../robotState/robotState.h"
#include "keejLib/util.h"

namespace keejLib {

Intake::Intake(pros::Motor *motor, pros::Optical *optical, Pis *piston,
               Color color)
    : motor(motor), optical(optical), piston(piston), colorToSort(color), velocityEma(0.9) {
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

void Intake::setColor(Color c) { colorToSort = c; }

void Intake::move(double velocity) { this->velocity = velocity; }

Color Intake::getDetected() { return colorDetected; }

Color Intake::detectColor() {
  int check = 2;
  double hue = optical->get_hue();
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

void Intake::control() {
  auto s = RobotState::getInstance();
  auto liftState = s->getInstance()->getLiftState();
  bool liftClear = liftState == LiftState::one || liftState == LiftState::two;

  Color col = detectColor();
  if (col != none) {
    if (col == oppositeColor(col)) taskBlocked = false;
    if (col == colorToSort) taskBlocked = true;
  }

  if (taskBlocked && liftClear) {
      motor -> tare_position();
      while (motor->get_position() < sortDist) {
        motor->move(127);
      }
      motor->move(0);
      pros::delay(50);
      taskBlocked = false;
  }
  
  if (velocity >= 0) optical->set_led_pwm(100);
  else optical->set_led_pwm(0);
  double vel = velocityEma.out(motor->get_actual_velocity());
  if (velocity > 0 && fabs(vel) < 0.4 && (jamTimer.elapsed() > 400) && liftClear) {
    Stopwatch sw;
    while (sw.elapsed() < 200) {
      motor->move(-127);
      jamTimer.reset();
    }
  }
  else motor->move(velocity);

  if (velocity <= 0) jamTimer.reset();
}
} // namespace keejLib