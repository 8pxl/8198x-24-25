#include "constants.hpp"
#include "funcs.hpp"
#include "keejLib/util.h"

// void posBlueShared() {
//     chass.setTurn(_90);
//     chass.setAng(_ang);
//     chass.setLin(_linSmall);
//     chass.setMTP(_chassLin, _chassAng);
    
//     //1355
//     //1350

//     // chass.driveAngle(-1330, neg(0), {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
//     // 17
//     chass.moveWithin({-0.0, -50.0}, 14.9, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
//     chass.setAng(_angBig);
//     chass.driveAngle(-780, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
//     clamp::clamp();
//     chass.driveAngle(-780, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     chass.driveAngle(550, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.waitUntilSettled();
//     // pros::delay(300);
//     clamp::tilt();
//     robot::intake.move(127);
//     chass.driveAngle(-300, neg(0), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     redirect.toggle();
//     robot::intake.move(127);
//     chass.driveAngle(500, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
//     chass.driveAngle(200, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
//     chass.driveAngle(200, 6, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
//     // chass.driveAngle(400, neg(30), {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
//     pros::delay(500);
//     chass.mtpoint({18.0, -3.0}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
//     pros::delay(400);
//     lift.switchState();
//     chass.turn(neg(40), {.timeout=3000, .exit = new Range(30, 20)});
//     robot::intake.move(-127);
//     // chass.turnTo(Pt target, MotionParams params)
//     tsukasa.toggle();
//     chass.driveAngle(-400, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     clamp::clamp();
//     //170
//     chass.driveAngle(200, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.turn(45, {.timeout=3000, .exit = new Range(4, 30)});
//     chass.driveAngle(850, 45, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(600);
//     robot::intake.move(127);
//     robot::tsukasa.toggle();
//     chass.waitUntilSettled();
//     chass.driveAngle(-200, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
//     //13, -18
//     chass.driveAngle(-750, 67, {.async = true, .timeout = 3000, .vMin = 38, .exit = new Range(80, 10)});
//     stopOnColor();
//     chass.waitUntilSettled();
//     robot::redirect.toggle();
//     // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
//     //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
//         chass.mtpoint({-3.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
//     // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
//     clamp::clamp();
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     pros::delay(190);
//     clamp::tilt();
    
//     //40,20
//     //38, 16
//     //35, 16
    
//     //12, 14
    
//     //36
//     //35.5
//     chass.turnTo({-36.0, 13.0}, {.timeout=1000, .exit = new Range(2, 20)});
//     robot::intake.move(127);
//     spitColor();
//     // chass.mtpoint({-36.0, 16.0}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
//     // 13.8
//     chass.moveWithin({-36.0, 13.0}, 12.8, {.timeout=2100, .exit = new Range(5, 100)});
//     lift.toggle();
//     pros::delay(390);
//     robot::intake.move(127);
// }
// void posBlueShared() {
//     chass.setTurn(_90);
//     chass.setAng(_ang);
//     chass.setLin(_linSmall);
//     chass.setMTP(_chassLin, _chassAng);
    
//     //1355
//     //1350

//     // chass.driveAngle(-1330, neg(0), {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
//     // 17
//     // 14.9
//     chass.moveWithin({-0.0, -50.0}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
//     chass.setAng(_angBig);
//     chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
//     clamp::clamp();
//     chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     chass.driveAngle(550, neg(30), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(290);
//     // pros::delay(300);
//     clamp::tilt();
//     pros::delay(250);
//     // -0.22150, -1,29493
//     robot::intake.move(127);
//     chass.waitUntilSettled();
//     chass.driveAngle(-300, neg(0), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(200);
//     redirect.toggle();
//     robot::intake.move(127);
//     chass.driveAngle(500, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
//     chass.driveAngle(200, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
//     chass.driveAngle(200, 6, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
//     // chass.driveAngle(400, neg(30), {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
//     pros::delay(500);
//     chass.mtpoint({18.0, -3.0}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
//     pros::delay(400);
//     lift.switchState();
//     chass.turn(neg(40), {.timeout=3000, .exit = new Range(30, 20)});
//     robot::intake.move(-127);
//     // chass.turnTo(Pt target, MotionParams params)
//     tsukasa.toggle();
//     chass.driveAngle(-400, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     clamp::clamp();
//     //170
//     chass.driveAngle(200, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.turn(45, {.timeout=900, .exit = new Range(4, 30)});
//     chass.driveAngle(850, 45, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(600);
//     robot::intake.move(127);
//     robot::tsukasa.toggle();
//     chass.waitUntilSettled();
//     chass.driveAngle(-200, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
//     //13, -18
//     chass.driveAngle(-1000, 65, {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
//     stopOnColor();
//     chass.waitUntilSettled();
//     // lift.toggle();
//     robot::redirect.toggle();
//     // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
//     //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
//         chass.mtpoint({-6.4, -18.0}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
//     robot::intake.move(-20);
    
