#include "constants.hpp"
#include "funcs.hpp"

void rnegElims(){
    //14.4
    Pt allianceStake = {-16.8, -10.0531};
    // Pt firstGoal = {-4, 23};
    Pt firstGoal = {-3, 23};
    Pt firstRing = {-33, 35};
    // Pt secondGoal = {32, 23};
    Pt secondGoal = {35, 33};
    Pt secondRing = {63, 36};
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    // prosController.print(0, 0, "%f", imu.get_rotation());
    
    redirect.toggle();
    pros::delay(280);
    robot::intake.move(127);
    pros::delay(980);
    robot::tsukasa.toggle();
    lift.setState(Lift::mid);
    chass.driveAngle(570, neg(62), {.async = true, .timeout = 2000, .vMin = 0, .exit = new Range(20, 50)});
    // chass.mtpoint({4,8}, {
    //     .async = false,
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(3, 400),
    // });
    pros::delay(500);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, neg(62), {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(80);
    lift.setState(Lift::resting);
    pros::delay(1650);
    chass.waitUntilSettled();
    lift.setState(Lift::mid);
    intake.move(-127);
    chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(1, 100)});
    chass.moveWithin(allianceStake, 11.2, {.timeout = 2000, .exit = new exit::Range(5, 200)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    // chass.turnTo(firstGoal, {.timeout=3000, .exit = new Range(2, 30), .reverse = true});
    
    // chass.mtpoint(firstGoal, {.timeout = 4000, .vMin = 20, .settleRange = 3, .exit = new exit::Range(3, 400)});
    chass.setLin(_lin);
    chass.driveAngle(-320, neg(170), {.timeout = 2000, .vMin = 70, .exit = new Range(50, 10)});
    chass.mtpoint({-1.9, 14.5}, {.timeout = 900, .vMin = 70, .settleRange = 3, .exit = new exit::Range(50, 10), .drift = 24});
    chass.driveAngle(-700, neg(150), {.async = false, .timeout = 3000, .vMin = 40, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-700, neg(150), {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    clamp::tilt();
    
    redirect.toggle();
    intake.move(127);
    chass.turnTo(firstRing, {.timeout=600, .exit = new Range(15, 20)});
    chass.mtpoint(firstRing, {.timeout = 700, .vMin = 30, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    
    // chass.mtpoint({-10, 20}, {.timeout = 8000, .vMin = 30, .settleRange = 8, .exit = new exit::Range(3, 400), .drift = 15});
    chass.setLin(_lin);
    // chass.turn(60, {.timeout = 100, .exit = new Range(5, 20)});
    chass.setAng(_angBig);
    chass.driveAngle(-2700, 65, {.timeout = 3000, .vMin = 67, .exit = new Range(20, 10)});
    chass.setAng(_ang);
    chass.driveAngle(-900, 94, {.async = true, .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
}

void negRed() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    robot::intake.move(127);
    stopOnColor();
    chass.moveWithin({0, -17}, 14.9, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
    chass.setAng(_angBig);
    chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
    clamp::clamp();
    chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    chass.turn(135, {.timeout=1000, .exit = new Range(1, 20)});
    chass.driveAngle(1200, 135, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(100, {.timeout=1000, .exit = new Range(1, 20)});
    chass.driveAngle(700, 100, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
    chass.mtpoint({0,-17}, {.timeout = 3000, .exit = new Range(7, 40), .reverse = true});
    chass.driveAngle(1200, 90, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
    chass.driveAngle(-2000, 108, {.timeout = 1700, .vMin = 0, .exit = new Range(20, 40)});
    robot::intake.move(0);
    chass.turnTo({-34, 0}, {.timeout = 3000, .exit = new Range(7, 40)});
}

// void negBlue() {
//     chass.setTurn(_90);
//     chass.setAng(_ang);
//     chass.setLin(_lin);
//     chass.setMTP(_chassLin, _chassAng);
    
//     robot::intake.move(127);
//     stopOnColor();
//     chass.moveWithin({0, -17}, 14.9, {.timeout = 3000, .vMin = 30, .exit = new Range(5, 40), .reverse = true});
//     chass.setAng(_angBig);
//     chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 10)});
//     clamp::clamp();
//     chass.driveAngle(-780, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
//     chass.turn(135, {.timeout=1000, .exit = new Range(1, 20)});
//     chass.driveAngle(1200, 135, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
//     chass.turn(100, {.timeout=1000, .exit = new Range(1, 20)});
//     chass.driveAngle(700, 100, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
//     chass.mtpoint({0,-17}, {.timeout = 3000, .exit = new Range(7, 40), .reverse = true});
//     chass.driveAngle(1200, 90, {.timeout = 1200, .vMin = 0, .exit = new Range(20, 40)});
//     chass.driveAngle(-2000, 108, {.timeout = 1700, .vMin = 0, .exit = new Range(20, 40)});
//     robot::intake.move(0);
//     chass.turnTo({-34, 0}, {.timeout = 3000, .exit = new Range(7, 40)});
// }