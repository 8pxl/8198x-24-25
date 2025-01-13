// #include "common.h"
#include "lift.h"

namespace lift {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    currentState = LiftState::idle;
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
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

void Lift::control() {
    double angle = rot -> get_position();
    error = angle - target;
    motor -> move(pid.out(error) + kf * cos(angle + angleOffset));
}

void Lift::setState(LiftState state) {
    currentState = state;
}

void Lift::next() {
    currentState = stateMap.get_value(currentState);
}

void Lift::prev() {
    currentState = stateMap.get_key(currentState);
}

void Lift::setTarget(double target) {
    this->target = target*100;
}
}