#include "constants.hpp"
#include "../lift/states.h"
#include "pros/rtos.hpp"
using namespace robot;

void goal1() {
    lb.next();
    lb.next();
    chass.setLin(_linBigger);
    chass.driveAngle(-210, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(40, 20)});
    // chass.useAlternateOffsets(true);
    clamp.toggle();
    intake.move(127);
    
    Pt redAS = {-25.5, 6.5};
    chass.turnTo(redAS, {.timeout = 600, .exit = new Range(3, 30)});
    intake.move(0);
    lb.next();
    lb.next();
    lb.next();
    //10.9 < x
    chass.moveWithin(redAS, 13.8, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(490);
    chass.driveAngle(-500, neg(45), {.async = true, .timeout = 600, .exit = new Range(20, 20)});
    pros::delay(200);
    lb.next();
    chass.waitUntilSettled();
    intake.move(127);
    chass.setLin(_lin);
    
    Pt ring1 = {-3.3, -38};
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(4, 30)});
    // chass.turnTo(ring1, {.timeout = 700, .exit = new Range(1, 30)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 20, .settleRange = 2,  .exit = new Range(5, 10), .drift = 8});
    
    Pt ring2 = {25.9, -62.58};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    pros::delay(300);
    
    Pt ring3 = {23.8, -44.33};
    chass.turnTo(ring3, {.timeout = 1000, .exit = new Range(6, 20)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 5});
    
    Pt ring4 = {23.8, 2.83};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 5});
    pros::delay(700);
    
    Pt ring5 = {36,-14};
    chass.turnTo(ring5, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt corner = {38, -3};
    chass.driveAngle(-300, neg(170), { .timeout = 200, .exit = new Range(40, 20)});
    chass.mtpoint(corner, {.timeout = 700, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    // chass.driveAngle(-780, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    chass.driveAngle(100, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    pros::delay(300);
    clamp.toggle();
    // chass.useAlternateOffsets(false);
    pros::delay(200);
    intake.move(127);
}

void wall1() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);

    Pt ring1 = {23, -85};
    chass.setMTP(_chassLin, _chassAngBig);
    chass.mtpoint(ring1, {.async = true, .timeout = 1600, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    pros::delay(250);
    intake.move(127);
    chass.waitUntilSettled();
    chass.setMTP(_chassLin, _chassAng);
    lb.next();
    chass.waitUntilSettled();
    pros::delay(900);
    
    //30 < x
    Pt ring2 = {33, -117};
    chass.setMTP(_chassLin, _chassAngBig);
    chass.mtpoint(ring2, {.async = true, .timeout = 1600, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    chass.setMTP(_chassLin, _chassAng);
    pros::delay(300);
    intake.move(-30);
    lb.next();
    pros::delay(300);
    intake.move(127);
    pros::delay(300);
    // chass.waitUntilSettled();
    
    Pt prime = {24, -76.31};
    // chass.turnTo(prime, {.timeout = 600, .exit = new Range(6, 30)});
    chass.mtpoint(prime, {.async = false, .timeout = 1600, .vMin = 100, .settleRange = 10, .exit = new Range(10, 10), .drift = 9});

    chass.driveAngle(-600,90.1, { .timeout = 600, .exit = new Range(300, 20)});
    
    //68 > x
    //67 > x (barely)
    //66 > x
    //64.8 < x ?
    // Pt stake = {38, -64.95};
    // x < -65.85 
    Pt stake = {38, -66.1};
    chass.setTurn(_ttp);
    chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    chass.setTurn(_90);
    intake.move(-10);
    chass.waitUntilSettled();
    
    
    lb.next();
    chass.moveWithin(stake, 5.1, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
    lb.next();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.setLin(_lin);

}

void corner1() {
    chass.driveAngle(-300, 80, { .timeout = 1000, .vMin = 60, .exit = new Range(20 , 20)});
    Pt lerp = {3, -105};
    chass.mtpoint(lerp, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    lb.setState(lift::One::getInstance());
    
    Pt ring1 = {16, -116};
    intake.move(127);
    chass.turnTo(ring1, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    Pt goal = {1, -118};
    // chass.setLin(_linBigger);
    chass.mtpoint(goal, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    chass.driveAngle(-700, 30, {.timeout = 1000, .exit = new Range(30, 10), .slew=1});
    // chass.setLin(_lin);
    // chass.useAlternateOffsets(true);
    clamp.toggle();
    chass.turn(130, {.async = true, .timeout = 400, .exit = new Range(10, 20)});
    intake.move(0);
    pros::delay(200);
    lb.next();
    
    chass.setLin(_linBigger);
    chass.driveAngle(400, 130, {.timeout = 400, .exit = new Range(10, 10)});
    chass.setLin(_lin);
    Pt ring2 = {18, -130};
    // chass.turnTo(ring2, {.timeout = 700, .exit = new Range(10, 20)});
    intake.move(127);
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    //place
    // chass.driveAngle(-500, 170, { .timeout = 900, .exit = new Range(40, 20)});
    // doink.toggle();
    // chass.driveAngle(500, 140, { .timeout = 900, .exit = new Range(40, 20)});
    chass.turn(neg(30), {.timeout = 200, .exit = new Range(3, 20)});
    chass.turn(neg(60), {.timeout = 500, .exit = new Range(5, 20)});
    // doink.toggle();
    // chass.mtpoint(goal2, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    clamp.toggle();
    // chass.useAlternateOffsets(false);
    tsukasa.toggle();
    pros::delay(250);
    chass.driveAngle(-1200, neg(60), { .timeout = 900, .exit = new Range(40, 20)});
    Pt prime = {-15, -124};
    chass.mtpoint(prime, {.timeout = 1400, .vMin = 10, .settleRange = 6, .exit = new Range(5, 80), .drift = 9});

    intake.move(0);
    lb.next();
    lb.next();

    //36 > x
    //33 > x
    //20 < x
    //23 < x
    // 27 > x ?
    // 25 < x
    // 32.8
    // -29.8 < x
    // x < -29.1
    // x < -29.4
    Pt blueAS = {-29.8, -138.8};
    chass.turnTo(blueAS, {.timeout = 600, .exit = new Range(2, 100)});
    //11.9 < x
    chass.moveWithin(blueAS, 12.8, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    lb.next();
    pros::delay(300);
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    lb.next();
    intake.move(127);
    chass.driveAngle(-700, neg(145), { .timeout = 800, .exit = new Range(10, 20)});
    
    // -5< x
    // -113 > x
    // -4 > x
    Pt goalPrime = {-9 , -114};
    // chass.mtpoint(goalPrime, {.async = false, .timeout = 1200, .vMin = 0, .settleRange = 3, .exit = new Range(3, 90),.drift = 5 });
    // pros::delay(400);
    chass.waitUntilSettled();
    chass.turn(90, {.timeout = 600, .exit = new Range(2, 100)});
    chass.driveAngle(-1000, 90, {.timeout = 1000, .exit = new Range(20, 100), .slew=0.01});
    // chass.setLin(_lin);


    // lb.next();
}

void goal2() {
    clamp.toggle();
    // chass.useAlternateOffsets(true);
    intake.move(127);
    tsukasa.setState(false);
    Pt ring1 = {-4, -92};
    chass.mtpoint(ring1, {.timeout = 1400, .vMin = 0, .settleRange = 9, .exit = new Range(8, 50) });
    chass.turn(neg(43), {.timeout = 500, .exit = new Range(0.5, 500)});
    intake.move(0);
    Pt ring2 = {-27, -64};
    chass.mtpoint(ring2, {.async = true, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    pros::delay(800);
    intake.move(127);
    pros::delay(400);
    intake.move(0);


    Pt ring3 = {-51, -38};
    chass.mtpoint(ring3, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) });
    intake.move(127);

    // Pt ring4 = {-80, -18};
    Pt ring4 = {-77, -13};
    chass.mtpoint(ring4, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) , .drift = 8});

    Pt ring5 = {-99, -14};
    chass.turnTo(ring5, {.timeout = 600, .exit = new Range(2, 30)});
    chass.driveAngle(800, imu.get_heading(), {.timeout = 600, .exit = new Range(60, 30)});
    // chass.mtpoint(ring5, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    // pros::delay(600);
    
    Pt ring6 = {-80, -3};
    chass.turnTo(ring6, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring6, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    
    Pt corner = {-90, -1};
    chass.turn(neg(80), {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(corner, {.timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(2, 14) });
    pros::delay(400);
    clamp.toggle();
}

void goal3() {
    Pt prime = {-77.37, -12.85};
    chass.mtpoint(prime, {.async = false, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    chass.turn(neg(90), {.timeout = 600, .exit = new Range(2, 30)});
    chass.driveAngle(-1000, 90, {.timeout = 1000, .exit = new Range(20, 10), .slew=0.04});
    clamp.toggle();
    
    Pt ring1 = {-80, -37};
    lb.next();
    chass.mtpoint(ring1, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    
    Pt ring2 = {-92, -64};
    chass.mtpoint(ring2, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    intake.move(0);
    lb.next();
    
    Pt stake = {-40, -65.85};
    chass.setTurn(_ttp);
    pros::delay(300);
    intake.move(127);
    chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    intake.move(0);
    lb.next();
    chass.setTurn(_90);
    chass.waitUntilSettled();
    
    
    lb.next();
    chass.moveWithin(stake, 4.1, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
    lb.next();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.setLin(_lin);

}
void skills() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);

    
    goal1();
    wall1();
    corner1();
    goal2();
    goal3();
    
}