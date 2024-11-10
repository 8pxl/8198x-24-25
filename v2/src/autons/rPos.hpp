#include "constants.hpp"
#include "../robot.hpp"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;
    void rPos() {
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    // chass.mtpoint({-64, -1}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // return;
    
    doink.toggle();
    chass.moveWithin({-11,36}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, neg(9));
    chass.setAng(_ang);
    claw.toggle();
    // chass.driveAngle(500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(5, 20), .slew = 2});
    chass.driveAngle(-1400, neg(10), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
    chass.driveAngle(-1400, 20, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(600, 30)},true);
    chass.driveAngle(-1400, 20, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(5, 30)}, true);
    claw.toggle();
    chass.driveAngle(-460, 0, {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(25, 20)});
    doink.toggle();
    chass.turn(90, {.timeout=150, .exit = new Range(3, 20)});
    chass.turn(135, {.timeout=50, .exit = new Range(3, 20)});
    chass.turn(180, {.timeout=700, .exit = new Range(3, 20)});
    chass.driveAngle(-1300, neg(178), {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
    clamp.toggle();
    chass.driveAngle(1520, 176, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(300);
    intake.move(127);
    chass.driveAngle(1300, 135, {.async = false, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    chass.driveAngle(-900, 135, {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
    chass.turn(neg(30), {.timeout=900, .exit = new Range(3, 20)});
    clamp.toggle();
    tsukasa.toggle();
    // Pt ringStack = {-64, -1};
    chass.turn(neg(90), {.timeout=600, .exit = new Range(3, 20)});
    chass.driveAngle(1830, neg(90), {.async = false, .timeout = 1200, .vMin = 20, .exit = new Range(5, 20)});
        // chass.mtpoint({-64, -1}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    lb.next();
    lb.next();
    tsukasa.toggle();
    chass.driveAngle(800, neg(90), {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    chass.driveAngle(-400, neg(90), {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    Pt allianceStake = {-72, -15};
    chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(3, 20)});
    // chass.turn(180, {.timeout=900, .exit = new Range(3, 20)});
    intake.move(0);
    lb.next();
    chass.moveWithin(allianceStake, 5, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10)});
    lb.next();lb.next();
    pros::delay(700);
    chass.driveAngle(-400, 180, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    lb.next();
    chass.turn(neg(150), {.timeout=900, .exit = new Range(3, 20)});
    chass.driveAngle(-800, neg(150), {.async = true, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    chass.waitUntilSettled();
    chass.driveAngle(-980, neg(150), {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    chass.setAng(_ang);
    clamp.toggle();
    intake.move(127);
    chass.turn(90, {.timeout=900, .exit = new Range(3, 20)});
    chass.driveAngle(1000, 90, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(5, 20)});
    
}