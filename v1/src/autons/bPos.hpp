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
    //-20
    //-20.3
    chass.moveWithin({-3.0, -21.3}, 0, {.timeout = 1500, .vMin=0, .exit = new Range(5, 100), .reverse=true, .slew = 2, }, 8.9);
    //turn to face goal and grab
    chass.driveAngle(-750, 30, {.async = false, .timeout = 3000, .vMin = 0, .exit = new Range(80, 5)});
    clamp::clamp();
    //800
    chass.driveAngle(-750, 30, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(39, 5)}, true);
    chass.setAng(_ang);
    chass.driveAngle(550, 30, {.async = true, .timeout = 700, .vMin = 0, .exit = new Range(20, 40)});
    pros::delay(290);
    clamp::tilt();
    pros::delay(250);
    robot::intake.move(127);
    chass.waitUntilSettled();
    
    pros::delay(200);
    chass.turn(neg(55), {.timeout=900, .exit = new Range(4, 20)});
    redirect.toggle();
    clamp::tilt();
    chass.setAng(_angBig);
    chass.driveAngle(400, neg(55), {.timeout=550, .exit = new Range(20, 50)});
    chass.setAng(_ang);
    chass.driveAngle(-300, neg(55), {.timeout=500, .exit = new Range(20, 50)});
    
    chass.turn(neg(140), {.timeout = 700, .exit = new Range(10, 30)});
    chass.mtpoint({-10.3, 13.3}, {.async = true, .timeout = 1400, .vMin = 20, .settleRange = 9, .exit = new exit::Range(5, 50), .drift = 20});
    // clamp::tilt();
    pros::delay(700);
    // clamp::clamp();
    lift.switchState();
    chass.waitUntilSettled();
    chass.turn(130, {.timeout = 300, .exit = new Range(10, 20)});
    chass.driveAngle(-400, 130, {.timeout=300, .exit = new Range(40, 20)});
    clamp::clamp();
    // chass.driveAngle(-400, , {.timeout=370, .exit = new Range(40, 20)}, true);
// chass.moveWithin({-12.43, 16.66}, 0, {.timeout=2100, .exit = new Range(3, 100)}, neg(135));
//14, 16.66
//-5
//-4.5
// -6.5
chass.mtpoint({-8.8, 13.0}, {.async = false, .timeout = 600, .vMin = 0, .settleRange = 6, .exit = new exit::Range(3, 30), .drift = 10});
    robot::intake.move(-127);
    // chass.turnTo(Pt target, MotionParams params)
    tsukasa.toggle();


chass.turn(45, {.timeout=550, .exit = new Range(4, 30)});
    chass.driveAngle(900, 45, {.async = true, .timeout = 600, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(550);
    robot::intake.move(127);
    robot::tsukasa.toggle();
    chass.waitUntilSettled();
    pros::delay(200);
    
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
        // 26.8 RIGHT
        // 26 LEFT
        // 28.4
        chass.mtpoint({-28.3, 2.0}, {.async = false, .timeout = 2000, .vMin = 0, .settleRange = 9, .exit = new exit::Range(5, 50), .drift = 6, .within=0});
    
    // chass.mtpoint({-10.0, -29.0}, {.async = false, .timeout = 2000, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 20, .within=0});
    // 
    chass.turn(30, {.timeout = 200, .exit = new Range(3, 40)});
    robot::intake.move(-30);
    chass.driveAngle(-900, 30, {.async = true, .timeout = 800, .vMin = 0, .exit = new Range(80, 10),.slew = 0.01});
    pros::delay(300);
    robot::intake.move(0);
    chass.waitUntilSettled();
    clamp::clamp();
    chass.driveAngle(-900, 30, {.async = false, .timeout = 360, .vMin = 0, .exit = new Range(30, 5)}, true);
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
    // 62.9 RIGHT
    // 62.3 RIGHT
    // 59 LEFT
    // 59.7 LEFT
    // -61 LEFT
    // -63.5
    //-61.8
    //62.3 LEFT
    //65 LEFT
    Pt allianceStake = {-65.3, 29.0};
    chass.turnTo(allianceStake, {.timeout=600, .exit = new Range(2, 80)});
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
    
    //14.1 close!
    //13.8 too far
    //13.6 TOO FAR
    //12.8
    //10 TOO FAR
    //9.5 CLOSE
    //10.2 CLOSE
    chass.moveWithin(allianceStake, 13.7, {.timeout=2100, .exit = new Range(5, 100)});
    //66,30
    chass.turnTo(allianceStake, {.timeout=900, .exit = new Range(2, 80)});
    lift.toggle();
    pros::delay(390);
    spitColor();

    chass.driveAngle(-1580, neg(20), {.async = false, .timeout = 700, .vMin = 38, .exit = new Range(80, 10)});
    robot::tsukasa.toggle();
    chass.driveAngle(-1400, 45, {.async = false, .timeout = 680, .vMin = 0, .exit = new Range(20, 10)});
    redirect.toggle();
    
    chass.mtpoint({8, -40}, {.timeout = 1300, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turn(neg(3), {.timeout = 700, .exit = new Range(5, 100)});
    // {-10.43, 13.3};
}
// void posBlueElims() {
//     rpos();
//     keejLib::Stopwatch t1;
//     int time = std::max(300,15000 - t1.elapsed() - 100);
//     chass.mtpoint({8.0, -40.0}, {.timeout = time, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
//     chass.turnTo({20.0, -90.0}, {.timeout=900, .exit = new Range(0.5, 200), .reverse = true});
// }