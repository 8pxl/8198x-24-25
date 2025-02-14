#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;
// void qrPos() {
//     chass.setTurn(_90);
//     chass.setAng(_angBig);
//     chass.setLin(_lin);
//     chass.setMTP(_chassLin, _chassAng);
//     // chass.mtpoint({-64, -1}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
//     // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
//     // return;
    
//     doink.toggle();
//     chass.moveWithin({-9.9,39.2}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 30), .reverse=false, }, neg(9.9));
//     chass.setAng(_ang);
//     claw.toggle();
//     // chass.driveAngle(500, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(5, 20), .slew = 2});
//     chass.driveAngle(-1400, neg(10), {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(800, 40)});
//     chass.driveAngle(-1400, 20, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(600, 30)},true);
//     chass.driveAngle(-1400, 33, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 10)}, true);
//     claw.toggle();
//     chass.driveAngle(-460, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(35, 20)});
//     doink.toggle();
//     chass.turn(90, {.timeout=150, .exit = new Range(3, 20)});
//     chass.turn(135, {.timeout=50, .exit = new Range(3, 20)});
//     chass.turn(190, {.timeout=400, .exit = new Range(3, 20)});
//     chass.driveAngle(-750, 200, {.async = false, .timeout = 680, .vMin = 28, .exit = new Range(30, 10)});
//     chass.setLin(_linSmall);
//     chass.driveAngle(-900, neg(180), {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 20)});
//     chass.setLin(_lin);
//     clamp.toggle();
//     //1490
//     //1400
//     Pt fourStack = {-12.5, -2.8};
//     chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});
//     // chass.driveAngle(1380, 187, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
//     pros::delay(300);
//     intake.move(127);
//     chass.setLin(_linSmall);

//     chass.driveAngle(1450, 135, {.async = false, .timeout = 610, .vMin = 20, .exit = new Range(5, 20)});
//     pros::delay(300);
//     chass.driveAngle(-880, 135, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
//     chass.setLin(_lin);

//     pros::delay(300);
//     chass.turn(neg(30), {.timeout=490, .exit = new Range(3, 20)});
//     clamp.toggle();
//     tsukasa.toggle();
//     //3.9 < x
//     Pt ringStack = {-62, 4.2};
//     chass.turnTo(ringStack, {.timeout=350, .exit = new Range(3, 20)});
//     // chass.driveAngle(1830, imu.get_heading(), {.async = false, .timeout = 1200, .vMin = 0, .exit = new Range(5, 20)});
//     // intake.setSorting(false);
//     // CHANGED TODAY
//         chass.mtpoint(ringStack, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
//     lb.next();
//     tsukasa.toggle();
//     // chass.setLin(_linSmall);
//     chass.driveAngle(300, neg(90), {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(20, 10)});
//     chass.setLin(_lin);
//     chass.driveAngle(-180, neg(90), {.async = false, .timeout = 500, .vMin = 0, .exit = new Range(20, 10)});
//     Pt allianceStake = {-66.89, -15};
//     chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(5, 20)});
//     // chass.turn(180, {.timeout=900, .exit = new Range(3, 20)});
//     intake.move(0);
//     lb.next();
//     lb.next();
//     tsukasa.toggle();
//     //11.4 > x
//     //11.2 > x
//     chass.moveWithin(allianceStake, 10.9, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
//     intake.move(127);
//     lb.next();
//     pros::delay(600);
//     // chass.driveAngle(-400, 180, {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
//     Pt goal = {-54.1, 16.8};
//     intake.move(0);
//     chass.mtpoint(goal, {.async = false, .timeout = 1000, .vMin = 30, .settleRange = 9, .exit = new exit::Range(3, 30), .drift = 16});
//     // lb.next();
//     lb.setState(LiftState::idle);
//     // chass.turn(neg(140), {.timeout=500, .exit = new Range(3, 20)});
//     // chass.driveAngle(-900, neg(140), {.async = true, .timeout = 1000, .vMin = 35, .exit = new Range(5, 20)});
//     tsukasa.toggle();
//     // intake.setSorting(true);
//     chass.setLin(_linSmall);
//     chass.driveAngle(-920, neg(150), {.timeout = 900, .exit = new Range(200, 15), .slew=3});
//     clamp.toggle();
//     chass.driveAngle(-920, neg(150), {.timeout = 360, .exit = new Range(70, 15), .slew=3,}, true);
//     // chass.driveAngle(-1000, neg(150), {.async = false, .timeout = 450, .vMin = 0, .exit = new Range(5, 20)});
//     chass.setLin(_lin);
//     chass.setAng(_ang);
//     // pros::delay(200);
//     // clamp.toggle();
//     chass.turnTo({-22.5, 29.8}, {.timeout=600, .exit = new Range(10, 10)});
//     intake.move(127);
//     chass.mtpoint({-22.5, 29.8}, {.async = false, .timeout = 800, .vMin = 0, .settleRange = 5, .exit = new exit::Range(3, 300)});
//     pros::delay(2000);
//     // pros::delay(600);
//     // 
//     // 
//     // QUALS
//     // chass.driveAngle(-400, 90, {.async = true, .timeout = 400, .vMin = 0, .exit = new Range(5, 20)});
//     // Pt corner = {-40, 45 };
//     // chass.turnTo(corner, {.timeout=500, .exit = new Range(5, 10)});
//     // chass.driveAngle(1000, imu.get_heading(), {.async = false, .timeout = 1500, .vMin = 0, .exit = new Range(5, 20)});
    
