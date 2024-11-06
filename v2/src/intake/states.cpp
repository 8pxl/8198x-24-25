#include "states.h"
#include "common.h"
#include "intake.h"

namespace intake {

//idle state
void Idle::enter(Intake* intake) {
    intake ->setTarget(1);
}
void Idle::next(Intake* intake) {
    intake -> setState(One::getInstance());
}
void Idle::prev(Intake* intake) {
    intake -> setState(Lowest::getInstance());
}
IntakeState& Idle::getInstance() {
    static Idle singleton;
    return singleton;
}

//one ring state
void One::enter(Intake* intake) {
    intake ->setTarget(2);
}
void One::next(Intake* intake) {
    intake -> setState(Two::getInstance());
}
void One::prev(Intake* intake) {
    intake -> setState(Idle::getInstance());
}
IntakeState& One::getInstance() {
    static One singleton;
    return singleton;
}

//two ring state
void Two::enter(Intake* intake) {
    intake ->setTarget(3);
}
void Two::next(Intake* intake) {
    intake -> setState(Prime::getInstance());
}
void Two::prev(Intake* intake) {
    intake -> setState(One::getInstance());
}
IntakeState& Two::getInstance() {
    static Two singleton;
    return singleton;
}

//prime state
void Prime::enter(Intake* intake) {
    intake ->setTarget(4);
}
void Prime::next(Intake* intake) {
    intake -> setState(Lower::getInstance());
}
void Prime::prev(Intake* intake) {
    intake -> setState(Two::getInstance());
}
IntakeState& Prime::getInstance() {
    static Prime singleton;
    return singleton;
}

//lower state (score normal stakes)
void Lower::enter(Intake* intake) {
    intake ->setTarget(5);
}
void Lower::next(Intake* intake) {
    intake -> setState(Lowest::getInstance());
}
void Lower::prev(Intake* intake) {
    intake -> setState(Prime::getInstance());
}
IntakeState& Lower::getInstance() {
    static Lower singleton;
    return singleton;
}

//lowest state (score alliance stakes)
void Lowest::enter(Intake* intake) {
    intake ->setTarget(1);
}
void Lowest::next(Intake* intake) {
    intake -> setState(Idle::getInstance());
}
void Lowest::prev(Intake* intake) {
    intake -> setState(Lower::getInstance());
}
IntakeState& Lowest::getInstance() {
    static Lowest singleton;
    return singleton;
}
}