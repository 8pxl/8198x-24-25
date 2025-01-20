#include "constants.hpp"
#include "../robot.hpp"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../lift/lift.h"
#include "funcs.hpp"

using namespace robot;
void bPos() {
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    // turnToRing(100000);
    // chass.mtpoint({64.0, -1.0}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // return;
    
    doink.toggle();
    //24 < x
    // 26 < x
    // 27 < x?
    chass.moveWithin({16.9, 36.3}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, 27.5);
    chass.setAng(_ang);
    claw.toggle();
    // chass.driveAngle(500, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(5, 20), .slew = 2});
    chass.driveAngle(-1400, 10, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
    chass.driveAngle(-1400, 5, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(600, 30)},true);
    chass.driveAngle(-1400, 5, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(55, 10)}, true);
    claw.toggle();
    // pros::delay(200);
    chass.driveAngle(-460, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 20)});
    chass.turn(90, {.timeout=150, .exit = new Range(3, 20)});
    chass.turn(neg(180), {.timeout=600, .exit = new Range(3, 100)});
    doink.toggle();
    chass.driveAngle(-700, neg(180), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(50, 10)});
    chass.setLin(_linSmall);
    // chass.turn(120, {.timeout = 600, .exit = new Range(5, 10)});
    chass.driveAngle(-500, 141, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(10, 20)});
    chass.driveAngle(-700, 141, {.async = false, .timeout = 370, .vMin = 0, .exit = new Range(10, 20)});
    chass.setLin(_lin);
    clamp.toggle();
    pros::delay(100);
    //1490
    //1400
    Pt fourStack = {10, -3.6};
    // chass.driveAngle(1200, 179, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(30, 20)});
    chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});

    pros::delay(300);
    intake.move(127);
    chass.waitUntilSettled();
    chass.setLin(_linSmall);

    chass.driveAngle(1100, neg(135), {.async = false, .timeout = 630, .vMin = 20, .exit = new Range(5, 20)});
    chass.setLin(_lin);
    chass.driveAngle(-880, neg(135), {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
    pros::delay(550);
    chass.turn(30, {.timeout=490, .exit = new Range(3, 20)});
    clamp.toggle();
    tsukasa.toggle();
    Pt ringStack = {60.4, 5.0};
    chass.turnTo(ringStack, {.timeout=350, .exit = new Range(3, 20)});
    // intake.setSorting(false);
    // CHANGED TODAYS
        chass.mtpoint(ringStack, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    lb.next();
    tsukasa.toggle();
    chass.driveAngle(800, 90, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
    chass.driveAngle(-400, 90, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
    //67.5 < x
    //68 < x
    //68.3 < x
    //68,8 < x
    Pt allianceStake = {69.8, -15.1};
    chass.turnTo(allianceStake, {.timeout=700, .exit = new Range(5, 20)});
    // chass.turn(neg(18    0), {.timeout=900, .exit = new Range(3, 20)});
    intake.move(0);
    lb.next();
    lb.next();
    lb.next();
    tsukasa.toggle();
    //10 < x
    chass.moveWithin(allianceStake, 12.21, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    intake.move(127);
    lb.next();
    pros::delay(600);
    // chass.driveAngle(-400, neg(180), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
    // 49.1 < x
    // 15 tpp small
    Pt goal = {51, 16.4};
    intake.move(0);
    chass.mtpoint(goal, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 9, .exit = new exit::Range(3, 30), .drift = 10});
    pros::delay(400);
    lb.next();
    chass.waitUntilSettled();
    // chass.turn(140, {.timeout=500, .exit = new Range(3, 20)});
    // chass.driveAngle(-900, 140, {.async = true, .timeout = 1000, .vMin = 35, .exit = new Range(5, 20)});
    tsukasa.toggle();
    // intake.setSorting(true);
    // CHANGED TODAY
    chass.setLin(_linSmall);
    chass.driveAngle(-990, 150, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(5, 20)});
    chass.setLin(_lin);
    chass.setAng(_ang);
    clamp.toggle();
    pros::delay(300);
    chass.turn(neg(58), {.timeout=600, .exit = new Range(7, 10)});
    intake.move(127);
    chass.driveAngle(1000, neg(58), {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(30, 10)});
    pros::delay(1000);
    // QUlals
    // chass.driveAngle(-1400, neg(80), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(40, 12)});
    // chass.turn(0, {.timeout=600, .exit = new Range(8, 10)});
    // chass.driveAngle(880, 0, {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
    
    
    //-----
    // intake.setSorting(false);
    // intake.move(20);
    // chass.driveAngle(-880, neg(135), {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
    // 
}