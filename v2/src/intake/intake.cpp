#include "Intake.h"
#include "states.h"

namespace intake {

Intake::Intake(pros::Motor *motor, pros::Optical *optical) : motor(motor), optical(optical) {
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
}

void Intake::setState(IntakeState& state) {
    currentState->exit(this);
    currentState = &state;
    currentState->enter(this);
}

void Intake::next() {
    currentState->next(this);
}
}