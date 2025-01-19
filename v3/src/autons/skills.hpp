#include "constants.hpp"
#include "pros/rtos.hpp"
using namespace robot;

void goal1() {
    lb.next();
    chass.setLin(_linBigger);
    chass.driveAngle(-210, 0, {.async = false, .timeout = 700, .vMin = 0, .exit = new Range(40, 20)});
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
    chass.moveWithin(redAS, 12.7, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    lb.next();
    lb.next();
    pros::delay(700);
    lb.prev();
    chass.driveAngle(-500, neg(45), {.async = true, .timeout = 600, .exit = new Range(20, 20)});
    lb.setState(lift::idle);
    pros::delay(200);
    chass.waitUntilSettled();
    intake.move(127);
    chass.setLin(_lin);
    
    Pt ring1 = {-3.9, -38};
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(4, 30)});
    // chass.turnTo(ring1, {.timeout = 700, .exit = new Range(1, 30)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 20, .settleRange = 2,  .exit = new Range(5, 10), .drift = 8});
    
    // Pt ring2 = {26.3, -62.58};
    Pt ring2 = {30, -64};
    chass.mtpoint(ring2, {.timeout = 1200, .vMin = 30, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    chass.driveAngle(-500, 70, {.timeout = 600, .exit = new Range(20, 10)});
    // pros::delay(300);
    
    Pt ring3 = {21.8, -44.33};
    chass.turnTo(ring3, {.timeout = 1000, .exit = new Range(6, 20)});
    chass.mtpoint(ring3, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 5});
    pros::delay(400);
    
    Pt ring4 = {21, 2.83};
    chass.mtpoint(ring4, {.timeout = 1200, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 5});
    pros::delay(890);
    
    Pt ring5 = {36,-14};
    chass.turnTo(ring5, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring5, {.timeout = 1200, .vMin = 40, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    
    Pt corner = {38, -3};
    chass.driveAngle(-300, neg(170), { .timeout = 200, .exit = new Range(40, 20)});
    chass.mtpoint(corner, {.timeout = 700, .vMin = 0, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});

    // chass.driveAngle(-780, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    // chass.driveAngle(100, neg(170), { .timeout = 600, .exit = new Range(40, 20)});
    // pros::delay(300);
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
    Pt ring2 = {33, -114};
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
    
    Pt prime = {24, -76.39};
    // chass.turnTo(prime, {.timeout = 600, .exit = new Range(6, 30)});
    chass.mtpoint(prime, {.async = false, .timeout = 1600, .vMin = 100, .settleRange = 10, .exit = new Range(10, 10), .drift = 9});

    chass.driveAngle(-600,90.1, { .timeout = 600, .exit = new Range(300, 20)});
    
    //68 > x
    //67 > x (barely)
    //66 > x
    //64.8 < x ?
    // Pt stake = {38, -64.95};
    // x < -65.85 
    Pt stake = {38, -65.89};
    chass.setTurn(_ttp);
    chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    chass.setTurn(_90);
    intake.move(-10);
    chass.waitUntilSettled();
    
    
    lb.next();
    //5.0 > x
    chass.moveWithin(stake, 4.6, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
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
    lb.setState(lift::one);
    
    Pt ring1 = {16, -116};
    intake.move(127);
    chass.turnTo(ring1, {.timeout = 700, .exit = new Range(10, 20)});
    chass.mtpoint(ring1, {.timeout = 1200, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 9});
    
    Pt goal = {1, -118};
    // chass.setLin(_linBigger);
    chass.mtpoint(goal, {.async = false, .timeout = 1600, .vMin = 5, .settleRange = 10, .exit = new Range(5, 10), .drift = 10});
    chass.driveAngle(-700, 30, {.timeout = 600, .exit = new Range(80, 10), .slew=1});
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
    chass.turn(neg(45), {.timeout = 500, .exit = new Range(5, 20)});
    // doink.toggle();
    // chass.mtpoint(goal2, {.timeout = 1200, .vMin = 20, .settleRange = 10, .exit = new Range(5, 10), .drift = 9});
    clamp.toggle();
    pros::delay(300);
    // chass.useAlternateOffsets(false);
    chass.driveAngle(400, neg(45), { .timeout = 400, .exit = new Range(40, 20)});
    clamp.toggle();
    chass.driveAngle(-1200, neg(45), { .timeout = 900, .exit = new Range(40, 20)});
    Pt prime = {-16.9, -126};
    // Pt pos = chass.getPose().pos;
    // double dist = pos.dist(prime);
    chass.turnTo(prime, {.timeout = 700, .vMin = 0, .exit = new Range(2, 15)});
    chass.moveWithin(prime, 0, { .timeout = 1000, .exit = new Range(5, 10)});
    // chass.driveAngle(dist, imu.get_heading(), { .timeout = 900, .exit = new Range(20, 20)});
    // chass.mtpoint(prime, {.timeout = 1400, .vMin = 0, .settleRange = 4, .exit = new Range(4, 300), .drift = 5});
    clamp.toggle();
    tsukasa.toggle();

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
    // x < -29.4
    // -29.8 > x
    // Pt blueAS = {-29.6, -138};
    // x > -30.8
    // -29.9
    Pt blueAS = {-30.7, -138};
    chass.turnTo(blueAS, {.timeout = 600, .exit = new Range(2, 100)});
    //11.9 < x
    // chass.moveWithin(blueAS, 12.7, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    chass.moveWithin(blueAS, 11.76, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});

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
    // chass.turn(90, {.timeout = 600, .exit = new Range(2, 100)});
    // -120 < x
    Pt mogo = {-40, -118};
    // chass.setLin(_lin);
        chass.turnTo(mogo, {.timeout = 700, .exit = new Range(5, 20), .reverse = true});
        intake.move(0);
    chass.setLin(_linSmall);
    chass.driveAngle(-1250, imu.get_heading(), {.timeout = 1000, .exit = new Range(200, 15), .slew=0.01});
    clamp.toggle();
    chass.driveAngle(-1250, imu.get_heading(), {.timeout = 400, .exit = new Range(50, 15), .slew=0.01,}, true);
    chass.setLin(_lin);
    // chass.mtpoint(mogo, {.timeout = 1000, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10)});


    // lb.next();
}

void goal2() {
    // clamp.toggle();
    // chass.useAlternateOffsets(true);
    intake.move(127);
    tsukasa.setState(false);
    Pt ring1 = {-8, -95};
    chass.turnTo(ring1, {.timeout = 500, .exit = new Range(10, 20)});
    chass.mtpoint(ring1, {.timeout = 1400, .vMin = 1, .settleRange = 5, .exit = new Range(8, 15) });
    pros::delay(800);
        Pt ring2 = {-27, -64};
    // chass.turnTo(ring2, {.timeout = 500, .exit = new Range(10, 20)});

    pros::delay(500);
    intake.move(0);
    chass.mtpoint(ring2, {.async = true, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    pros::delay(800);
    intake.move(127);
    pros::delay(1800);
    intake.move(0);


    Pt ring3 = {-54, -39};
    chass.mtpoint(ring3, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 7 });
    intake.move(127);

    // Pt ring4 = {-80, -18};
    Pt ring4 = {-74.5, -13};
    chass.mtpoint(ring4, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10) , .drift = 4});

    Pt ring5 = {-99, -14};
    chass.turnTo(ring5, {.timeout = 600, .exit = new Range(5, 10)});
    chass.driveAngle(1000, imu.get_heading(), {.timeout = 600, .exit = new Range(60, 30)});
    // chass.mtpoint(ring5, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    // pros::delay(600);
    
    Pt ring6 = {-76, -2};
    // chass.turnTo(ring6, {.timeout = 600, .exit = new Range(2, 30)});
    chass.turn(20, {.timeout = 600, .exit = new Range(2, 30)});
    chass.mtpoint(ring6, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    
    Pt corner = {-90, 4};
    chass.turn(130, {.timeout = 600, .exit = new Range(4, 30)});
    chass.mtpoint(corner, {.timeout = 900, .vMin = 0, .settleRange = 5, .exit = new Range(4, 14) });
    // pros::delay(300);
    clamp.toggle();
    pros::delay(100);
}

void goal3() {
    //-12.6 > x
    Pt prime = {-77.37, -12.8};
    chass.mtpoint(prime, {.async = false, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    
    Pt goal = {-57, -13.5};
    chass.turnTo(goal, {.timeout = 600, .exit = new Range(2, 30), .reverse = true});
    chass.setLin(_linSmall);
    intake.move(0);
    chass.driveAngle(-1100, imu.get_heading(), {.timeout = 1000, .exit = new Range(100, 10), .slew=0.008});
    clamp.toggle();
    chass.driveAngle(-1100, imu.get_heading(), {.timeout = 400, .exit = new Range(15, 10), .slew=0.008}, true);
    chass.setLin(_lin);

    Pt ring1 = {-76.5, -37};
    lb.next();
    intake.move(127);
    chass.mtpoint(ring1, {.async = false, .timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(5, 10), .drift = 8 });
    pros::delay(1350);
    intake.move(0);
    lb.next();
    lb.next();
    
    Pt ring2 = {-87, -64};
    chass.mtpoint(ring2, {.async = true, .timeout = 1400, .vMin = 0, .settleRange = 5, .exit = new Range(15, 10), .drift = 8 });
    pros::delay(400);
    intake.move(127);
    chass.waitUntilSettled();
    // chass.driveAngle(-700, neg(120), {.timeout = 700, .exit = new Range(20, 10)});
    //-68.85 < c
    //-67 < y
    //-66.5 < y
    // Pt stake = {-98, -65.5};
    // Pt stake = {-98, -65.5};
Pt stake = {-98, -61.8};
    chass.setTurn(_ttp);
    chass.turnTo(stake, {.timeout = 800, .exit = new Range(1, 200)});
    chass.setTurn(_90);
    chass.waitUntilSettled();
    
    
    chass.moveWithin(stake, 4.1, {.timeout = 1500, .vMin=0, .exit = new Range(3, 90)});
    lb.next();
    pros::delay(200);
    chass.setLin(_linBigger);
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(-200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.driveAngle(200, imu.get_heading(), { .timeout = 200, .exit = new Range(10, 20)});
    chass.setLin(_lin);
}

void corner4() {
    Pt ring1 = {-82, -90};
    chass.driveAngle(-600, neg(90), {.timeout = 700, .vMin = 20, .exit = new Range(20, 10)});
    lb.setState(lift::idle);
    chass.driveAngle(300, 200, {.timeout = 700, .vMin = 20, .exit = new Range(20, 10)});
    chass.mtpoint(ring1, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    
    Pt ring2 = {-55, -89};
    chass.turnTo(ring2, {.timeout = 600, .exit = new Range(2, 30)});

    chass.mtpoint(ring2, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });

    chass.driveAngle(-950, 90, {.timeout = 9700, .exit = new Range(40, 10)});
    Pt ring3 = {-78.6, -112};
    chass.turnTo(ring3, {.timeout = 500, .exit = new Range(5, 10)});
    chass.mtpoint(ring3, {.timeout = 1400, .vMin = 30, .settleRange = 5, .exit = new Range(2, 14) });
    Pt ring4 = {-91, -113};
    chass.driveAngle(-400, 180, {.timeout = 400, .exit = new Range(10, 10)});
    chass.driveAngle(-500, 135, {.timeout = 400, .exit = new Range(10, 10)});
    chass.driveAngle(-200, 180, {.timeout = 400, .exit = new Range(10, 10)});
    chass.turnTo(ring4, {.timeout = 600, .exit = new Range(2, 30)});
    chass.driveAngle(800, imu.get_heading(), {.timeout = 600, .exit = new Range(20, 10)});

    
    chass.turn(45, {.timeout = 800, .exit = new Range(3, 10)});
    pros::delay(200);
    // clamp.toggle();
    // chass.driveAngle(700, 45, {.timeout = 300, .exit = new Range(20, 10)});
clamp.toggle();
    chass.driveAngle(-1000, 45, {.timeout = 450, .exit = new Range(20, 10)});
    intake.move(0);

    chass.driveAngle(600, 45, { .timeout = 400, .exit = new Range(40, 20)});
    clamp.toggle();
    chass.driveAngle(-1200, 45, { .timeout = 900, .exit = new Range(40, 20)});
    
    chass.driveAngle(800, 45, {.timeout = 200, .exit = new Range(20, 10)});
    chass.driveAngle(1000, 45, {.timeout = 300, .exit = new Range(20, 10)});
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
}
void skills() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);

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
    goal1();
    wall1();
    corner1();
    goal2();
    goal3();
    corner4();
    
}