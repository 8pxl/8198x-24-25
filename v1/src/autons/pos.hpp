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

//     // chass.driveAngle(-1330, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
//     // 17
//     chass.moveWithin({0, -50}, 14.9, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
//     chass.setAng(_angBig);
//     chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
//     clamp::clamp();
//     chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     chass.driveAngle(550, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.waitUntilSettled();
//     // pros::delay(300);
//     clamp::tilt();
//     robot::intake.move(127);
//     chass.driveAngle(-300, 0, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     redirect.toggle();
//     robot::intake.move(127);
//     chass.driveAngle(500, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
//     chass.driveAngle(200, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
//     chass.driveAngle(200, neg(6), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
//     // chass.driveAngle(400, 30, {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
//     pros::delay(500);
//     chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
//     pros::delay(400);
//     lift.switchState();
//     chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
//     robot::intake.move(-127);
//     // chass.turnTo(Pt target, MotionParams params)
//     tsukasa.toggle();
//     chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     clamp::clamp();
//     //170
//     chass.driveAngle(200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
//     chass.turn(neg(45), {.timeout=3000, .exit = new Range(4, 30)});
//     chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
//     pros::delay(600);
//     robot::intake.move(127);
//     robot::tsukasa.toggle();
//     chass.waitUntilSettled();
//     chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
//     //13, -18
//     chass.driveAngle(-750, neg(67), {.async = true, .timeout = 3000, .vMin = 38, .exit = new Range(80, 10)});
//     stopOnColor();
//     chass.waitUntilSettled();
//     robot::redirect.toggle();
//     // chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
//     //         chass.mtpoint({-4, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
//         chass.mtpoint({3, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
//     // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
//     chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
//     clamp::clamp();
//     chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     pros::delay(190);
//     clamp::tilt();
    
//     //40,20
//     //38, 16
//     //35, 16
    
//     //12, 14
    