//     // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
//     clamp::clamp();
//     robot::intake.move(0);
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     pros::delay(190);
//     clamp::tilt();
    
//     //40,20
//     //38, 16
//     //35, 16
    
//     //12, 14
    
//     //36
//     //35.5
//     //36, 13
//     //37.4
//     // lift.toggle();
//     // 41
//     chass.turnTo({-40.0, 13.0}, {.timeout=900, .exit = new Range(2, 20)});
//     robot::intake.move(127);
//     spitColor();
//     // chass.mtpoint({-36.0, 16.0}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
//     // 13.8
//     // 12.4
//     // 12.8
//     // 12.7
//     // 13
//     chass.moveWithin({-40.0, 13.0}, 14.7, {.timeout=2100, .exit = new Range(5, 100)});
//     lift.toggle();
//     pros::delay(390);
//     spitColor();
// }

// void posBlueNoStake() {
//     keejLib::Stopwatch t1;
//     chass.setTurn(_90);
//     chass.setAng(_ang);
//     chass.setLin(_linSmall);
//     chass.setMTP(_chassLin, _chassAng);
    
//     //1355
//     //1350

//     // chass.driveAngle(-1330, neg(0), {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
//     // 17
//     // 14.9
//     chass.moveWithin({-0.0, -50.0}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
//     chass.setAng(_angBig);
//     chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
//     clamp::clamp();
//     chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     chass.driveAngle(550, neg(30), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(290);
//     // pros::delay(300);
//     clamp::tilt();
//     // -0.22150, -1,29493
//     robot::intake.move(127);
//     chass.waitUntilSettled();
//     chass.driveAngle(-300, neg(0), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(200);
//     // redirect.toggle();
//     robot::intake.move(127);
//     chass.driveAngle(500, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
//     chass.driveAngle(200, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
//     chass.driveAngle(200, 6, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
//     // chass.driveAngle(400, neg(30), {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
//     pros::delay(500);
//     chass.mtpoint({18.0, -3.0}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
//     pros::delay(400);
//     lift.switchState();
//     chass.turn(neg(40), {.timeout=3000, .exit = new Range(30, 20)});
//     robot::intake.move(-127);
//     // chass.turnTo(Pt target, MotionParams params)
//     tsukasa.toggle();
//     chass.driveAngle(-400, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     clamp::clamp();
//     //170
//     chass.driveAngle(200, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.turn(45, {.timeout=900, .exit = new Range(4, 30)});
//     chass.driveAngle(850, 45, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(600);
//     robot::intake.move(127);
//     robot::tsukasa.toggle();
//     chass.waitUntilSettled();
//     chass.driveAngle(-200, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
//     //13, -18
//     chass.driveAngle(-1000, 73, {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
//     stopOnColor();
//     chass.waitUntilSettled();
//     // lift.toggle();
//     // robot::redirect.toggle();
//     // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
//     //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
//         chass.mtpoint({-6.4, -18.0}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
//     // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
//     clamp::clamp();
//     chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     pros::delay(190);
//     clamp::tilt();
//     robot::intake.move(127);
    
//     int time = 15000 - t1.elapsed() - 1000;
//     chass.mtpoint({8.0, -40.0}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
//     chass.turnTo({20.0, -90.0}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
    
//     //40,20
//     //38, 16
//     //35, 16
    
//     //12, 14
    
//     //36
//     //35.5
//     //36, 13
//     //37.4
//     // lift.toggle();
//     // chass.turnTo({-41.0, 13.0}, {.timeout=900, .exit = new Range(2, 20)});
//     // robot::intake.move(127);
//     // spitColor();
//     // // chass.mtpoint({-36.0, 16.0}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
//     // // 13.8
//     // // 12.4
//     // // 12.8
//     // // 12.7
//     // chass.moveWithin({-41.0, 13.0}, 13, {.timeout=2100, .exit = new Range(5, 100)});
//     // lift.toggle();
//     // pros::delay(390);
//     // spitColor();
// }

// void posAwpBlue() {
//     posBlueShared();
    
//     // chass.mtpoint({-20.0, -30.0}, {.timeout=3000, .exit = new Range(0.8, 20)});
    
//     chass.driveAngle(-1580, neg(20), {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
//     chass.driveAngle(-890, 45, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
//     redirect.toggle();
// }

