#include "states.h"
#include "vStates.h"

namespace intake {

//idle state
void Idle::enter(Intake *intake) {
    intake ->setTarget(0);
}
void Idle::exit(Intake *intake) {
}
void Idle::next(Intake *intake) {
    intake -> setState(On::getInstance());
}
void Idle::prev(Intake *intake) {
    intake -> setState(On::getInstance());
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
}
void On::exit(Intake *intake) {
}
void On::next(Intake *intake) {
    
}
void On::prev(Intake *intake) {
    intake -> setState(Idle::getInstance());
}
void On::control(Intake *intake) {
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
}
Sort::State Sort::getState() {
    return sort;
}
IntakeState& Sort::getInstance() {
    static Sort singleton;
    return singleton;
}
}