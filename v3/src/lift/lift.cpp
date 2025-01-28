#include "lift.h"
#include "../robotState/robotState.h"
#include "main.h"

namespace keejLib {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    currentState = LiftState::idle;
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
    if (task == nullptr) {
        calibrate();
        motor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        task = new pros::Task{[this] {
            while (true) {
                control();
                pros::delay(10);
            }
        }};
    }
    pros::delay(20);
}

void Lift::calibrate() {
    double angle = rot -> get_position();
    // std::cout << "old angle: " << angle << std::endl;
    if (angle > 32000) {
        // std::cout << "set to: " << angle - 36000 << std::endl;
        rot ->set_position(angle - 36000);
    }
    // std::cout << "new angle: " << rot -> get_position() << std::endl;

}
void Lift::setControl(bool state) {
    off = !state;
}

void Lift::spin(double voltage) {
    if (off) {
        motor -> move(voltage);
        //snapping
        if (voltage == 0 && fabs(rot -> get_position() - target) <= snapRange) {
            off = false;
        }
    }
}

void Lift::control() {
    if (off) return;
    double angle = rot -> get_position();
    error = angle - target;
    // std::cout << "angle: " << angle << std::endl;
    motor -> move(pid.out(error) + kf * cos(angle + angleOffset));
}

void Lift::setState(LiftState state) {
    auto s = RobotState::getInstance();
    s -> setLiftState(currentState);
    currentState = state;
    setTarget(currentState);
}

void Lift::next() {
    setState(fwdMap[currentState]);
}

void Lift::prev() {
    setState(revMap[currentState]);
}

void Lift::setTarget(LiftState state) {
    target = valueMap[state] * 100;
}
}