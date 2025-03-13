#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include <functional>
using namespace robot;

void init() {
        chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);
    intake.setAutoLift(false);
    // intake.setJamProtection(false);
}
void allianceStake() {
    intake.setColor(none);
    // lb.next();
    chass.setLin(_linBigger);
    chass.driveAngle(-300, 0, {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(40, 20), .slew = 3});
    // chass.useAlternateOffsets(true);
    clamp.toggle();
    pros::delay(100);
    // intake.move(127);
    
    // Pt redAS = {-25.7, 6.7};
    //from circle regression
    // Pt redAS = {-25.956166554408174, 7.077167481154157};
    Pt redAS = {-25.8, 5.6};
    chass.turnTo(redAS, {.timeout = 600, .exit = new Range(3, 30)});
    intake.move(0);
    lb.next();
    lb.next();
    lb.next();
    //10.9 < x
    chass.moveWithin(redAS,  13.6, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    pros::delay(790);
    chass.driveAngle(-500, neg(45), { .timeout = 500, .exit = new Range(90, 20)});
    lb.setState(LiftState::idle);
}

void goal1() {
    chass.setLin(_lin);
    
    Pt ring1 = {-3.9, -38};
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(4, 30)});
    intake.move(127);
    // chass.turnTo(ring1, {.timeout = 700, .exit = new Range(1, 30)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 20, .settleRange = 2,  .exit = new Range(5, 10), .drift = 8});
    
    // Pt ring2 = {26.3, -62.58};
    //32.3
    Pt ring2 = {31.3, -64};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    chass.driveAngle(-500, 70, {.timeout = 400, .exit = new Range(100, 10)});
    pros::delay(150);
    
    Pt ring3 = {20.8, -44.33};
    chass.turnTo(ring3, {.timeout = 500, .exit = new Range(10, 15)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 5});
    pros::delay(400);
    
    //24.7
    Pt ring4 = {23.1, -2};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 2});
    // pros::delay(500);
    
    Pt ring5 = {38.7,-14.8};
    chass.turnTo(ring5, {.timeout = 700, .vMax = 50, .exit = new Range(10, 20)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt corner = {38, 0};
    chass.driveAngle(-300, neg(170), { .timeout = 200, .exit = new Range(40, 20)});
    chass.mtpoint(corner, {.timeout = 700, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    // chass.driveAngle(-780, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    // chass.driveAngle(100, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    clamp.toggle();
    pros::delay(280);
    // chass.turn(180, {.timeout = 500, .exit = new Range(1, 50)});
    // chass.wallReset(2, 10);
    // chass.useAlternateOffsets(false);
    intake.move(127);
}

void wall1() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);

    Pt ring1 = {22.1, -89.5};
    chass.setMTP(_chassLin, _chassAngBig);
    chass.mtpoint(ring1, {.async = true, .timeout = 1600, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 9, .slew=0,});
    pros::delay(250);
    intake.move(127);
    pros::delay(1200);
    lb.next();
    chass.waitUntilSettled();
    chass.setMTP(_chassLin, _chassAng);
    chass.waitUntilSettled();
    pros::delay(250);
    chass.driveAngle(500, 135, {.timeout = 700, .vMin = 27, .exit = new Range(20, 20)});
    // pros::delay(900);
    
    //30 < x
    //was 32 10:12
    //WAS 31.5
    Pt ring2 = {32.5, -115.6};
    chass.setMTP(_chassLin, _chassAng);
    chass.mtpoint(ring2, {.async = true, .timeout = 1600, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    pros::delay(50);
    intake.move(-5);
    lb.next();
    pros::delay(140);
    intake.move(127);
    pros::delay(300);
    // chass.waitUntilSettled();
    
    // Pt prime = {20, -82};
    Pt prime = {25, -65.39};

    // chass.turnTo(prime, {.timeout = 600, .exit = new Range(6, 30)});
    chass.mtpoint(prime, {.async = false, .timeout = 1500, .drift = 5, .slew = 2,});
    
    // chass.driveAngle(600,90.1, { .timeout = 600, .vMin = 30, .exit = new Range(50, 20)});

    
    //68 > x
    //67 > x (barely)
    //66 > x
    //64.8 < x ?
    // Pt stake = {38, -64.95};
    // x < -65.85 
    Pt stake = {43.6, -63.8};
    chass.turnTo(stake, {.timeout = 500});
    intake.move(0);
    lb.next();
    chass.mtpoint(stake, {.timeout = 800, .drift = 2.5, .within = 3.6});

    // chass.setTurn(_ttp);
    // chass.turnTo(stake, {.timeout = 700, .exit = new Range(1, 200)});
    // chass.setTurn(_90);
    // intake.move(-10);
    // chass.waitUntilSettled();
    
    
    // lb.next();
    // //5.0 > x
    // chass.moveWithin(stake, 4.6, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
    lb.next();
    // lb.next();
    chass.driveAngle(400, imu.get_heading(), {.async = false, .timeout = 500, .exit = new Range(10, 20)});

    // chass.driveAngle(-300, imu.get_heading(), { .timeout = 300, .exit = new Range(10, 20)});
    // chass.driveAngle(800, imu.get_heading(), { .timeout = 400, .exit = new Range(10, 20)});
    chass.setLin(_lin);

}

void corner1() {
    chass.driveAngle(-400, 80, { .timeout = 1000, .vMin = 60, .exit = new Range(20 , 20)});
    lb.prev();
    //was -112
    Pt lerp = {3, -108};
    chass.mtpoint(lerp, {.async = false, .timeout = 1200, .vMin = 15, .settleRange = 10, .exit = new Range(8, 10), .drift = 9});
    
    Pt ring1 = {19.4, -117.1};
    intake.move(127);
    lb.setState(LiftState::one);
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(15, 20)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    Pt goal = {1.5, -122.5};
    // chass.setLin(_linBigger);
    chass.mtpoint(goal, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 8});
    chass.driveAngle(-700, 55, {.timeout = 700, .vMin = 30, .exit = new Range(30, 10), .slew=3});
    chass.setAng(_ang);
    // chass.setLin(_lin);
    // chass.useAlternateOffsets(true);
    clamp.toggle();
    pros::delay(150);
    chass.turn(100, {.async = true, .timeout = 300, .exit = new Range(10, 20)});
    intake.move(0);
    pros::delay(200);
    lb.next();
    
    Pt ring2 = {15.5, -132.5};
    // chass.turnTo(ring2, {.timeout = 700, .exit = new Range(10, 20)});
    // chass.mtpoint(ring2, {.async = true, .timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    chass.driveAngle(1080, 80, {.async = true, .timeout = 700});
    pros::delay(200);
    intake.move(127);
    chass.waitUntilSettled();
    //place
    // chass.driveAngle(-500, 170, { .timeout = 900, .exit = new Range(40, 20)});
    // doink.toggle();
    // chass.driveAngle(500, 140, { .timeout = 900, .exit = new Range(40, 20)});
    chass.turn(neg(25), {.timeout = 600, .exit = new Range(3, 20)});
    // chass.turn(neg(45), {.timeout = 500, .exit = new Range(5, 20)});
    // doink.toggle();
    // chass.mtpoint(goal2, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    clamp.toggle();
    pros::delay(300);

    /*
    pros::delay(300);
    // chass.useAlternateOffsets(false);
    chass.driveAngle(400, neg(45), { .timeout = 400, .exit = new Range(40, 20)});
    clamp.toggle();
    pros::delay(200);
    */

    chass.driveAngle(-1000, neg(45), { .timeout = 900, .slew = 5});
    chass.driveAngle(300, neg(90), {.timeout = 300});
    tsukasa.toggle();
    Pt prime = {-16.9, -126};
    // Pt pos = chass.getPose().pos;
    // double dist = pos.dist(prime);
    // 
    chass.setTurn(_5);
    chass.turn(neg(90),  {.timeout = 500, .exit = new Range(2, 230)});
    chass.setTurn(_5);

    intake.move(0);
    chass.wallReset(3, 10, false);
    // clamp.toggle();
    // chass.driveAngle(1700, neg(88), {.timeout = 1000, .exit = new Range(30, 20)});
    // chass.mtpoint({-16.5, -125}, {.timeout = 1200, .drift = 5});
    chass.waitUntilSettled();

    Pt goalPrime = {-9 , -114.1};
    chass.mtpoint(goalPrime, {.timeout = 1200, .drift = 8});
    //114.7
    Pt mogo = {-40, -115.5};
    // chass.setLin(_lin);
        chass.setTurn(_180);
        double ang = chass.turnTo(mogo, {.timeout = 700 , .exit = new Range(8, 20), .reverse = true});
        chass.setTurn(_90);
        intake.move(0);
    chass.setLin(_linSmall);
    chass.driveAngle(-1020, 90, {.timeout = 1000, .exit = new Range(200, 15), .slew=2.5});
    clamp.toggle();
    chass.driveAngle(-1020, 90, {.timeout = 300, .exit = new Range(50, 15)}, true);
    chass.setLin(_lin);
    


    
    // chass.turnTo(prime, {.timeout = 700, .vMin = 0, .exit = new Range(2, 15)});
    // chass.moveWithin(prime, 0, { .timeout = 1000, .exit = new Range(5, 10)});
    // 
    // 
    // 
    // chass.driveAngle(dist, imu.get_heading(), { .timeout = 900, .exit = new Range(20, 20)});
    // chass.mtpoint(prime, {.timeout = 1400, .vMin = 0, .settleRange = 4, .exit = new Range(4, 300), .drift = 5});
tsukasa.toggle();

    intake.move(0);

//-32.4
//31.1
    Pt blueAS = {-28.4, -137.9};
    ang = chass.turnTo(blueAS, {.timeout  = 800, .exit = new Range(2, 100)});
    chass.mtpoint(blueAS, {.timeout = 700, .vMax = 60, .within = 3});
    lb.next();
    lb.next();
    //-330 WORKS 100%
    chass.driveAngle(-340, imu.get_heading(), {.timeout = 700});

    lb.next();
    pros::delay(400);
    // chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(250, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-600, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    // lb.prev();
    pros::delay(100);
    intake.move(127);
    lb.setState(LiftState::idle);
    chass.turn(45, {.timeout = 630});

    // -5< x
    // -113 > x
    // -4 > x
    // chass.mtpoint(goalPrime, {.async = false, .timeout = 1200, .vMin = 0, .settleRange = 3, .exit = new Range(3, 90),.drift = 5 });
    // pros::delay(400);
    // chass.turn(90, {.timeout = 600, .exit = new Range(2, 100)});
    // -120 < x
    // chass.mtpoint(mogo, {.timeout = 1000, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10)});


    // lb.next();
}

void goal2() {
    // clamp.toggle();
    // chass.useAlternateOffsets(true);
    intake.move(127);
    tsukasa.setState(false);
    //was 1.4 11:17 video
    //was 2.4
    //was -3.9
    // Pt ring1 = {-6.9, -89};
    // 1.9
    Pt ring1 = {-1.9, -84.8};
    chass.mtpoint(ring1, {.timeout = 900, .drift = 10, .within = 9, });

    // chass.turnTo(ring1, {.timeout = 500, .exit = new Range(10, 20)});
    // chass.mtpoint(ring1, {.timeout = 1400, .vMin = 1, .settleRange = 5, .exit = new Range(8, 15) });
    // pros::delay(800);
        Pt ring2 = {-28.6, -63};
    // chass.turnTo(ring2, {.timeout = 500, .exit = new Range(10, 20)});
    // chass.driveAngle(300, 45, {.timeout = 400});
    chass.driveAngle(300, neg(5), {.vMin = 20, .exit = new Range(200, 20)});
    pros::delay(600);
    intake.move(0);
    chass.mtpoint(ring2, {.async = true, .timeout = 1400,  .drift = 8 });
    pros::delay(700);
    intake.move(90);
        intake.stopOnColor(keejLib::red, 500);
    pros::delay(700);
    // intake.move(127);
    // pros::delay(200);
    intake.move(0);

    Pt ring3 = {-51, -39};
    chass.mtpoint(ring3, {.async = true, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 7, .debug = false});
    chass.waitUntilSettled();
    intake.move(127);
    pros::delay(500);

    // Pt ring4 = {-80, -18};
    //was -77.9
    Pt ring4 = {-75.9, -11.3};
    chass.mtpoint(ring4, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(10, 10) , .drift = 4, .debug = false});

    Pt ring5 = {-90.6, -10};
    // double angle = chass.turnTo(ring5, {.timeout = 600, .exit = new Range(5, 10)});
    // chass.driveAngle(1000, angle, {.timeout = 600, .exit = new Range(60, 30)});
    chass.mtpoint(ring5, {.timeout = 1100, .vMin = 0, .settleRange = 5,.exit = new Range(3, 14),  .drift = 5,  });
    // pros::delay(600);
    
    Pt ring6 = {-77, 4};
    // chass.turnTo(ring6, {.timeout = 600, .exit = new Range(2, 30)});
    chass.driveAngle(-330, 10, {.timeout = 500, .vMax = 50});
    // chass.turn(20, {.timeout = 600, .exit = new Range(2, 30)});
    // pros::delay(100);
    chass.mtpoint(ring6, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });

    
    //-86, 14
    Pt corner = {-90, 8};
    chass.turn(130, {.timeout = 600, .exit = new Range(4, 30)});
    chass.mtpoint(corner, {.timeout = 800, .vMin = 0, .settleRange = 5, .exit = new Range(4, 14) });
    clamp.toggle();
    pros::delay(180);
    chass.setAng(_angBig);
    chass.driveAngle(400, 90, {.timeout = 400});
    chass.setAng(_ang);
    chass.wallReset(1, 10, false);
    intake.stopOnColor(red, 1300);
}

