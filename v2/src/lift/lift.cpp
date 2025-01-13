// #include "common.h"
#include "lift.h"
#include "states.h"
#include "../intake/intake.h"

namespace lift {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    currentState = &Idle::getInstance();
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
    pros::delay(20);
}

void Lift::control() {
    error = rot -> get_position() - target;
    motor -> move(pid.out(error));
    // currentState->control(this);
    // std::cout << "target: " << target/100.0 << " | actual: " << rot ->get_position()/100.0 << " | error: " << pid.out(rot -> get_position() - target) << std::endl;
    // //deriative
    // std::cout << "derivative: " << pid.getDerivative() << std::endl;
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

void Lift::toggle() {
    currentState->toggle(this);
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

double Lift::getError() {
    return error;
}

Color Lift::getColor() {
    // return intake->getOptical();
}

bool Lift::getAutoControl() {
    // autoControlMutex.take(300);
    // return autoControl;
    // autoControlMutex.give();
    return false;
}

void Lift::setAutoControl(bool autoControl) {
    // autoControlMutex.take(300);
    // this->autoControl = autoControl;
    // autoControlMutex.give();
}
}