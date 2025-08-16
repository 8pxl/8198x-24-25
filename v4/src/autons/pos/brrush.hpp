#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void brrushPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    
    intake.move(127);
    chass.driveAngle(1200, 9.0, {.slew = 3});
    intake.move(0);
    tsukasa.toggle();
    chass.mtpoint({6.1, 47.1}, {.drift = 2});
    chass.setTurn(_5);
    chass.turn(20, {});
    rdoink.toggle();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.setAng(_angBig);
    chass.driveAngle(-60, 30, {});
    // chass.turn(48, {});
    chass.setLin(_lin);
    chass.setAng(_ang);
    chass.setTurn(_90);
    ldoink.toggle();
    pros::delay(180);
    // chass.turn(90, {});
    chass.driveAngle(-1000, 55 , {.vMin = 60, .vMax = 70});
    clamp.toggle();
    chass.driveAngle(-300, 90 , {.vMin = 40, .vMax = 60});
    tsukasa.toggle();
    intake.move(127);
    ldoink.toggle();
    rdoink.toggle();
    pros::delay(100);
    chass.driveAngle(600, 70, {});
    chass.turn(180, {.exit = new Range(10, 10)});
    chass.driveAngle(400, neg(170), {.vMin = 80});
    chass.driveAngle(400, neg(120), {.vMin = 80});
    chass.driveAngle(700, neg(81), {.vMin = 80});
    // rdoink.toggle();
    worldsWinningMech.toggle();
    chass.mtpoint({-43, -2}, {.drift = 3,});
    double cornerAng = chass.turnTo({-48, -9}, {});
    intakeCorner(cornerAng, neg(135));
    
    chass.driveAngle(-150, neg(135), {.vMin = 100});
    chass.driveAngle(-300, neg(15), {.timeout = 630, .vMin = 20});
    clamp.toggle();
    
    lb.setState(keejLib::LiftState::two);
    chass.mtpoint({-38, 28}, {});
    worldsWinningMech.toggle();
    
    chass.driveAngle(400, neg(80), {});
    chass.mtpoint({-50, 47}, {.settleRange =7, .exit = new Range(5, 10), });
    intake.move(0);
    lb.setState(keejLib::LiftState::prime);
    chass.setTurn(_5);
    double score = chass.turnTo({-53, 50}, {});
    
    chass.driveAngle(300, score, {});
    lb.setState(keejLib::LiftState::lower);
    
    
    
    // chass.driveAngle(-900, 90, {.vMin = 50});
    
    // chass.driveAngle(1200, 10, {});
}