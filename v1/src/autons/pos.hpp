#include "constants.hpp"

void posShared() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    //1355
    //1350

    // chass.driveAngle(-1330, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
    chass.moveWithin({0, -50}, 16, {.timeout = 3000, .vMin = 38, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-800, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(60, 10)});
    clamp::clamp();
    chass.driveAngle(-800, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
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
    chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    chass.driveAngle(170, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=3000, .exit = new Range(4, 30)});
    chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-200, neg(61), {.async = true, .timeout = 3000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    robot::redirect.toggle();
    // chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
        chass.mtpoint({-2, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
    // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    clamp::tilt();
    
    //40,20
    //38, 16
    //35, 16
    
    //12, 14
    
    //36
    chass.turnTo({35.5, 13}, {.timeout=1000, .exit = new Range(2, 20)});
    robot::intake.move(127);
    // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    chass.moveWithin({35.5,13}, 13.8, {.timeout=2100, .exit = new Range(5, 100)});
    lift.toggle();
    pros::delay(390);
}
void posAwp() {
    posShared();
    
    // chass.mtpoint({20, -30}, {.timeout=3000, .exit = new Range(0.8, 20)});
    
    chass.driveAngle(-1580, 20, {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-890, neg(45), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
}

void posELims() {
    posShared();
    chass.driveAngle(-1800, 90, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 50)});
}