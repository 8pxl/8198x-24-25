#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../clamp.hpp"
#include "funcs.hpp"

void posShared() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    chass.driveAngle(-1355, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40)});
    chass.setAng(_angBig);
    chass.driveAngle(-860, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-860, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.driveAngle(550, 30, {.async = true, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(100);
    clamp::tilt();
    robot::intake.move(127);
    chass.waitUntilSettled();
    chass.driveAngle(-300, 0, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    redirect.toggle();
    robot::intake.move(127);
    chass.driveAngle(500, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    chass.driveAngle(200, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
    chass.driveAngle(200, neg(6), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
    // chass.driveAngle(400, 30, {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
    pros::delay(500);
    chass.mtpoint({-17, -2}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 11});
    pros::delay(400);
    lift.switchState();
    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    clamp::clamp();
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=3000, .exit = new Range(4, 30)});
    chass.driveAngle(550, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(300);
    robot::intake.move(127);
    stopOnColor();
    robot::tsukasa.toggle();
    //13, -18
    chass.driveAngle(-710, neg(75), {.async = false, .timeout = 3000, .vMin = 38, .exit = new Range(80, 10)});
    robot::redirect.toggle();
    chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    
    // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    clamp::tilt();
    
    //40,20
    //38, 16
    chass.turnTo({39, 16}, {.timeout=3000, .exit = new Range(2, 20)});
    robot::intake.move(127);
    chass.mtpoint({39, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    lift.toggle();
    pros::delay(200);
}
void posAwp() {
    posShared();
    
    // chass.mtpoint({20, -30}, {.timeout=3000, .exit = new Range(0.8, 20)});
    
    chass.driveAngle(-1380, 20, {.async = false, .timeout = 3000, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-860, neg(45), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
}

void posELims() {
    posShared();
    chass.driveAngle(-1800, 90, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 50)});
}