#include "constants.hpp"
#include "../robot.hpp"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;
void rPos() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    // chass.mtpoint({-64, -1}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // return;
    
    doink.toggle();
    chass.moveWithin({-9.9,38.4}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, neg(9.3));
    chass.setAng(_ang);
    claw.toggle();
    // chass.driveAngle(500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(5, 20), .slew = 2});
    chass.driveAngle(-1400, neg(10), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
    chass.driveAngle(-1400, 20, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(600, 30)},true);
    chass.driveAngle(-1400, 33, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 10)}, true);
    claw.toggle();
    chass.driveAngle(-460, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 20)});
    doink.toggle();
    chass.turn(90, {.timeout=150, .exit = new Range(3, 20)});
    chass.turn(135, {.timeout=50, .exit = new Range(3, 20)});
    chass.turn(190, {.timeout=400, .exit = new Range(3, 20)});
    chass.driveAngle(-900, 200, {.async = false, .timeout = 800, .vMin = 28, .exit = new Range(30, 10)});
    chass.setLin(_linSmall);
    chass.driveAngle(-400, neg(180), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(5, 20)});
    chass.setLin(_lin);
    clamp.toggle();
    //1490
    //1400
    Pt fourStack = {-10, -3.9};
    chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});
    // chass.driveAngle(1380, 187, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(300);
    intake.move(127);
    chass.driveAngle(1300, 135, {.async = false, .timeout = 610, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(400);
    chass.driveAngle(-880, 135, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
    pros::delay(300);
    chass.turn(neg(30), {.timeout=490, .exit = new Range(3, 20)});
    clamp.toggle();
    tsukasa.toggle();
    Pt ringStack = {-62, 3.9};
    chass.turnTo(ringStack, {.timeout=350, .exit = new Range(3, 20)});
    // chass.driveAngle(1830, imu.get_heading(), {.async = false, .timeout = 1200, .vMin = 0, .exit = new Range(5, 20)});
    intake.setSorting(false);
        chass.mtpoint(ringStack, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    lb.next();
    lb.next();
    tsukasa.toggle();
    chass.setLin(_linSmall);
    chass.driveAngle(640, neg(90), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(10, 10)});
    chass.setLin(_lin);
    chass.driveAngle(-400, neg(90), {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
    Pt allianceStake = {-67.4, -15};
    chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(5, 20)});
    // chass.turn(180, {.timeout=900, .exit = new Range(3, 20)});
    intake.move(0);
    lb.next();
    tsukasa.toggle();
    chass.moveWithin(allianceStake, 11.6, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    intake.move(127);
    lb.next();
    lb.next();
    pros::delay(600);
    // chass.driveAngle(-400, 180, {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
    Pt goal = {-53.7, 17};
    intake.move(0);
    chass.mtpoint(goal, {.async = false, .timeout = 1000, .vMin = 30, .settleRange = 9, .exit = new exit::Range(3, 30), .drift = 20});
    lb.next();
    // chass.turn(neg(140), {.timeout=500, .exit = new Range(3, 20)});
    // chass.driveAngle(-900, neg(140), {.async = true, .timeout = 1000, .vMin = 35, .exit = new Range(5, 20)});
    tsukasa.toggle();
    intake.setSorting(true);
    chass.setLin(_linSmall);
    chass.driveAngle(-1000, neg(150), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(5, 20)});
    chass.setLin(_lin);
    chass.setAng(_ang);
    clamp.toggle();
    chass.turnTo({-24, 27.9}, {.timeout=600, .exit = new Range(5, 10)});
    intake.move(127);
    chass.mtpoint({-24, 27.9}, {.async = false, .timeout = 800, .vMin = 0, .settleRange = 5, .exit = new exit::Range(3, 300)});
    // pros::delay(600);
    chass.driveAngle(-400, 90, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
    Pt corner = {-44, 45 };
    chass.turnTo(corner, {.timeout=600, .exit = new Range(5, 10)});
    chass.driveAngle(700, imu.get_heading(), {.async = false, .timeout = 1500, .vMin = 0, .exit = new Range(5, 20)});
    
    //OLD
    /* 
    chass.mtpoint({-52, 40}, {.async = true, .timeout = 1700, .vMin = 0, .settleRange = 10, .exit = new exit::Range(5, 50)});
    pros::delay(300);
    intake.move(30);
    chass.waitUntilSettled();
    */
}