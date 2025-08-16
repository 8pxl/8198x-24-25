#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void rrrushPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    
    intake.move(127);
    chass.driveAngle(1200, neg(6.0), {.slew = 5});
    intake.move(0);
    tsukasa.toggle();
    chass.mtpoint({-6.1, 47.1}, {.drift = 2});
    chass.setTurn(_5);
    chass.turn(neg(20), {});
    ldoink.toggle();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.setAng(_angBig);
    chass.driveAngle(-60, neg(39), {});
    // chass.turn(48, {});
    chass.setLin(_lin);
    chass.setAng(_ang);
    chass.setTurn(_90);
    rdoink.toggle();
    pros::delay(180);
    // chass.turn(90, {});
    chass.driveAngle(-1000, neg(55) , {.vMin = 70, .vMax = 80});
    clamp.toggle();
    chass.driveAngle(-300, neg(90) , {.vMin = 70, .vMax = 80});
    tsukasa.toggle();
    intake.move(127);
    ldoink.toggle();
    rdoink.toggle();
    chass.driveAngle(600, neg(60), {.vMin =20});
    chass.driveAngle(400, neg(150), {.vMin = 80});
    chass.turn(180, {.exit = new Range(10, 10)});
    chass.driveAngle(400, 170, {.vMin = 80});
    chass.driveAngle(400, 120, {.vMin = 80});
    chass.driveAngle(700, 81, {.vMin = 80});
    // rdoink.toggle();
    worldsWinningMech.toggle();
    chass.mtpoint({43, -2}, {.drift = 3,});
    double cornerAng = chass.turnTo({48, -9}, {.timeout = 500});
    chass.driveAngle(400, cornerAng, {.timeout = 400});
    intakeCorner(cornerAng, 135);
    
    rdoink.toggle();
    chass.driveAngle(-200, 163, {.vMin = 100});
    chass.driveAngle(200, 135, {.timeout = 630, .vMin = 20});
    // chass.driveAngle(300, 90, {.timeout = 630, .vMin = 20});
    chass.turn(85, {.timeout = 500});
    rdoink.toggle();
    // clamp.toggle();
    
    chass.mtpoint({38, 28}, {});
    chass.driveAngle(-900 , neg(0), {.vMin = 80});
    clamp.toggle();
    chass.driveAngle(-400 , neg(30), {.vMin = 80});
    
    // chass.driveAngle(400, 80, {});
    lb.setState(keejLib::LiftState::lower);
    chass.mtpoint({47, 47}, {.settleRange =7, .exit = new Range(5, 10), });
    intake.move(0);
    // chass.setTurn(_5);
    // double score = chass.turnTo({-53, 50}, {});
    
    // chass.mtpoint({-53, 50}, { .vMin = 80, .settleRange = 7,});;
    
    
    
    // chass.driveAngle(-900, 90, {.vMin = 50});
    
    // chass.driveAngle(1200, 10, {});
}