void rposShared() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    //1355
    //1350

    // chass.driveAngle(-1330, neg(0), {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
    // 17
    // 14.9
    chass.moveWithin({-0.0, -50.0}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
    clamp::clamp();
    chass.driveAngle(-690, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.driveAngle(550, neg(30), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    // pros::delay(300);
    clamp::tilt();
    pros::delay(250);
    // -0.22150, -1,29493
    robot::intake.move(127);
    chass.waitUntilSettled();
    chass.driveAngle(-300, neg(0), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    robot::intake.move(127);
    chass.driveAngle(500, 40, {.async = true, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    pros::delay(200);
    redirect.toggle();
    chass.driveAngle(200, 40, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
    chass.driveAngle(200, 6, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
    // chass.driveAngle(400, neg(30), {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
    pros::delay(500);
    chass.mtpoint({18.0, -3.0}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.turn(neg(40), {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-400, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    //170
    chass.driveAngle(200, neg(40), {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(45, {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(850, 45, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-1000, 73, {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    // lift.toggle();
    robot::redirect.toggle();
    // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
        chass.mtpoint({-6.4, -18.0}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
    // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-600, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    pros::delay(190);
    clamp::tilt();
    
    //40,20
    //38, 16
    //35, 16
    
    //12, 14
    
    //36
    //35.5
    //36, 13
    //37.4
    // lift.toggle();
    chass.turnTo({-39.0, 13.0}, {.timeout=900, .exit = new Range(2, 20)});
    robot::intake.move(127);
    spitColor();
    // chass.mtpoint({-36.0, 16.0}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // 13.8
    // 12.4
    // 12.8
    // 12.6
    chass.moveWithin({-39.0, 13.0}, 12.2, {.timeout=2100, .exit = new Range(5, 100)});
    lift.toggle();
    pros::delay(390);
    spitColor();
}

void rposAwp() {
    rposShared();
    chass.driveAngle(-1580, neg(20), {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-890, 45, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(20, 10)});
    redirect.toggle();
}

void rposElims() {
    keejLib::Stopwatch t1;
    rposShared();
    int time = 15000 - t1.elapsed()-100;
    chass.mtpoint({8.0, -40.0}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turnTo({20.0, -90.0}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
}

void rposNew() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //move to goal straight
    chass.setAng(_angBig);
    prosController.print(0,0, "%f", imu.get_heading());
    chass.moveWithin({-3.0, -20.6}, 0, {.timeout = 1500, .vMin=0, .exit = new Range(5, 100), .reverse=true, .slew = 1.8, }, neg(9.5));
    //turn to face goal and grab
    chass.driveAngle(-840, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 5), .slew = 2});
    clamp::clamp();
    chass.driveAngle(-840, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.setAng(_ang);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    clamp::tilt();
    pros::delay(250);
    robot::intake.move(127);
    chass.waitUntilSettled();
    pros::delay(1100);
    redirect.toggle();
    chass.turn(neg(70), {.timeout=900, .exit = new Range(4, 20)});
    chass.setAng(_angBig);
    chass.driveAngle(800, neg(70), {.timeout=550, .exit = new Range(20, 50)});
    chass.setAng(_ang);
    chass.driveAngle(-600, neg(70), {.timeout=1200, .exit = new Range(20, 50)});
    chass.turn(neg(180), {.timeout = 300, .exit = new Range(30, 10)});
    chass.mtpoint({-10.3, 13.3}, {.async = true, .timeout = 1400, .vMin = 20, .settleRange = 9, .exit = new exit::Range(10, 50), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.driveAngle(-900, 130, {.timeout=300, .exit = new Range(40, 20)});
    clamp::clamp();
    chass.driveAngle(-980, 130, {.timeout=400, .exit = new Range(40, 20)}, true);
    chass.driveAngle(240, 130, {.timeout=1000, .exit = new Range(20, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();


chass.turn(45, {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(900, 45, {.async = true, .timeout = 700, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(690);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-850, 73, {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    // lift.toggle();
    robot::redirect.toggle();
    // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    //31
    //33.4, -5.3
    //33.2
    //33.1
        chass.mtpoint({-32.9, -5.3}, {.async = false, .timeout = 2000, .vMin = 0, .settleRange = 9, .exit = new exit::Range(10, 100), .drift = 6, .within=0});
    
    // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.turn(30, {.timeout = 500, .exit = new Range(3, 70)});
    chass.driveAngle(-700, 30, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-700, 30, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(30, 5)}, true);
    clamp::tilt();
    
    //40,20
    //38, 16
    //35, 16
    
    //12, 14
    
    //36
    //35.5
    //36, 13
    //37.4
    // lift.toggle();
    //61.8
    //62.5
    chass.turnTo({-62.85, 30.0}, {.timeout=900, .exit = new Range(2, 80)});
    robot::intake.move(127);
    spitColor();
    // chass.mtpoint({-36.0, 16.0}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // 13.8
    // 12.4
    // 12.8
    // 12.6
    //12.4
    //12.9
    //62.5
    chass.moveWithin({-62.85, 30.0}, 13.1, {.timeout=2100, .exit = new Range(5, 100)});
    chass.turnTo({-62.85, 30.0}, {.timeout=900, .exit = new Range(2, 80)});
    lift.toggle();
    pros::delay(390);
    spitColor();

    chass.driveAngle(-1580, neg(20), {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-980, 45, {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(20, 10)});
    redirect.toggle();
    // {-10.43, 13.3};
}
// void posBlueElims() {
//     rpos();
//     keejLib::Stopwatch t1;
//     int time = std::max(300,15000 - t1.elapsed() - 100);
//     chass.mtpoint({8.0, -40.0}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
//     chass.turnTo({20.0, -90.0}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
// }