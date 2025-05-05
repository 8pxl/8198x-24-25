#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void rringsPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //grab mogo and score alliance stake;
    // lb.next();
    lb.setState(LiftState::alliance);
    chass.driveLin(700, 27, {});
    chass.driveAngle(-200, 43, { .timeout = 400, .vMin = 100,});
    lb.setState(LiftState::idle);

    chass.mtpoint({-0.5, -17.1}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.8
    });
    // pros::delay(100000);
    // chass.mtpose({{-8, -19.6}, h(0)}, 0.5, {.timeout = 1100, .vMin = 60,.settleRange = 5, .exit = new Range(3, 10), .drift = 6,});
    // chass.driveAngle(-400, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50,.exit = new Range(130, 10)});
    // chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    chass.driveAngle(-500, 25, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    chass.driveAngle(-400, 30, {.async = false, .timeout = 1000, .vMin = 50, .vMax = 60, .exit = new Range(100, 10)});
    // chass.driveAngle(-400, neg(50), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    clamp.toggle();
    pros::delay(150);
    // chass.driveAngle(200, neg(35), {.timeout = 300});
    // chass.turn(124, {.timeout = 700});
    // chass.driveAngle(740, 90, { .vMin = 80, .exit = new Range(60, 10),});
    // tsukasa.toggle();
    // chass.driveAngle(-400, 89, {.vMin = 80, .exit = new Range(60, 10),});
    Pt centerSetup = {14.9, -43.8};
    chass.turnTo(centerSetup, {.exit = new Range(5, 10)});
    // chass.driveAngle(-150, neg(202), {.timeout = 500});
    chass.turn(neg(200), {.timeout = 500});
    chass.mtpoint(centerSetup, {});
    // 
    ldoink.toggle();
    pros::delay(300);
    chass.setTurn(_5);
    chass.driveAngle(-150, neg(223), {.timeout = 500, .vMin = 8});
    // chass.turn(neg(223), {});
    chass.setTurn(_90);
    rdoink.toggle();
    pros::delay(300);
    
    
    // chass.mtpoint({-14, -4}, {.turnBias = 1});
    chass.driveAngle(-1140, 167, {.vMin = 80, .exit = new Range(190, 10)});
    rdoink.toggle();
    chass.driveAngle(-360, neg(177), {.vMin = 80, .exit = new Range(50, 10)});
    // chass.turn(180, {});
    chass.driveAngle(100, neg(177), {.vMin = 80, .exit = new Range(50, 10)});
    ldoink.toggle();
    tsukasa.toggle();
    dt.spinAll(0);
    intake.move(127);
    pros::delay(250);
    chass.driveAngle(700, 168, {.vMin = 80, .exit = new Range(150, 10)});
    chass.driveAngle(600, neg(140), { .exit = new Range(150, 10)});
    chass.mtpoint({-30, -35}, {.vMin = 90, .exit = new Range(4, 10)});
    
    chass.driveAngle(-300, neg(90), {.vMin = 80, .exit = new Range(90, 10)});
    chass.driveAngle(-250, neg(45), {.vMin = 30, .exit = new Range(90, 10)});

    //go to corner
    Pt corner1 = {-46.8, 2.9};
    worldsWinningMech.toggle();
    chass.mtpoint(corner1, {.timeout = 1500, .exit = new Range(1, 10), .drift = 7});
    intake.move(127);
    chass.setTurn(_5);
    double ang = chass.turnTo({-54.8, 11.0}, {.timeout = 600});
    chass.setTurn(_90);
    intakeCorner(ang, neg(45));
    pros::delay(500);
    // chass.driveAngle(-500, neg(45), {});
    // rdoink.toggle();
    chass.driveAngle(-300, 135, {.exit = new Range(60, 10)});
    worldsWinningMech.toggle();
    intake.move(0);
    clamp.toggle();
    chass.driveAngle(2000, 128, {.async = false});
    // chass.mtpoint({6, -28}, {});
    chass.waitUntilSettled();
    worldsWinningMech.toggle();
}