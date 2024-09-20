#include "constants.hpp"
#include "funcs.hpp"

void skills() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    Pt allianceStake = {18, -11.0531};
    robot::intake.move(127);
    lift.setState(Lift::mid);
    dt.move(-40);
    pros::delay(300);
    clamp::tilt();
    pros::delay(100);
    dt.move(0);
    
    chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(2, 100)});
    chass.mtpoint(allianceStake, {.timeout = 2000, .vMin = 0, .settleRange = 20, .exit = new exit::Range(20, 100), .drift = 5, .within = 14.5});
    chass.moveWithin(allianceStake, 14.5, {.timeout = 2000, .exit = new exit::Range(10, 300)});
    // chass.driveAngle(770, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 50)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    Pt ring1 = {-9,34};
    chass.driveAngle(-300, imu.get_heading(), {.timeout = 2000, .exit = new Range(20, 50)});
    lift.setState(Lift::raised);
    chass.turnTo(ring1, {.timeout=3000, .exit = new Range(3, 30)});
    chass.setLin(_lin);
    chass.driveAngle(1400, imu.get_heading(), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    chass.driveAngle(1300, neg(94), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    
    Pt ring3 = {-45, 10};
    chass.mtpoint(ring3, {.timeout = 1400, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    chass.driveAngle(-700, imu.get_heading(), {.timeout = 2000, .exit = new Range(50, 10)});
    chass.turnTo({-37, 0}, {.timeout=3000, .exit = new Range(5, 10)});
    chass.driveAngle(600, 170, {.timeout = 2000, .vMin = 10, .exit = new Range(10, 30)});
    // dt.move(-60);
    // pros::delay(100);
    chass.driveAngle(600, 180, {.timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(190);
    chass.turn(60, {.timeout=3000, .exit = new Range(1, 90)});
    chass.driveAngle(-700, 60, {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(200);
    clamp::clamp();
    chass.waitUntilSettled();
    robot::intake.move(-127);
    
    Pt ring4 = {-47, 55};
    lift.toggle();
    chass.mtpoint(ring4, {.async = true, .timeout = 1800, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 20), .drift = 14});
    robot::intake.move(127);
    pros::delay(500);
    redirect.toggle();
    chass.mtpoint({-34, 82}, {.timeout = 1500, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17});
    chass.turn(0, {.timeout=3000, .exit = new Range(5, 20)});
    chass.driveAngle(-1000, neg(3), {.timeout = 2000, .exit = new Range(20, 100)});
    lift.toggle();
    chass.turnTo({-59, 61.1}, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.moveWithin({-59, 61.1}, 12.5, {.timeout = 2000, .exit = new exit::Range(10, 300)});
    lift.toggle();
    pros::delay(400);
    chass.setLin(_linSmall);
    chass.driveAngle(-700, imu.get_heading(), {.timeout = 2000, .exit = new Range(20, 100)});
    chass.setLin(_lin);
    
    
    Pt ring5 = {-9, 86};
    chass.turnTo(ring5, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.driveAngle(2000, imu.get_heading(), {.timeout = 2000, .vMin = 45, .exit = new Range(100, 10)});
    clamp::clamp();
    chass.driveAngle(850, 90, {.timeout = 2000, .vMin =1, .exit = new Range(100, 50)});
    chass.driveAngle(-1400, 130, {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    lift.switchState();
    chass.driveAngle(-1400, 90, {.timeout = 2000, .vMin = 0, .exit = new Range(20, 80)});
    clamp::clamp();
    robot::intake.move(0);
    
    Pt goal2 = {-10, 120};
    chass.mtpoint(goal2, {.timeout = 1500, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17});
    chass.turn(neg(90), {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.driveAngle(-800, neg(90), { .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
    chass.driveAngle(-1200, neg(90), {.async = true, .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(400);
    clamp::clamp();
    // chass.driveAngle(500, neg(50), {.timeout = 3000, .vMin = 0, .exit = new Range(30, 20)});
    
    //14.6 - too far left
    //14.9 - too far left (maybe)
    Pt blueStake = {15.4, 130};
    chass.turnTo(blueStake, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.mtpoint(blueStake, {.timeout = 2000, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17, .within = 14.5});
    lift.toggle();
    redirect.toggle();

    chass.mtpoint({-9, 86}, {.timeout = 2000, .vMin = 30, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17, .within = 14.5});
    chass.driveAngle(-350, 135, { .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
    robot::intake.move(127);
    chass.mtpoint({16, 70}, {.timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17, .within = 14.5});
    pros::delay(900);
    chass.mtpoint({23, 34}, {.timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17, .within = 14.5});
    chass.driveAngle(1800, 135, { .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    chass.turn(neg(45), {.timeout=3000, .exit = new Range(15, 30)});
    chass.driveAngle(-1200, neg(45), { .timeout = 3000, .vMin = 0, .exit = new Range(20, 40)});
    clamp::tilt();
}