void goal3() {
    //-12.6 > x
    Pt prime = {-77.37, -11.8};
    chass.mtpoint(prime, {.async = false, .timeout = 1400, .vMin = 20, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    
    //-15.1
    //14.6
    //13.6
    Pt goal = {-57, -13.1};
    chass.setTurn(_180);
    double ang = chass.turnTo(goal, {.timeout = 630, .exit = new Range(2, 30), .reverse = true});
    chass.setTurn(_90);
    chass.setLin(_linSmall);
    intake.move(0);
    chass.driveAngle(-1300, ang, {.timeout = 1000, .vMax = 60,.exit = new Range(100, 10),  .slew=5});
    clamp.toggle();
    intake.move(127);
    chass.driveAngle(-1300, ang, {.timeout = 400, .exit = new Range(15, 10), .slew=5}, true);
    chass.setLin(_lin);

    Pt ring1 = {-76.5, -36};
    lb.next();
    intake.move(127);
    chass.mtpoint(ring1, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    pros::delay(800);
    intake.move(0);
    intake.setJamProtection(false);
    lb.next();
    lb.next();
    
    Pt ring2 = {-92, -66.4};
    chass.mtpoint(ring2, {.async = true, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(10, 10), .drift = 5 });
    pros::delay(400);
    intake.setJamProtection(true);
    intake.move(127);
    chass.waitUntilSettled();
    // chass.driveAngle(-700, neg(120), {.timeout = 700, .exit = new Range(20, 10)});
    //-68.85 < c
    //-67 < y
    //-66.5 < y
    // Pt stake = {-98, -65.5};
    // Pt stake = {-98, -65.5};
    //was 62
    // chass.driveAngle(-400, neg(135), {});
Pt stake = {-106, -62.2};
    // chass.setTurn(_ttp);
    // chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    // chass.setTurn(_90);
    // chass.waitUntilSettled();
    
    
    // chass.moveWithin(stake, 3.5, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
    chass.driveAngle(-300, neg(135), {.vMin = 30, .exit = new Range(90, 10)});
    // chass.turnTo(stake, {.timeout = 370});
    chass.mtpoint(stake, {.timeout = 700, .exit = new Timeout(1000), .drift = 2.5,  .within = 4.6});

    lb.next();
    chass.driveAngle(400, imu.get_heading(), {.timeout = 300});
    // chass.driveAngle(-200, imu.get_heading(), {.timeout = 200});
    chass.setLin(_linBigger);
    chass.setLin(_lin);
}

void corner4() {
    intake.setColor(none);
    Pt ring1 = {-77, -91.3};
    chass.driveAngle(-600, neg(90), {.timeout = 570, .vMin = 20, .exit = new Range(20, 10)});
    intake.move(127);
    lb.setState(LiftState::idle);
    chass.driveAngle(300, 200, {.timeout = 500, .vMin = 20, .exit = new Range(20, 10)});
    chass.mtpoint(ring1, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(4, 14), .within = 4});
    
    Pt ring2 = {-55, -87};
    chass.turnTo(ring2, {.timeout = 400, .exit = new Range(10, 30)});

    chass.mtpoint(ring2, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });

    chass.driveAngle(-1080, 90, {.timeout = 1100, .vMin = 80, .exit = new Range(100, 10)});
    // chass.setAng(_)
    chass.driveAngle(-600, 145, {.timeout = 1100, .vMin = 80, .exit = new Range(200, 10)});
    chass.driveAngle(-500, 190, {.timeout = 1100, .exit = new Range(200, 10)});
    //WAS -89

    /*
    Pt ring3 = {-76.01, -112};
    chass.setTurn(_180);
    double ang = chass.turnTo(ring3, {.timeout = 500, .exit = new Range(5, 10)});
    chass.setTurn(_90);
    chass.driveAngle(1000, ang, {.timeout = 700});
    */

    // pros::delay(100);
    // chass.mtpoint(ring3, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    // chass.mtpoint({-81, -125}, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    Pt ring4 = {-94.3, -112};
    chass.mtpoint(ring4, {.timeout = 600, .vMin = 30});
    chass.mtpoint({-80.5, -123}, {.timeout = 1100, .vMin = 30, .drift = 3.8});
    // chass.driveAngle(-400, 180, {.timeout = 400, .exit = new Range(10, 10)});
    // chass.driveAngle(-1000, 135, {.timeout = 640, .exit = new Range(10, 10)});
    // chass.driveAngle(-200, 180, {.timeout = 300, .exit = new Range(10, 10)});
    // double ang = chass.turnTo(ring4, {.timeout = 400, .exit = new Range(2, 30)});
    // chass.driveAngle(960, 200, {.timeout = 600, .exit = new Range(20, 10)});
    Pt ring3 = {-76.01, -112};
    chass.driveAngle(-400, 120, {.timeout = 500});
    double ang = chass.turnTo(ring3, {.timeout = 500, .exit = new Range(9, 10)});
    chass.driveAngle(900, 30, {.timeout = 600, .exit = new Range(20, 10)});
    // chass.mtpoint(ring3, {.timeout = 800});
    // chass.mtpoint({-77, -119}, {.timeout = 900, .vMin = 30});

    
    // chass.turn(50, {.timeout = 800, .exit = new Range(3, 10)});
    chass.driveAngle(-590, 60, {.timeout = 600, .exit = new Range(20, 10)});

    pros::delay(50);
    // clamp.toggle();
    // chass.driveAngle(700, 45, {.timeout = 300, .exit = new Range(20, 10)});
clamp.toggle();
pros::delay(100);
    chass.driveAngle(-1270, 30, {.timeout = 700, .exit = new Range(20, 10)});
    intake.move(0);

    
    // chass.driveAngle(800, 45, {.timeout = 200, .exit = new Range(20, 10)});
    // chass.driveAngle(1000, 45, {.timeout = 300, .exit = new Range(20, 10)});
    /*
    chass.turnTo(ring3, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring3, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });


    Pt ring4 = {-77, -112};
    chass.turnTo(ring4, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring4, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });

    Pt corner = {-92, -125.42};
    pros::delay(500);
    clamp.toggle();
    chass.driveAngle(-1400, 45, {.timeout = 700, .vMin = 0, .exit = new Range(20, 10)});
    */
        chass.mtpoint({-61, -95.6}, {.exit = new Range (7, 10)});

}

void hang() {
    //-50, -87
    lb.setState(keejLib::LiftState::prime);
    chass.setTurn(_180);
    odomRelease.setState(true);
    chass.turn(neg(135), {.timeout = 500});
    chass.setTurn(_90);
    tsukasa.toggle();
    chass.driveAngle(-1100, neg(135), {.timeout = 800, .slew = 6});
    chass.driveLin(250, -50, {});
    // lb.next();    
    // lb.setState(keejLib::LiftState::lower);
    // pros::delay(200);
    // chass.driveLin(170, 90, {});
    chass.driveLin(300, 40, {});
    // chass.driveLin(400, 10, {});
    chass.driveLin(0, 0, {});
    pros::delay(5000);
    // chass.driveLin(400, -35, {});
    // chass.driveLin(400, 35, {});
    // chass.driveAngle(500, neg(135), {.slew = 4});
    // chass.driveAngle(-400, neg(135), {.slew = 4});
    // chass.driveAngle(400, neg(135), {.slew = 4});
}
void skills() {
    init();

    // chass.turn(neg(45), {.timeout = 500, .exit = new Range(0.5, 500)});
        // Pt prime = {-16.9, -126};

        // chass.mtpoint(prime, {.timeout = 1400, .vMin = 0, .settleRange = 9, .exit = new Range(4, 300), .drift = 6});


        // chass.turn(neg(160), {.timeout = 900, .exit = new Range(1, 10)});
        // // chass.setLin(_linSmall);
        // chass.driveAngle(500, neg(160), {.timeout = 1000, .exit = new Range(100, 10)});
        // chass.driveAngle(700, 120, {.timeout = 1000, .exit = new Range(20, 10)});
        // pros::delay(800);
        // clamp.toggle();
        // chass.driveAngle(-1000, 75, {.timeout = 1000, .exit = new Range(600, 10)});
        // chass.driveAngle(-1000, 25, {.timeout = 1000, .exit = new Range(20, 10)}, true);
        // chass.driveAngle(300, 25, {.timeout = 400, .exit = new Range(20, 10)});
        // clamp.toggle();
        // chass.driveAngle(-300, 25, {.timeout = 400, .exit = new Range(20, 10)});
    allianceStake();
    goal1();
    wall1();
    corner1();
    goal2();
    goal3();
    corner4();
    hang();
    
}