// #include "common.h"
#include "lift.h"
#include "states.h"

namespace lift {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, pros::Optical *optical, PIDConstants constants) : motor(motor), rot(rot), optical(optical) {
    currentState = &One::getInstance();
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
    if (task == nullptr) {
        task = new pros::Task{[=] {
            while (true) {
                control();
                pros::delay(10);
            }
        }};
    }
}

void Lift::control() {
    motor -> move(pid.out(rot -> get_position() - target));
    std::cout << "target: " << target/100.0 << " | actual: " << rot ->get_position()/100.0 << " | error: " << pid.out(rot -> get_position() - target) << std::endl;
}

void Lift::setState(LiftState& state) {
    currentState->exit(this);
    currentState = &state;
    currentState->enter(this);
}

void Lift::next() {
    currentState->next(this);
}

void Lift::prev() {
    currentState->prev(this);
}

void Lift::score() {
    switch (currentState -> getState()) {
        case LiftState::lower:
            setState(Lowest::getInstance());
            break;
        default:
            setState(Lower::getInstance());
            break;
    }
    setRebound(true);
}

void Lift::setTarget(double target) {
    this->target = target*100;
}

double Lift::getDerivative() {
    return pid.getDerivative();
}

bool Lift::getReboud() {
    return rebound;
}

void Lift::setRebound(bool rebound) {
    this->rebound = rebound;
}
}