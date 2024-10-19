#include "constants.hpp"
#include "funcs.hpp"
#include "keejLib/util.h"

void bposNew() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    //30
    // chass.turnTo({-65.0, 29.0}, {.timeout=900, .exit = new Range(2, 80)});
    // return;
    
    //move to goal straight
    chass.setAng(_angBig);
    prosController.print(0,0, "%f", imu.get_heading());
    chass.moveWithin({-3.0, -20.6}, 0, {.timeout = 1500, .vMin=0, .exit = new Range(5, 100), .reverse=true, .slew = 1.8, }, 9.5);
    //turn to face goal and grab
    chass.driveAngle(-840, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(120, 5), .slew = 2});
    clamp::clamp();
    chass.driveAngle(-840, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(29, 5)}, true);
    chass.setAng(_ang);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    clamp::tilt();
    pros::delay(250);
    robot::intake.move(127);
    chass.waitUntilSettled();
    pros::delay(200);
    chass.turn(neg(45), {.timeout=900, .exit = new Range(4, 20)});
    redirect.toggle();
    chass.setAng(_angBig);
    chass.driveAngle(400, neg(45), {.timeout=550, .exit = new Range(20, 50)});
    chass.setAng(_ang);
    chass.driveAngle(-300, neg(45), {.timeout=500, .exit = new Range(20, 50)});
    chass.turn(neg(150), {.timeout = 300, .exit = new Range(30, 10)});
    chass.mtpoint({-9.6, 13.3}, {.async = true, .timeout = 1400, .vMin = 20, .settleRange = 9, .exit = new exit::Range(10, 50), .drift = 20});
    clamp::tilt();
    pros::delay(300);
    // clamp::clamp();
    lift.switchState();
    chass.turn(130, {.timeout = 300, .exit = new Range(10, 20)});
    chass.driveAngle(-400, 130, {.timeout=300, .exit = new Range(40, 20)});
    clamp::clamp();
    // chass.driveAngle(-400, , {.timeout=370, .exit = new Range(40, 20)}, true);
// chass.moveWithin({-12.43, 16.66}, 0, {.timeout=2100, .exit = new Range(3, 100)}, neg(135));
//14, 16.66
chass.mtpoint({-5.0, 13.0}, {.async = false, .timeout = 600, .vMin = 0, .settleRange = 6, .exit = new exit::Range(3, 30), .drift = 10});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();


chass.turn(45, {.timeout=700, .exit = new Range(4, 30)});
    chass.driveAngle(900, 45, {.async = true, .timeout = 600, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(550);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    
    chass.driveAngle(-400, 45, {.timeout = 500, .vMin = 0, .exit = new Range(20, 40)});
    
    //13, -18
    stopOnColor();
    // chass.driveAngle(-850, 73, {.async = true, .timeout = 1000, .vMin = 38, .exit = new Range(80, 10)});
    chass.waitUntilSettled();
    // lift.toggle();
    robot::redirect.toggle();
    // chass.mtpoint({-6.5, -21.0}, {.async = false, .timeout = 2000, .vMin = 25, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 20, .within=0});
    //         chass.mtpoint({4.0, -18.0}, {.async = false, .timeout = 2000, .vMin = 35, .settleRange = 9, .exit = new exit::Range(50, 10), .drift = 6, .within=0});
    //31
    //33.4, -5.3
    //33.2
    //33.1
        // chass.mtpoint({-33.3, -5.3}, {.async = false, .timeout = 2000, .vMin = 15, .settleRange = 9, .exit = new exit::Range(5, 50), .drift = 6, .within=0});
        // 16
        // 19
        // 26
        // 30
        // 25
        // 26
        // 25.8
        chass.mtpoint({-26.8, 2.0}, {.async = false, .timeout = 2000, .vMin = 0, .settleRange = 9, .exit = new exit::Range(5, 50), .drift = 6, .within=0});
    
    // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    // 
    chass.turn(30, {.timeout = 300, .exit = new Range(3, 40)});
    robot::intake.move(-30);
    chass.driveAngle(-1200, 30, {.async = true, .timeout = 1000, .vMin = 0, .exit = new Range(80, 10),.slew = 1.8});
    pros::delay(300);
    robot::intake.move(0);
    chass.waitUntilSettled();
    clamp::clamp();
    chass.driveAngle(-1200, 30, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(30, 5)}, true);
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
    //63.5 (right)
    //64.5 (right)
    // Pt allianceStake = {-64.0, 29.0};
    // 61.9
    // 62.5
    // 62.9 LEFT
    // 62.3 LEFT
    Pt allianceStake = {-62.7, 29.0};
    chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(2, 80)});
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

    //13.9
    chass.moveWithin(allianceStake, 14.5, {.timeout=2100, .exit = new Range(5, 100)});
    //66,30
    chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(2, 80)});
    lift.toggle();
    pros::delay(390);
    spitColor();

    chass.driveAngle(-1580, neg(20), {.async = false, .timeout = 1500, .vMin = 38, .exit = new Range(80, 10)});
    chass.driveAngle(-1250, 45, {.async = false, .timeout = 880, .vMin = 0, .exit = new Range(20, 10)});
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