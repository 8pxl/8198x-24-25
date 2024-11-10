#include "Intake.h"
#include "keejLib/util.h"
#include "states.h"
#include "vStates.h"

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
    pros::delay(10);
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
    if (currentState->getState() == IntakeState::sort) return;
    if (speed == 0) {
        if (currentState->getState() != IntakeState::idle) setState(Idle::getInstance());
    }
    else {
        if (currentState->getState() != IntakeState::on) setState(On::getInstance());
    }
    this->speed = speed;
}

void Intake::setSpeed(double speed) {
    this->speed = speed;
}
double Intake::getSpeed() {
    return speed;
}

Color Intake::getOptical() {
    double hue = optical->get_hue();
    if (hue > 190 && hue < 230) return blue;
    if (hue > 6 && hue < 17) return red;
    return none;
}

Color Intake::getColor() {
    return color;
}

void Intake::setPwm(int led) {
    optical->set_led_pwm(led);
}

bool Intake::getSorting() {
    return sort;
}

void Intake::setSorting(bool state) {
    sort = state;
}
}