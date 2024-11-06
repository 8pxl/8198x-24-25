#include "Intake.h"
#include "keejLib/util.h"
#include "states.h"

namespace ifsm {

Intake::Intake(pros::Motor *motor, pros::Optical *optical, Color color) : motor(motor), optical(optical), color(color) {
    currentState = &Idle::getInstance();
}

void Intake::startControl() {
    if (task == nullptr) {
        task = new pros::Task{[=] {
            while (true) {
                control();
                pros::delay(10);
            }
        }};
    }
}

void Intake::control() {
    motor->move(speed);
    currentState->control(this);
}

void Intake::setState(IntakeState& state) {
    currentState->exit(this);
    currentState = &state;
    currentState->enter(this);
}

void Intake::next() {
    currentState->next(this);
}

void Intake::move(double speed) {
    if (speed == 0) {
        setState(Idle::getInstance());
    }
    
    this->speed = speed;
}

double Intake::getSpeed() {
    return speed;
}

Color Intake::getOptical() {
    return none;
}

Color Intake::getColorToSort() {
    switch (color) {
        case red:
            return blue;
        case blue:
            return red;
        case none:
            return none;
    }
}
}