#include "constants.hpp"
#include "../lift/states.h"
using namespace robot;

void skills() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    
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
    
    Pt ring2 = {30.4, -61.58};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    
    Pt ring3 = {22.04, -44.33};
    chass.turnTo(ring3, {.timeout = 1000, .exit = new Range(6, 20)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring4 = {23.04, 2.83};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt ring5 = {37,-14};
    chass.turnTo(ring5, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    chass.driveAngle(-780, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    chass.driveAngle(100, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    pros::delay(300);
    clamp.toggle();
    pros::delay(200);
    
    Pt ring6 = {24.2, -87};
    chass.setMTP(_chassLin, _chassAngBig);
    chass.mtpoint(ring6, {.async = false, .timeout = 1600, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    chass.setMTP(_chassLin, _chassAng);
    lb.next();
    // chass.waitUntilSettled();
    
    // Pt ring7 = {30, -115};
    // chass.mtpoint(ring7, {.async = true, .timeout = 1600, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    // pros::delay(300);
    // lb.next();
    // chass.waitUntilSettled();
    
    Pt wallPrime1 = {24, -65.31};
    chass.mtpoint(wallPrime1, {.async = false, .timeout = 1600, .vMin = 30, .settleRange = 10, .exit = new Range(10, 10), .drift = 9});
    chass.driveAngle(-600,90, { .timeout = 600, .exit = new Range(40, 20)});
    Pt wallStake = {40, -65};
    chass.turnTo(wallStake, {.timeout = 600, .exit = new Range(5, 30)});
    pros::delay(500);
    intake.move(0);
    chass.waitUntilSettled();
    
    
    lb.next();
    lb.next();
    chass.moveWithin(wallStake, 4, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(400);
    
    Pt lerp7 = {15, -114};
    chass.mtpoint(lerp7, {.async = true, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10)});
    pros::delay(300);
    lb.setState(lift::Idle::getInstance());
    
    Pt ring7 = {21, -114};
    chass.turnTo(ring7, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring7, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    chass.setLin(_linSmall);
    chass.driveAngle(-900, 30, {.timeout = 1000, .exit = new Range(10, 10), .slew=1});
    chass.setLin(_lin);
    clamp.toggle();
    
    Pt ring8 = {21, -128};
    lb.next();
    chass.mtpoint(ring8, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    chass.turn(neg(80), {.timeout = 700, .exit = new Range(2, 20)});
    
    chass.driveAngle(-800, neg(80), { .timeout = 600, .exit = new Range(40, 20)});
    clamp.toggle();
    
    Pt goal2 = {2, -128};
    chass.turn(0, {.timeout = 150, .exit = new Range(3, 20)});
    chass.turn(100, {.timeout = 300, .exit = new Range(3, 20)});
    chass.mtpoint(goal2, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    chass.driveAngle(-800, 90, { .timeout = 600, .exit = new Range(40, 20)});
    clamp.toggle();
    lb.next();
    lb.next();

    Pt blueAS = {-29, -128};
    chass.turnTo(redAS, {.timeout = 600, .exit = new Range(3, 30)});
    chass.moveWithin(redAS, 10.9, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
}