//     //36
//     //35.5
//     chass.turnTo({36, 13}, {.timeout=1000, .exit = new Range(2, 20)});
//     robot::intake.move(127);
//     spitColor();
//     // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
//     // 13.8
//     chass.moveWithin({36,13}, 12.8, {.timeout=2100, .exit = new Range(5, 100)});
//     lift.toggle();
//     pros::delay(390);
//     robot::intake.move(127);
// }
void posBlueShared() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    //1355
    //1350

    // chass.driveAngle(-1330, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
    // 17
    // 14.9
    chass.moveWithin({0, -50}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
    clamp::clamp();
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    // pros::delay(300);
    clamp::tilt();
    pros::delay(250);
    // -0.22150, -1,29493
    robot::intake.move(127);
    chass.waitUntilSettled();
    chass.driveAngle(-300, 0, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(200);
    redirect.toggle();
    robot::intake.move(127);
    chass.driveAngle(500, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    chass.driveAngle(200, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
    chass.driveAngle(200, neg(6), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
    // chass.driveAngle(400, 30, {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
    pros::delay(500);
    chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    //170
    chass.driveAngle(200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-1000, neg(65), {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    // lift.toggle();
    robot::redirect.toggle();
    // chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({-4, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
        chass.mtpoint({6.4, -18}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    robot::intake.move(-20);
    
    // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    robot::intake.move(0);
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
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
    // 41
    chass.turnTo({40, 13}, {.timeout=900, .exit = new Range(2, 20)});
    robot::intake.move(127);
    spitColor();
    // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // 13.8
    // 12.4
    // 12.8
    // 12.7
    // 13
    chass.moveWithin({40,13}, 14.7, {.timeout=2100, .exit = new Range(5, 100)});
    lift.toggle();
    pros::delay(390);
    spitColor();
}

void posBlueNoStake() {
    keejLib::Stopwatch t1;
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    //1355
    //1350

    // chass.driveAngle(-1330, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
    // 17
    // 14.9
    chass.moveWithin({0, -50}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
    clamp::clamp();
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    // pros::delay(300);
    clamp::tilt();
    // -0.22150, -1,29493
    robot::intake.move(127);
    chass.waitUntilSettled();
    chass.driveAngle(-300, 0, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(200);
    // redirect.toggle();
    robot::intake.move(127);
    chass.driveAngle(500, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    chass.driveAngle(200, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
    chass.driveAngle(200, neg(6), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
    // chass.driveAngle(400, 30, {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
    pros::delay(500);
    chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    //170
    chass.driveAngle(200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-1000, neg(73), {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    // lift.toggle();
    // robot::redirect.toggle();
    // chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({-4, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
        chass.mtpoint({6.4, -18}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
    // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    pros::delay(190);
    clamp::tilt();
    robot::intake.move(127);
    
    int time = 15000 - t1.elapsed() - 1000;
    chass.mtpoint({-8, -40}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turnTo({-20, -90}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
    
    //40,20
    //38, 16
    //35, 16
    
    //12, 14
    
    //36
    //35.5
    //36, 13
    //37.4
    // lift.toggle();
    // chass.turnTo({41, 13}, {.timeout=900, .exit = new Range(2, 20)});
    // robot::intake.move(127);
    // spitColor();
    // // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // // 13.8
    // // 12.4
    // // 12.8
    // // 12.7
    // chass.moveWithin({41,13}, 13, {.timeout=2100, .exit = new Range(5, 100)});
    // lift.toggle();
    // pros::delay(390);
    // spitColor();
}

void posAwpBlue() {
    posBlueShared();
    
    // chass.mtpoint({20, -30}, {.timeout=3000, .exit = new Range(0.8, 20)});
    
    chass.driveAngle(-1580, 20, {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-890, neg(45), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    redirect.toggle();
}

void posRedShared() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    //1355
    //1350

    // chass.driveAngle(-1330, 0, {.timeout = 3000, .vMin = 38, .exit = new Range(20, 40), .slew = 2});
    // 17
    // 14.9
    chass.moveWithin({0, -50}, 12.8, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
    clamp::clamp();
    chass.driveAngle(-690, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    // pros::delay(300);
    clamp::tilt();
    pros::delay(250);
    // -0.22150, -1,29493
    robot::intake.move(127);
    chass.waitUntilSettled();
    chass.driveAngle(-300, 0, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    robot::intake.move(127);
    chass.driveAngle(500, neg(40), {.async = true, .timeout = 3000, .vMin = 0, .exit = new Range(20, 10)});
    pros::delay(200);
    redirect.toggle();
    chass.driveAngle(200, neg(40), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)}, true);
    chass.driveAngle(200, neg(6), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(30, 40)});
    // chass.driveAngle(400, 30, {.timeout = 3000, .vMin = 40, .exit = new Range(20, 40)});
    pros::delay(500);
    chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);
    lift.switchState();
    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    //170
    chass.driveAngle(200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    chass.driveAngle(-1000, neg(73), {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    stopOnColor();
    chass.waitUntilSettled();
    // lift.toggle();
    robot::redirect.toggle();
    // chass.mtpoint({6.5, -21}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({-4, -18}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
        chass.mtpoint({6.4, -18}, {.async = false, .timeout = 2000, .vMin = 33, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    
    // chass.mtpoint({10, -29}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-600, neg(30), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
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
    chass.turnTo({39, 13}, {.timeout=900, .exit = new Range(2, 20)});
    robot::intake.move(127);
    spitColor();
    // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // 13.8
    // 12.4
    // 12.8
    // 12.6
    chass.moveWithin({39,13}, 12.2, {.timeout=2100, .exit = new Range(5, 100)});
    lift.toggle();
    pros::delay(390);
    spitColor();
}

void posRedSafe() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    

    // chass.moveWithin({0, -17}, 10, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    robot::intake.move(30);
    //280
    //300
    chass.driveAngle(-300, 0, {.async = false, .timeout = 900, .vMin = 0, .exit = new Range(10, 50)});
    chass.setAng(_angBig);
    chass.turn(neg(30), {.timeout=1000, .exit = new Range(1, 20)});
    chass.driveAngle(-1200, neg(30), {.async = true, .timeout = 3000, .vMin = 0, .exit = new Range(10, 50)});
    pros::delay(750);
    clamp::clamp();
    pros::delay(200);
    clamp::tilt();
    robot::intake.move(127);
    chass.turn(neg(90), {.timeout=1000, .exit = new Range(1, 20)});
    
    chass.driveAngle(900, neg(90), {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
    chass.driveAngle(-500, neg(90), {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
    lift.switchState();
    chass.mtpoint({-18, -3}, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 9, .exit = new exit::Range(24, 20), .drift = 20});
    pros::delay(400);

    chass.turn(40, {.timeout=3000, .exit = new Range(30, 20)});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();
    // chass.driveAngle(-400, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::clamp();
    //170
    // chass.driveAngle(200, 40, {.timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=900, .exit = new Range(4, 30)});
    chass.driveAngle(850, neg(45), {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(600);
    tsukasa.toggle();
    robot::intake.move(127);
    redirect.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(45), {.timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    // stopOnColor();
    chass.driveAngle(-1500, neg(73), {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    pros::delay(800);
    chass.waitUntilSettled();
    redirect.toggle();
    pros::delay(700);
    lift.toggle();
    chass.turnTo({39, 13}, {.timeout=900, .exit = new Range(2, 20)});
    robot::intake.move(127);
    spitColor();
    // chass.mtpoint({36, 16}, {.timeout=1000, .exit = new Range(5, 20), .within = 14.5});
    // 13.8
    // 12.4
    // 12.8
    // 12.6
    chass.moveWithin({39,13}, 10, {.timeout=2100, .exit = new Range(5, 100)});
    lift.toggle();
    pros::delay(390);
    spitColor();
    
}
void posAwpRed() {
    posRedShared();
    chass.driveAngle(-1580, 20, {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-890, neg(45), {.async = false, .timeout = 1000, .vMin = 0, .exit = new Range(20, 10)});
    redirect.toggle();
}

void posRedElims() {
    keejLib::Stopwatch t1;
    posRedShared();
    int time = 15000 - t1.elapsed()-100;
    chass.mtpoint({-8, -40}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turnTo({-20, -90}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
}
void posBlueElims() {
    posBlueShared();
    keejLib::Stopwatch t1;
    int time = std::max(300,15000 - t1.elapsed() - 100);
    chass.mtpoint({-8, -40}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turnTo({-20, -90}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
}