#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void rctrPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //grab mogo and score alliance stake;
    // lb.next();
    pros::delay(500);
    lb.setState(LiftState::alliance);
    
    //score alliance ring
    
    // chass.moveWithin(allianceStake, 14.7, {});
    // chass.driveAngle(180, 43, {.timeout = 700});
    chass.driveLin(700, 27, {});
    chass.driveAngle(-200, 43, { .timeout = 400, .vMin = 100,});
    lb.setState(LiftState::idle);
    
    chass.mtpoint({-7.1, -19.6}, {.timeout = 1100, .vMin = 50, .exit = new Range(3, 10), .drift = 8, .turnBias = 0.74});
    // chass.mtpoint({-7.3, -19.6}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 8, .turnBias = 0.8});

    // pros::delay(100000);
    // chass.mtpose({{-8, -19.6}, h(0)}, 0.5, {.timeout = 1100, .vMin = 60,.settleRange = 5, .exit = new Range(3, 10), .drift = 6,});
    // chass.driveAngle(-400, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50,.exit = new Range(130, 10)});
    chass.driveAngle(-650, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    clamp.toggle();
    pros::delay(100);
    // chass.turn(60, {.exit = new Range(20, 10)});
    chass.driveAngle(320, 80, {.vMin = 70, .exit = new Range(100, 10)});
    // tsukasa.toggle();
// chass.mtpoint({13.1, -45.2}, {});
    chass.mtpoint({12.7, -45.3}, {});
    chass.setTurn(_5);
    // chass.setLin(_linBigger);
    chass.driveAngle(150, 161, {.timeout = 500,.exit = new Range(40, 10)});
    // chass.driveAngle(150, 156, {.timeout = 500,.exit = new Range(40, 10)});
    ldoink.toggle();
    pros::delay(200);
    chass.driveAngle(-160, 144, {.timeout = 500,.exit = new Range(50, 10)});
    rdoink.toggle();
    pros::delay(200);
    chass.setLin(_lin);
    
    // chass.mtpoint({-14, -4}, {.turnBias = 1});
    chass.driveAngle(-1140, 167, {.vMin = 80, .exit = new Range(190, 10)});
    rdoink.toggle();
    chass.driveAngle(-560, neg(170), {.vMin = 80, .exit = new Range(50, 10)});
    // chass.turn(180, {});
    ldoink.toggle();
    // tsukasa.toggle();
    intake.move(127);
    chass.driveAngle(700, 168, {.vMin = 60, .exit = new Range(150, 10)});
    chass.driveAngle(600, neg(140), { .exit = new Range(150, 10)});
    chass.mtpoint({-30, -35}, {.vMin = 90, .exit = new Range(4, 10)});
    
    chass.driveAngle(-300, neg(90), {.vMin = 80, .exit = new Range(90, 10)});
    chass.driveAngle(-250, neg(45), {.vMin = 30, .exit = new Range(90, 10)});

    //go to corner
    Pt corner1 = {-47.9, 2.9};
    worldsWinningMech.toggle();
    chass.mtpoint(corner1, {.timeout = 1500, .exit = new Range(1, 10), .drift = 7, .within = 3});
    intake.move(127);
    chass.setTurn(_5);
    double ang = chass.turnTo({-54.8, 11.0}, {.timeout = 600});
    chass.setTurn(_90);
    intakeCorner(ang, neg(45));
    pros::delay(200);
    // chass.driveAngle(-300, neg(45), {.timeout =300, .vMin = 100});
    // // rdoink.toggle();
    // chass.driveAngle(200, 135, {.timeout =200, .vMin = 100, .exit = new Range(150, 10),});
    // intake.move(0);
    // clamp.toggle();
    // worldsWinningMech.toggle();
    // chass.driveAngle(1200, 128, {.async = false, .timeout = 800, .vMin = 50,});
    chass.mtpoint({3, -37}, {.async = true, .exit = new Range(5, 10)});
    pros::delay(500);
    intake.move(0);
    chass.waitUntilSettled();
    chass.driveAngle(-580, neg(45), {});
    // worldsWinningMech.toggle();
}