#include "lift.h"
#include "main.h"

namespace keejLib {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    currentState = LiftState::idle;
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
    if (task == nullptr) {
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
    motor -> move(pid.out(error) + kf * cos(angle + angleOffset));
}

void Lift::setState(LiftState state) {
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