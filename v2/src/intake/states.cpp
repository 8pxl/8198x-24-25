#include "states.h"
#include "vStates.h"

namespace ifsm {

//idle state
void Idle::enter(Intake *intake) {
    intake -> move(0);
    intake -> setPwm(0);
}
void Idle::exit(Intake *intake) {
}
void Idle::next(Intake *intake) {
    intake -> setState(On::getInstance());
}
void Idle::prev(Intake *intake) {
}
void Idle::control(Intake *intake) {
}
Idle::State Idle::getState() {
    return idle;
}
IntakeState& Idle::getInstance() {
    static Idle singleton;
    return singleton;
}

//On state
void On::enter(Intake *intake) {
    intake->setPwm(100);
}
void On::exit(Intake *intake) {
}
void On::next(Intake *intake) {
}
void On::prev(Intake *intake) {
    intake -> setState(Idle::getInstance());
}
void On::control(Intake *intake) {
    if (intake -> getOptical() != intake->getColor() && intake -> getOptical() != none) {
        intake -> setState(Sort::getInstance());
    }
}
On::State On::getState() {
    return on;
}
IntakeState& On::getInstance() {
    static On singleton;
    return singleton;
}
//Sort state
void Sort::enter(Intake *intake) {
    s1.reset();
    prevVel = intake->getSpeed();
}
void Sort::exit(Intake *intake) {
}
void Sort::next(Intake *intake) {
    intake -> setState(On::getInstance());
}
void Sort::prev(Intake *intake) {
    intake -> setState(On::getInstance());
}
void Sort::control(Intake *intake) {
    if (s1.elapsed() > 90) {
        intake -> setSpeed(-127);
    }
    if (s1.elapsed() > 400) {
        intake->setSpeed(prevVel);
        intake -> setState(On::getInstance());
    }
}
Sort::State Sort::getState() {
    return sort;
}
IntakeState& Sort::getInstance() {
    static Sort singleton;
    return singleton;
}
}