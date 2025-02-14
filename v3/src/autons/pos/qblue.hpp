#include "../constants.hpp"
#include "../../robot.hpp"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../../lift/lift.h"
#include "../funcs.hpp"


using namespace robot;

// void qbPos() {
//     chass.setTurn(_90);
//     chass.setAng(_angBig);
//     chass.setLin(_lin);
//     chass.setMTP(_chassLin, _chassAng);
//         Pose p = chass.getPose();
//         chass.setPose({-p.pos.x, p.pos.y, p.heading});
    
//     // turnToRing(100000);
//     // chass.mtpoint({64.0, -1.0}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
//     // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
//     // return;
    
//     doink.toggle();
//     //24 < x
//     // 26 < x
//     // 27 < x?
//     chass.moveWithin({16.9, 36.3}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, 27.5);
//     chass.setAng(_ang);
//     claw.toggle();
//     // chass.driveAngle(500, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(5, 20), .slew = 2});
//     chass.driveAngle(-1400, 10, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
//     chass.driveAngle(-1400, 5, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(600, 30)},true);
//     chass.driveAngle(-1400, 5, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(55, 10)}, true);
//     claw.toggle();
//     // pros::delay(200);
//     chass.driveAngle(-460, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 20)});
//     chass.turn(90, {.timeout=150, .exit = new Range(3, 20)});
//     chass.turn(neg(180), {.timeout=600, .exit = new Range(3, 100)});
//     doink.toggle();
//     chass.driveAngle(-700, neg(180), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(50, 10)});
//     chass.setLin(_linSmall);
//     // chass.turn(120, {.timeout = 600, .exit = new Range(5, 10)});
//     chass.driveAngle(-700, 151, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(10, 20)});
//     // chass.driveAngle(-4, 151, {.async = false, .timeout = 370, .vMin = 0, .exit = new Range(10, 20)});
//     chass.setLin(_lin);
//     clamp.toggle();
//     pros::delay(100);
//     //1490
//     //1400
//     Pt fourStack = {10, -3.6};
//     // chass.driveAngle(1200, 179, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(30, 20)});
//     intake.setJamProtection(false);
//     chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});

//     pros::delay(300);
//     intake.move(127);
//     chass.waitUntilSettled();
//     chass.setLin(_linSmall);

