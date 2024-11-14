#include "constants.hpp"
#include "../lift/states.h"
#include "pros/rtos.hpp"
using namespace robot;

void goal1() {
    lb.next();
    lb.next();
    chass.setLin(_linBigger);
    chass.driveAngle(-210, 0, {.async = false, .timeout = 400, .vMin = 0, .exit = new Range(40, 20)});
    clamp.toggle();
    
    Pt redAS = {-25.5, 6.5};
    chass.turnTo(redAS, {.timeout = 600, .exit = new Range(3, 30)});
    chass.moveWithin(redAS, 10.9, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(250);
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
    
    Pt ring2 = {29.5, -61.58};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    
    Pt ring3 = {23.04, -44.33};
    chass.turnTo(ring3, {.timeout = 1000, .exit = new Range(6, 20)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring4 = {23.04, 2.83};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring5 = {36,-14};
    chass.turnTo(ring5, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    chass.driveAngle(-780, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    chass.driveAngle(100, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    pros::delay(300);
    clamp.toggle();
    pros::delay(200);
}

void wall1() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);

    intake.move(127);
    Pt ring1 = {23, -87};
    chass.setMTP(_chassLin, _chassAngBig);
    chass.mtpoint(ring1, {.async = false, .timeout = 1600, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    chass.setMTP(_chassLin, _chassAng);
    lb.next();
    chass.waitUntilSettled();
    pros::delay(900);
    
    //30 < x
    Pt ring2 = {33, -115};
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
    Pt stake = {38, -64.95};
    chass.setTurn(_ttp);
    chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    chass.setTurn(_90);
    intake.move(-10);
    chass.waitUntilSettled();
    
    
    lb.next();
    chass.moveWithin(stake, 4.8, {.timeout = 1500, .vMin=0, .exit = new Range(3, 10)});
    lb.next();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.setLin(_lin);

}

void corner1() {
    chass.driveAngle(-100, 80, { .timeout = 800, .vMin = 70, .exit = new Range(20 , 20)});
    lb.setState(lift::One::getInstance());
    Pt lerp = {3, -105};
    chass.mtpoint(lerp, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring1 = {16, -116};
    intake.move(127);
    chass.turnTo(ring1, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    Pt goal = {1, -118};
    // chass.setLin(_linBigger);
    chass.mtpoint(goal, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    chass.driveAngle(-700, 30, {.timeout = 1000, .exit = new Range(30, 10), .slew=1});
    // chass.setLin(_lin);
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
    tsukasa.toggle();
    pros::delay(250);
    chass.driveAngle(-1200, neg(60), { .timeout = 900, .exit = new Range(40, 20)});
    Pt prime = {-11, -129};
    chass.mtpoint(prime, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 11});

    intake.move(0);
    lb.next();
    lb.next();

    //36 > x
    //33 > x
    //20 < x
    //23 < x
    // 27 > x ?
    // 25 < x
    Pt blueAS = {-26.8, -138.8};
    chass.turnTo(blueAS, {.timeout = 600, .exit = new Range(2, 100)});
    chass.moveWithin(blueAS, 10.72, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(500);
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    lb.next();
    
    // -5< x
    // -113 > x
    Pt goalPrime = {-4, -117};
    chass.mtpoint(goalPrime, {.timeout = 1200, .vMin = 0, .settleRange = 3, .exit = new Range(3, 90),.drift = 5 });
    chass.turn(90, {.timeout = 600, .exit = new Range(2, 100)});
    chass.driveAngle(-900, 90, {.timeout = 1000, .exit = new Range(20, 10), .slew=0.07});
    // chass.setLin(_lin);
    clamp.toggle();


    // lb.next();
}

void goal2() {
    intake.move(127);
    tsukasa.toggle();
    Pt ring1 = {-1, -92};
    chass.mtpoint(ring1, {.timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 100) });
    pros::delay(500);
    Pt ring2 = {-27, -62};
    chass.mtpoint(ring2, {.async = true, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    pros::delay(800);
    intake.move(127);
    pros::delay(700);
    intake.move(0);



    Pt ring3 = {-49, -37};
    chass.mtpoint(ring3, {.async = true, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) });
    pros::delay(500);
    intake.move(127);

    Pt ring4 = {-71, -13};
    chass.mtpoint(ring4, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) });

    Pt ring5 = {-85, -13};
    chass.turnTo(ring5, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring5, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) });
    pros::delay(600);
    
    Pt ring6 = {-68, -13};
    chass.turnTo(ring6, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring6, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) });
    
    chass.driveAngle(-700, neg(80), {.timeout = 800, .vMin = 0, .settleRange = 5, .exit = new Range(20, 10) });
    



}
void skills() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);

    
    // goal1();
    // wall1();
    corner1();
    goal2();
    
}