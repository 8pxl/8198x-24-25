#include "constants.hpp"

using namespace robot;

void skills() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    
    lb.next();
    lb.next();
    chass.setLin(_linBigger);
    chass.driveAngle(-300, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(40, 20)});
    chass.setLin(_lin);
    clamp.toggle();
    
    Pt allianceStake = {-25.5, 6.5};
    chass.turnTo(allianceStake, {.timeout = 600, .exit = new Range(2, 30)});
    chass.moveWithin(allianceStake, 10.9, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(250);
    chass.driveAngle(-500, neg(45), {.async = true, .timeout = 600, .exit = new Range(20, 20)});
    pros::delay(200);
    lb.next();
    chass.waitUntilSettled();
    intake.move(127);
    
    Pt ring1 = {2, -30};
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(2, 100)});
    // chass.turnTo(ring1, {.timeout = 700, .exit = new Range(1, 30)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 40, .settleRange = 2, .exit = new Range(5, 10)});
    
    Pt ring2 = {33.94, -60.58};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 10, .settleRange = 10, .exit = new Range(5, 10)});
    
    
    Pt ring3 = {22.04, -10.83};
    chass.turnTo(ring3, {.timeout = 300, .exit = new Range(2, 30)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring4 = {22.04, 3.83};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring5 = {37,-14};
    chass.turnTo(ring5, {.timeout = 400, .exit = new Range(2, 30)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    chass.driveAngle(-600, neg(170), { .timeout = 600, .exit = new Range(20, 20)});
    clamp.toggle();
    
    Pt ring6 = {22, -87};
    chass.mtpoint(ring6, {.timeout = 1600, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
}