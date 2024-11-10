#include "states.h"
#include "vStates.h"
// #include "common.h"
// #include "lift.h"

namespace lift {

//idle state
void Idle::enter(Lift *lift) {
    lift ->setTarget(10);
}
void Idle::exit(Lift *lift) {
}
void Idle::next(Lift *lift) {
    lift -> setState(One::getInstance());
}
void Idle::prev(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void Idle::toggle(Lift *lift) {
    lift -> setState(Lower::getInstance());
}
void Idle::control(Lift *lift) {
}
Idle::State Idle::getState() {
    return idle;
}
LiftState& Idle::getInstance() {
    static Idle singleton;
    return singleton;
}

//one ring state
void One::enter(Lift *lift) {
    lift ->setTarget(ONE_RING);
    ringSeen = false;
}
void One::exit(Lift *lift) {
}
void One::next(Lift *lift) {
    lift -> setState(Two::getInstance());
}
void One::prev(Lift *lift) {
    lift -> setState(Idle::getInstance());
}
void One::toggle(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void One::control(Lift *lift) {
    if (lift->getColor() != none) {
        ringSeen = true;
        ringTimer.reset();
    }
    if (ringSeen && ringTimer.elapsed() > 400) {
        lift->setState(Two::getInstance());
    }
}
One::State One::getState() {
    return one;
}
LiftState& One::getInstance() {
    static One singleton;
    return singleton;
}

//two ring state
void Two::enter(Lift *lift) {
    lift ->setTarget(TWO_RING);
    ringSeen = false;
}
void Two::exit(Lift *lift) {
}
void Two::next(Lift *lift) {
    lift -> setState(Prime::getInstance());
}
void Two::prev(Lift *lift) {
    lift -> setState(One::getInstance());
}
void Two::toggle(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void Two::control(Lift *lift) {
    if (lift->getColor() != none) {
        ringSeen = true;
        ringTimer.reset();
    }
    if (ringSeen && ringTimer.elapsed() > 400) {
        lift->setState(Prime::getInstance());
    }
}
Two::State Two::getState() {
    return two;
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
void Prime::toggle(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void Prime::control(Lift *lift) {
}
Prime::State Prime::getState() {
    return prime;
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
    lift -> setRebound(false);
}
void Lower::next(Lift *lift) {
    lift -> setState(Lowest::getInstance());
}
void Lower::prev(Lift *lift) {
    lift -> setState(Prime::getInstance());
}
void Lower::toggle(Lift *lift) {
    lift -> setState(One::getInstance());
}
void Lower::control(Lift *lift) {
    if (lift->getReboud()) {
        if (fabs(lift->getDerivative()) < 0.1 && fabs(lift->getError())  < 30) {
            lift->setState(One::getInstance());
        }
    }
}
Lower::State Lower::getState() {
    return lower;
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
    lift -> setRebound(false);
}
void Lowest::next(Lift *lift) {
    lift -> setState(Idle::getInstance());
}
void Lowest::prev(Lift *lift) {
    lift -> setState(Lower::getInstance());
}
void Lowest::toggle(Lift *lift) {
    lift -> setState(One::getInstance());
}
void Lowest::control(Lift *lift) {
    if (lift->getReboud()) {
        if (fabs(lift->getDerivative()) < 0.1 && fabs(lift->getError())  < 30) {
            lift->setState(One::getInstance());
        }
    }
}
Lowest::State Lowest::getState() {
    return lowest;
}
LiftState& Lowest::getInstance() {
    static Lowest singleton;
    return singleton;
}
}