//     chass.driveAngle(1100, neg(135), {.async = false, .timeout = 630, .vMin = 20, .exit = new Range(5, 20)});
//     chass.setLin(_lin);
//     chass.driveAngle(-880, neg(135), {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
//     intake.setJamProtection(true);
//     pros::delay(550);
//     chass.turn(30, {.timeout=490, .exit = new Range(3, 20)});
//     clamp.toggle();
//     tsukasa.toggle();
//     Pt ringStack = {65.3, 7.0};
//     chass.turnTo(ringStack, {.timeout=350, .exit = new Range(3, 20)});
//     // intake.setSorting(false);
//     // CHANGED TODAYS
//         chass.mtpoint(ringStack, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 9, .exit = new exit::Range(5, 50)});
//     lb.next();
//     tsukasa.toggle();
//     pros::delay(200);
//     // chass.driveAngle(800, 90, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
//     chass.driveAngle(-400, 90, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
//     //67.5 < x
//     //68 < x
//     //68.3 < x
//     //68,8 < x
//     Pt allianceStake = {71.5, -16.9};
//     chass.turnTo(allianceStake, {.timeout=700, .exit = new Range(5, 20)});
//     // chass.turn(neg(18    0), {.timeout=900, .exit = new Range(3, 20)});
//     intake.move(0);
//     lb.setState(keejLib::LiftState::lower);
//     tsukasa.toggle();
//     //10 < x
//     chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
//     intake.move(127);
//     lb.next();
//     pros::delay(700);
//     // chass.driveAngle(-400, neg(180), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
//     // 49.1 < x
//     // 15 tpp small
//     Pt goal = {52, 18.4};
//     intake.move(0);
//     chass.mtpoint(goal, {.async = true, .timeout = 1000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(7, 10), .drift = 5});
//     pros::delay(400);
//     lb.setState(keejLib::LiftState::idle);
//     chass.waitUntilSettled();
//     // chass.turn(140, {.timeout=500, .exit = new Range(3, 20)});
//     // chass.driveAngle(-900, 140, {.async = true, .timeout = 1000, .vMin = 35, .exit = new Range(5, 20)});
//     tsukasa.toggle();
//     // intake.setSorting(true);
//     // CHANGED TODAY
//     // chass.turn(150, {.timeout = 280});
//     chass.driveAngle(-1200, 155, {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(5, 20), .slew = 3});
//     chass.setAng(_ang);
//     clamp.toggle();
//     pros::delay(100);
// // chass.driveAngle(-300, 150, {.async = false, .timeout = 400});
//     chass.turn(neg(58), {.timeout=600, .exit = new Range(7, 10)});
//     intake.move(127);
//     chass.driveAngle(800, neg(58), {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(150, 10)});
//     // pros::delay(1000);
//     // QUlals
//     // chass.driveAngle(-1400, neg(80), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(40, 12)});
//     chass.driveAngle(-1000, neg(45), {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
//     lb.next();
//     chass.driveAngle(1000, 45, {.async = false, .timeout = 800, .vMin = 0, .exit = new Range(5, 20)});
    
    
//     //-----
//     // intake.setSorting(false);
//     // intake.move(20);
//     // 
// }
void qbPos() {
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});
    
    // turnToRing(100000);
    // chass.mtpoint({64.0, -1.0}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // return;
    
    doink.toggle();
    //24 < x
    // 26 < x
    // 27 < x?
    chass.moveWithin({17.14, 36.9}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 10), .reverse=false, }, 28.5);
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
    chass.driveAngle(-700, 151, {.async = false, .timeout = 400, .vMin = 0,  .vMax = 40, .exit = new Range(10, 20)});
    // chass.driveAngle(-4, 151, {.async = false, .timeout = 370, .vMin = 0, .exit = new Range(10, 20)});
    chass.setLin(_lin);
    pros::delay(100);
    clamp.toggle();
    pros::delay(100);
    //1490
    //1400
 Pt fourStack = {9.5, -2.1};
    chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});
    lb.next();
    lb.next();
    // chass.driveAngle(1380, 187, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(300);
    intake.move(127);
    chass.setLin(_linSmall);

    Pt corner = {0.4,-15};
        chass.turn(neg(110), {.timeout = 300});

    double ang = chass.turnTo(corner, {.timeout = 400});
    intake.setJamProtection(false);
    chass.driveAngle(700, ang, {.async = false, .timeout = 610, .exit = new Range(5, 20)});
    pros::delay(100);
    chass.driveAngle(-500, ang, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
    intake.setJamProtection(false);
    chass.setLin(_lin);

    pros::delay(700);
    chass.turn(140, {.async = true, .timeout=600, .exit = new Range(3, 20)});
    pros::delay(200);
    clamp.toggle();
    chass.waitUntilSettled();

    Pt g2Prime = {35, 18.92};
    chass.turnTo(g2Prime,  {.exit = new Range(10, 10),.reverse = true});
    chass.mtpoint(g2Prime, {.drift = 5});
    chass.driveAngle(-1000, neg(140), {.async = true, .timeout = 1300, .vMax = 60, .slew = 5});
    pros::delay(600);
    clamp.toggle();

    chass.driveAngle(900, neg(88), {.timeout = 400, .vMin = 40});
    chass.driveAngle(1000, neg(93), {.timeout = 750, .vMin= 40});
    // Pt ring = {-20, 31};
    // chass.turn(90, {.timeout = 400});
    // chass.mtpoint(ring,{.drift = 4});
    // intake.stopOnColor(Color col, int timeout)

    Pt stake = {-4, 55.5};
    Pt scoringPosition = {1.8, 46.5};
    chass.mtpoint(scoringPosition, {.async = true, .exit = new Range(4, 10),.drift = 3});
    pros::delay(200);
    chass.waitUntilSettled();
    chass.setTurn(_5);
    ang = chass.turnTo(stake, {.timeout = 600});
    chass.setTurn(_90);
    lb.next();
    chass.driveAngle(200, ang+10, {.timeout = 300});
    chass.driveAngle(-200, ang-10, {.timeout = 300});
chass.driveAngle(200, ang+10, {.timeout = 300});
}