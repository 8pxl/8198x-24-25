#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void bctrwallPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //grab mogo and score alliance stake;
    // lb.next();
    // lb.setState(LiftState::alliance);
    
    //score alliance ring
    
    // chass.moveWithin(allianceStake, 14.7, {});
    // chass.driveAngle(180, neg(43), {.timeout = 700});
    // chass.driveLin(700, 26, {});
    // chass.driveAngle(-200, neg(43), { .timeout = 400, .vMin = 100,});
    // lb.setState(LiftState::idle);
    
    chass.mtpoint({7.3, -19.6}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 8, .turnBias = 0.8
    });
    // pros::delay(100000);
    // chass.mtpose({{8.0, -19.6}, h(0)}, 0.5, {.timeout = 1100, .vMin = 60,.settleRange = 5, .exit = new Range(3, 10), .drift = 6,});
    // chass.driveAngle(-400, neg(0), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50,.exit = new Range(130, 10)});
    chass.driveAngle(-600, neg(0), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
    clamp.toggle();
    pros::delay(60);
    // chass.turn(neg(60), {.exit = new Range(20, 10)});
    tsukasa.toggle();
    // chass.driveAngle(320, neg(80.8), {.async = true, .vMin = 70, .exit = new Range(100, 10)});
    chass.driveAngle(200, neg(10), {.timeout =250});
    intake.move(127);
    // chass.turn(neg(80.0), {.async = true, .timeout = 400,.vMax = 70});
    chass.driveAngle(330, neg(80), {.async = true, .timeout = 400});
    // tsukasa.toggle();
    chass.waitUntilSettled();
    intake.move(0);
    chass.mtpoint({-11.9, -46.3}, {.settleRange = 6, .exit = new Range(3, 10),.drift = 4});
    chass.setTurn(_5);
    // chass.setLin(_linBigger);
    chass.driveAngle(150, neg(165), {.timeout = 470,.exit = new Range(40, 10)});
    rdoink.toggle();
    pros::delay(200);
    chass.driveAngle(-160, neg(143), {.timeout = 400,.exit = new Range(50, 10)});
    ldoink.toggle();
    pros::delay(200);
    chass.setLin(_lin);
    
    // chass.mtpoint({14.0, -4.0}, {.turnBias = 1});
    chass.driveAngle(-1140, neg(168), {.vMin = 80, .exit = new Range(190, 10)});
    ldoink.toggle();
    chass.driveAngle(-560, 170, {.vMin = 80, .exit = new Range(50, 10)});
    // chass.turn(neg(180), {});
    rdoink.toggle();
    tsukasa.toggle();
    intake.move(127);
    chass.driveAngle(700, neg(168), {.vMin = 60, .exit = new Range(150, 10)});
    chass.driveAngle(600, 140, { .exit = new Range(150, 10)});
    chass.mtpoint({30.0, -35.0}, {.vMin = 90, .exit = new Range(4, 10)});
    
    chass.driveAngle(-390, 90, {.vMin = 80, .exit = new Range(90, 10)});
    chass.driveAngle(-250, 45, {.vMin = 50, .exit = new Range(30, 10)});

    //go to corner
    Pt corner1 = {46.8, 3.3};
    worldsWinningMech.toggle();
    chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(7, 10), .drift = 8});
    intake.move(127);
    chass.setTurn(_5);
    double ang = chass.turnTo({55.9, 11.0}, {.timeout = 600});
    chass.setTurn(_90);
    //--- intake corner
    intake.move(127);
    chass.driveAngle(1190, ang, {.timeout = 700,.vMin = 55, .vMax = 60, .slew = 3});
    intake.setJamProtection(false);
    chass.driveAngle(-155, ang, {.timeout = 480, .vMax = 35});
    intake.stopOnColor(blue, 0);
    intake.setJamProtection(true);
    tsukasa.toggle();
    intake.move(127);
    pros::delay(300);
    lb.setState(keejLib::LiftState::two);
    chass.driveAngle(890, 45, {.timeout = 680, .vMax = 60, .slew = 2.4});
    intake.setJamProtection(false);
    tsukasa.toggle();
    // ---
    chass.driveAngle(-530, 45, {.timeout =450,});
    // pros::delay(300);
    // // rdoink.toggle();
    // chass.driveAngle(200, neg(135), {.timeout =200, .vMin = 100, .exit = new Range(150, 10),});
    // intake.move(0);
    // clamp.toggle();
    // worldsWinningMech.toggle();
    // chass.driveAngle(1200, neg(128), {.async = false, .timeout = 800, .vMin = 50,});
    chass.turn(168, {.timeout = 640});
    intake.move(0);
    worldsWinningMech.toggle();
    clamp.toggle();
    // chass.mtpoint({46.9, -47.5}, {.async = true, .exit = new Range(5, 10)});
    chass.driveAngle(1200, 168, {.async = true, .exit = new Range(40, 10)});
    pros::delay(300);
    lb.setState(keejLib::LiftState::prime);
    pros::delay(300);
    intake.move(127);
    // intake.stopOnColor(keejLib::blue, 0);
    chass.waitUntilSettled();
    chass.driveAngle(300, 156, {.timeout =300});
    
    Pt wallStake = {55.0, -60.96};
    double wallAng = chass.turnTo(wallStake, {.timeout = 600});
    // chass.driveAngle(260, wallAng, {.timeout = 340});
    lb.setState(keejLib::LiftState::lower);
}