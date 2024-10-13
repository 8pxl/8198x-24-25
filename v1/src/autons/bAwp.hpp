#include "constants.hpp"
#include "funcs.hpp"

void soloBlue () {
    //14.4
    //12.5
    Pt allianceStake = {12.1, -10.0531};
    // Pt firstGoal = {-4, 23};
    Pt firstGoal = {-3.5, 25};
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
    chass.driveAngle(570, 62, {.async = true, .timeout = 2000, .vMin = 0, .exit = new Range(20, 50)});
    // chass.mtpoint({4,8}, {
    //     .async = false,
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(3, 400),
    // });
    pros::delay(500);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, 62, {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(80);
    lift.setState(Lift::resting);
    pros::delay(1650);
    chass.waitUntilSettled();
    lift.setState(Lift::mid);
    intake.move(-127);
    chass.turnTo(allianceStake, {.timeout=1000, .exit = new Range(1, 100)});
    //11.5
    //11.45
    chass.moveWithin(allianceStake, 11, {.timeout = 1400, .exit = new exit::Range(5, 200)});
    // chass.driveAngle(400, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 50)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    // chass.turnTo(firstGoal, {.timeout=3000, .exit = new Range(2, 30), .reverse = true});
    
    // chass.mtpoint(firstGoal, {.timeout = 4000, .vMin = 20, .settleRange = 3, .exit = new exit::Range(3, 400)});
    chass.setLin(_lin);
    chass.setAng(_angBig);
    chass.driveAngle(-250, 170, {.timeout = 2000, .vMin = 70, .exit = new Range(50, 10)});
    chass.setAng(_ang);
    // chass.mtpoint({1.9, 14.5}, {.timeout = 900, .vMin = 70, .settleRange = 3, .exit = new exit::Range(50, 10), .drift = 24});
    chass.mtpoint({-2, 16.5}, {.timeout = 1000, .vMin = 70, .settleRange = 3, .exit = new exit::Range(50, 10), .drift = 24});
    chass.driveAngle(-700, 150, {.async = false, .timeout = 3000, .vMin = 40, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-700, 150, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    clamp::tilt();
    
    redirect.toggle();
    intake.move(127);
    chass.turnTo(firstRing, {.timeout=500, .exit = new Range(15, 20)});
    chass.mtpoint(firstRing, {.timeout = 700, .vMin = 30, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    // chass.mtpoint({-10, 20}, {.timeout = 8000, .vMin = 30, .settleRange = 8, .exit = new exit::Range(3, 400), .drift = 15});
    chass.setLin(_lin);
    // chass.turn(neg(60), {.timeout = 100, .exit = new Range(5, 20)});
    chass.setAng(_angBig);
    // chass.driveAngle(-2400, neg(65), {.timeout = 1360, .vMin = 67, .exit = new Range(20, 10)});
    chass.driveAngle(-1200, neg(65), {.timeout = 1360, .vMin = 67, .exit = new Range(20, 10)});
    chass.driveAngle(-660, neg(90), {.timeout = 1360, .vMin = 30, .exit = new Range(20, 10)});
    chass.setAng(_ang);
    chass.driveAngle(-900, neg(50), {.async = true, .timeout = 800, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(200);
    clamp::tilt();
    pros::delay(90);
    clamp::clamp();
    chass.driveAngle(410, neg(50), {.timeout = 350, .vMin = 1, .exit = new Range(80, 10)});
    // chass.driveAngle(-1000, neg(90), {.timeout = 3000, .vMin = 30, .exit = new Range(20, 40)});
    chass.turnTo(secondGoal, {.timeout=990, .exit = new Range(5, 10), .reverse = true});
    chass.driveAngle(-900, neg(150), {.async = true, .timeout = 900, .exit = new Range(23, 40)});
    pros::delay(600);
    clamp::tilt();
    
    intake.move(127); 
    chass.turnTo(secondRing, {.timeout=990, .exit = new Range(10, 10)});
    chass.mtpoint(secondRing, {.timeout = 730, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 50), .drift = 30});
    lift.setState(Lift::mid);
    stopOnColor();
    chass.turn(neg(65), {.timeout=900, .exit = new Range(10, 10)});
    intake.move(127);
    spitColor();
    chass.driveAngle(1600, neg(70), {.async = true, .timeout = 2000, .exit = new Range(30, 20)});
    pros::delay(200);
    robot::tsukasa.setState(false);
    chass.waitUntilSettled();
    // while (!chass.isSettled()) {
    //     intake.move(127);
    // }
    lift.setOff(true);
    robot::tsukasa.setState(false);
}

void soloAwp() {
    //14.4
    Pt allianceStake = {16.85, -10.0531};
    // Pt firstGoal = {-4, 23};
    //     Pt firstGoal = {-3, 25};
    Pt firstGoal = {-1.6, 25};
    Pt firstRing = {-33, 34};
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
    chass.driveAngle(570, 62, {.async = true, .timeout = 2000, .vMin = 0, .exit = new Range(20, 50)});
    // chass.mtpoint({4,8}, {
    //     .async = false,
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(3, 400),
    // });
    pros::delay(500);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    chass.driveAngle(-200, 62, {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(80);
    lift.setState(Lift::resting);
    pros::delay(1730);
    chass.waitUntilSettled();
    lift.setState(Lift::mid);
    intake.move(-127);
    chass.turnTo(allianceStake, {.timeout=1000, .exit = new Range(1, 100)});
    //11.8
    //12.7
    chass.moveWithin(allianceStake, 12.4, {.timeout = 2000, .exit = new exit::Range(5, 200)});
    // chass.driveAngle(400, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 50)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    // chass.turnTo(firstGoal, {.timeout=3000, .exit = new Range(2, 30), .reverse = true});
    
    // chass.mtpoint(firstGoal, {.timeout = 4000, .vMin = 20, .settleRange = 3, .exit = new exit::Range(3, 400)});
    chass.setLin(_lin);
    chass.setAng(_angBig);
    chass.driveAngle(-320, 170, {.timeout = 2000, .vMin = 70, .exit = new Range(50, 10)});
    chass.setAng(_ang);
    // chass.mtpoint({1.9, 14.5}, {.timeout = 900, .vMin = 70, .settleRange = 3, .exit = new exit::Range(50, 10), .drift = 24});
    chass.mtpoint({2.3, 16.5}, {.timeout = 900, .vMin = 70, .settleRange = 3, .exit = new exit::Range(50, 10), .drift = 24});
    chass.driveAngle(-700, 150, {.async = false, .timeout = 3000, .vMin = 40, .exit = new Range(80, 10)});
    clamp::clamp();
    chass.driveAngle(-700, 150, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(20, 5)}, true);
    clamp::tilt();
    
    redirect.toggle();
    intake.move(127);
    chass.turnTo(firstRing, {.timeout=500, .exit = new Range(15, 20)});
    chass.mtpoint(firstRing, {.timeout = 700, .vMin = 30, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    // chass.mtpoint({-10, 20}, {.timeout = 8000, .vMin = 30, .settleRange = 8, .exit = new exit::Range(3, 400), .drift = 15});
    chass.setLin(_lin);
    // chass.turn(neg(60), {.timeout = 100, .exit = new Range(5, 20)});
    chass.setAng(_angBig);
    chass.driveAngle(-2400, neg(65), {.timeout = 1260, .vMin = 67, .exit = new Range(20, 10)});
    chass.setAng(_ang);
    chass.driveAngle(-600, neg(50), {.async = true, .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(200);
    clamp::tilt();
    pros::delay(90);
    clamp::clamp();
    chass.driveAngle(410, neg(50), {.timeout = 400, .vMin = 1, .exit = new Range(80, 10)});
    // chass.driveAngle(-1000, neg(90), {.timeout = 3000, .vMin = 30, .exit = new Range(20, 40)});
    chass.turnTo(secondGoal, {.timeout=1000, .exit = new Range(5, 10), .reverse = true});
    chass.driveAngle(-1100, neg(150), {.async = true, .timeout = 2000, .exit = new Range(23, 40)});
    pros::delay(600);
    clamp::tilt();
    
    intake.move(127); 
    chass.turnTo(secondRing, {.timeout=900, .exit = new Range(10, 10)});
    chass.mtpoint(secondRing, {.timeout = 700, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 50), .drift = 30});
    lift.setState(Lift::mid);
    stopOnColor();
    chass.turn(neg(65), {.timeout=900, .exit = new Range(10, 10)});
    intake.move(127);
    spitColor();
    chass.driveAngle(1600, neg(70), {.async = true, .timeout = 2000, .exit = new Range(30, 20)});
    pros::delay(200);
    robot::tsukasa.setState(false);
    chass.waitUntilSettled();
    // while (!chass.isSettled()) {
    //     intake.move(127);
    // }
    lift.setOff(true);
    robot::tsukasa.setState(false);
}