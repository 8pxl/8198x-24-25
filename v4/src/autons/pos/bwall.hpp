#include "../constants.hpp"
#include "../../robot.hpp"
#include "keejLib/util.h"
#include "liblvgl/lvgl.h"
#include "pros/rtos.hpp"
#include "../../lift/lift.h"
#include "../funcs.hpp"


using namespace robot;

void wbPos() {
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});
    worldsWinningMech.toggle();
    // chass.moveWithin({17.14, 36.9}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, 28.5);
    chass.mtpoint({17.14, 36.9}, {.timeout = 1500, .vMin = 110, .exit = new Range(5, 10), .reverse = false});
    chass.setAng(_ang);
    worldsWinningMech.toggle();
    auto grab = chass.getPose();
    chass.driveAngle(-400, 28, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
    chass.holdPos(10, -4, 3000, {.exit = new Range(1, 100)});
    chass.driveAngle(400, 10, {});
    worldsWinningMech.toggle();
    lb.setState(LiftState::prime);
    
    // pros::delay(200);
    chass.driveAngle(700, 50, {.async = true, .timeout = 800, .vMin = 70, .exit = new Range(80, 20)});
    pros::delay(200);
    intake.move(127);
    intake.stopOnColor(keejLib::blue, 0);
    chass.waitUntilSettled();
    
    chass.driveAngle(600, 90, {.async = false, .timeout = 800, .vMin = 20, .exit = new Range(80, 20)});
    chass.driveAngle(-1000, 0, {.async = false, .timeout = 800, .vMin = 40, .exit = new Range(80, 20)});
    clamp.toggle();
    pros::delay(100);
    intake.move(127);
    
    Pt stake = {-4, 55.1};
    Pt scoringPosition = {1.8, 46.5};
    chass.mtpoint(scoringPosition, {.async = true, .exit = new Range(4, 10),.drift = 3});
    pros::delay(200);
    chass.waitUntilSettled();
    chass.setTurn(_5);
    double ang = chass.turnTo(stake, {.timeout = 600});
    chass.setTurn(_90);
    lb.next();
    chass.driveAngle(200, ang+10, {.timeout = 300});
    chass.driveAngle(-200, ang-10, {.timeout = 300});

    Pt g2Prime = {35, 18.92};
    chass.turnTo(g2Prime,  {.exit = new Range(10, 10),.reverse = true});
    chass.mtpoint(g2Prime, {.drift = 5});
    lb.setState(keejLib::LiftState::idle);
    chass.driveAngle(-1400, neg(140), {.async = false, .timeout = 1300,.vMin = 40, .vMax = 60, .slew = 5});
    clamp.toggle();
    
 Pt fourStack = {9.5, -2.1};
    chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});
    // chass.driveAngle(1380, 187, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(300);
    intake.move(127);
    chass.setLin(_linSmall);

    Pt corner = {0.4,-15};

    ang = chass.turnTo(corner, {.timeout = 400});
    intakeCorner(ang, neg(135));
}