//     //ELIMS
//     // chass.driveAngle(600, 95, {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(5, 20)});
//     // pros::delay(400);
//     // chass.turn(200,  {.timeout=600, .exit = new Range(3, 10)});
    
//     /* 
//     chass.mtpoint({-52, 40}, {.async = true, .timeout = 1700, .vMin = 0, .settleRange = 10, .exit = new exit::Range(5, 50)});
//     pros::delay(300);
//     intake.move(30);
//     chass.waitUntilSettled();
//     */
// }

void qrPos() {
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    // chass.mtpoint({-64, -1}, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // chass.mtpose({-64, -1, Angle(neg(90), keejLib::HEADING)}, 0.5, {.async = false, .timeout = 1700, .vMin = 0, .settleRange = 5, .exit = new exit::Range(5, 50)});
    // return;
    
    doink.toggle();
    chass.moveWithin({-9.9,39.2}, 0, {.timeout = 1500, .vMin=60, .exit = new Range(5, 30), .reverse=false, }, neg(15));
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
    chass.driveAngle(-750, 190, {.async = false, .timeout = 680, .vMin = 28, .exit = new Range(30, 10)});
    chass.setLin(_linSmall);
    chass.driveAngle(-900, neg(180), {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 20)});
    chass.setLin(_lin);
    clamp.toggle();
    pros::delay(150);
    //1490
    //1400
    Pt fourStack = {-9.5, -1.1};
    chass.mtpoint(fourStack, {.async = true, .timeout = 1000, .vMin = 30, .settleRange = 14, .exit = new exit::Range(3, 30), .drift = 20});
    lb.next();
    lb.next();
    // chass.driveAngle(1380, 187, {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(5, 20)});
    pros::delay(300);
    intake.move(127);
    chass.setLin(_linSmall);

    Pt corner = {-0.4,-14};
    chass.turn(110, {.timeout = 300});
    double ang = chass.turnTo(corner, {.timeout = 400});
    intake.setJamProtection(false);
    chass.driveAngle(700, ang, {.async = false, .timeout = 610, .exit = new Range(5, 20)});
    pros::delay(100);
    chass.driveAngle(-500, ang, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(5, 200)});
    intake.setJamProtection(false);
    chass.setLin(_lin);

    pros::delay(700);
    chass.turn(neg(135), {.async = true, .timeout=600, .exit = new Range(3, 20)});
    pros::delay(200);
    clamp.toggle();
    chass.waitUntilSettled();

    Pt g2Prime = {-35, 18.92};
    chass.turnTo(g2Prime,  {.exit = new Range(10, 10),.reverse = true});
    chass.mtpoint(g2Prime, {.drift = 5});
    chass.driveAngle(-1000, 140, {.async = true,.slew = 7});
    pros::delay(600);
    clamp.toggle();

    chass.driveAngle(500, 78, {.timeout = 400, .vMin = 40});
    chass.driveAngle(900, 111, {.timeout = 600, .vMin= 40});
    // Pt ring = {-20, 31};
    // chass.turn(90, {.timeout = 400});
    // chass.mtpoint(ring,{.drift = 4});
    // intake.stopOnColor(Color col, int timeout)

    Pt stake = {4, 55.5};
    Pt scoringPosition = {-2.41, 46.5};
    chass.mtpoint(scoringPosition, {.async = true, .timeout = 1400, .exit = new Range(4, 10),.drift = 3});
    pros::delay(200);
    chass.waitUntilSettled();
    chass.setTurn(_5);
    ang = chass.turnTo(stake, {.timeout = 500});
    chass.setTurn(_90);
    lb.next();
    chass.driveAngle(200, ang-10, {.timeout = 300});
    chass.driveAngle(-200, ang+10, {.timeout = 300});
chass.driveAngle(200, ang-10, {.timeout = 300});
}