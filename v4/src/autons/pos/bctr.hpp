#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void bctrPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //grab mogo and score alliance stake;
    // lb.next();
    lb.setState(LiftState::alliance);
    
    //score alliance ring
    
    // chass.moveWithin(allianceStake, 14.7, {});
    // chass.driveAngle(180, neg(43), {.timeout = 700});
    chass.driveLin(700, 26, {});
    chass.driveAngle(-200, neg(43), { .timeout = 400, .vMin = 100,});
    lb.setState(LiftState::idle);
    
    chass.mtpoint({7.3, -19.6}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 8, .turnBias = 0.8
    });
    // pros::delay(100000);
    // chass.mtpose({{8.0, -19.6}, h(0)}, 0.5, {.timeout = 1100, .vMin = 60,.settleRange = 5, .exit = new Range(3, 10), .drift = 6,});
    // chass.driveAngle(-400, neg(0), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50,.exit = new Range(130, 10)});
    chass.driveAngle(-600, neg(0), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    clamp.toggle();
    pros::delay(100);
    // chass.turn(neg(60), {.exit = new Range(20, 10)});
    chass.driveAngle(320, neg(80), {.vMin = 70, .exit = new Range(100, 10)});
    // tsukasa.toggle();
    chass.mtpoint({-11.03, -45.2}, {});
    chass.setTurn(_5);
    // chass.setLin(_linBigger);
    chass.driveAngle(150, neg(156), {.timeout = 500,.exit = new Range(40, 10)});
    rdoink.toggle();
    pros::delay(200);
    chass.driveAngle(-160, neg(144), {.timeout = 500,.exit = new Range(50, 10)});
    ldoink.toggle();
    pros::delay(200);
    chass.setLin(_lin);
    
    // chass.mtpoint({14.0, -4.0}, {.turnBias = 1});
    chass.driveAngle(-1140, neg(167), {.vMin = 80, .exit = new Range(190, 10)});
    ldoink.toggle();
    chass.driveAngle(-560, 170, {.vMin = 80, .exit = new Range(50, 10)});
    // chass.turn(neg(180), {});
    rdoink.toggle();
    // tsukasa.toggle();
    intake.move(127);
    chass.driveAngle(700, neg(168), {.vMin = 60, .exit = new Range(150, 10)});
    chass.driveAngle(600, 140, { .exit = new Range(150, 10)});
    chass.mtpoint({30.0, -35.0}, {.vMin = 90, .exit = new Range(4, 10)});
    
    chass.driveAngle(-300, 90, {.vMin = 80, .exit = new Range(90, 10)});
    chass.driveAngle(-250, 45, {.vMin = 30, .exit = new Range(90, 10)});

    //go to corner
    Pt corner1 = {47.04, 2.9};
    worldsWinningMech.toggle();
    chass.mtpoint(corner1, {.timeout = 1500, .exit = new Range(1, 10), .drift = 7});
    intake.move(127);
    chass.setTurn(_5);
    double ang = chass.turnTo({54.8, 11.0}, {.timeout = 600});
    chass.setTurn(_90);
    intakeCorner(ang, 45);
    pros::delay(200);
    // chass.driveAngle(-300, 45, {.timeout =300, .vMin = 100});
    // // rdoink.toggle();
    // chass.driveAngle(200, neg(135), {.timeout =200, .vMin = 100, .exit = new Range(150, 10),});
    // intake.move(0);
    // clamp.toggle();
    // worldsWinningMech.toggle();
    // chass.driveAngle(1200, neg(128), {.async = false, .timeout = 800, .vMin = 50,});
    chass.mtpoint({-4.0, -39.0}, {.async = true, .exit = new Range(5, 10)});
    pros::delay(500);
    intake.move(0);
    chass.waitUntilSettled();
    chass.driveAngle(-500, 45, {});
    // worldsWinningMech.toggle();
}