#pragma once

#include "states.h"
// #include "common.h"
// #include "lift.h"

namespace lift {

//idle state
void Idle::enter(Lift *lift) {
    lift ->setTarget(0);
}
void Idle::exit(Lift *lift) {
}
void Idle::next(Lift *lift) {
    lift -> setState(One::getInstance());
}
void Idle::prev(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
LiftState& Idle::getInstance() {
    static Idle singleton;
    return singleton;
}

//one ring state
void One::enter(Lift *lift) {
    lift ->setTarget(ONE_RING);
}
void One::exit(Lift *lift) {
}
void One::next(Lift *lift) {
    lift -> setState(Two::getInstance());
}
void One::prev(Lift *lift) {
    lift -> setState(Idle::getInstance());
}
LiftState& One::getInstance() {
    static One singleton;
    return singleton;
}

//two ring state
void Two::enter(Lift *lift) {
    lift ->setTarget(TWO_RING);
}
void Two::exit(Lift *lift) {
}
void Two::next(Lift *lift) {
    lift -> setState(Prime::getInstance());
}
void Two::prev(Lift *lift) {
    lift -> setState(One::getInstance());
}
LiftState& Two::getInstance() {
    static Two singleton;
    return singleton;
}

//prime state
void Prime::enter(Lift *lift) {
    lift ->setTarget(PRIME);
}
void Prime::exit(Lift *lift) {
}
void Prime::next(Lift *lift) {
    lift -> setState(Lower::getInstance());
}
void Prime::prev(Lift *lift) {
    lift -> setState(Two::getInstance());
}
LiftState& Prime::getInstance() {
    static Prime singleton;
    return singleton;
}

//lower state (score normal stakes)
void Lower::enter(Lift *lift) {
    lift ->setTarget(LOWER);
}
void Lower::exit(Lift *lift) {
}
void Lower::next(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void Lower::prev(Lift *lift) {
    lift -> setState(Prime::getInstance());
}
LiftState& Lower::getInstance() {
    static Lower singleton;
    return singleton;
}

//lowest state (score alliance stakes)
void Lowest::enter(Lift *lift) {
    lift ->setTarget(LOWEST);
}
void Lowest::exit(Lift *lift) {
}
void Lowest::next(Lift *lift) {
    lift -> setState(Idle::getInstance());
}
void Lowest::prev(Lift *lift) {
    lift -> setState(Lower::getInstance());
}
LiftState& Lowest::getInstance() {
    static Lowest singleton;
    return singleton;
}
}