#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;

void rwallNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
      lb.setState(LiftState::lower);

      //score alliance ring
            Pt allianceStake = {-25.6, 18.4};

      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.4});
      lb.next();
      pros::delay(200);

      chass.mtpoint({-1.4, -5}, {.timeout = 1100, .vMin = 40, .exit = new Range(3, 10), .drift = 9,});
      chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 55,.exit = new Range(90, 10)});
      chass.driveAngle(-800, 0, {.async = false, .timeout = 1000, .vMin = 20, .vMax = 55, .exit = new Range(80, 10)});
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);

      //go to center rings
      chass.mtpoint({-4, -31.4}, {.exit = new Range(10, 10), .drift = 10, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {12.1, -42.9};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.exit = new Range(3.5, 10), .drift = 9, .slew = 0});
      pros::delay(100);
      chass.driveAngle(990, 90, {.exit = new Range(40, 10), .slew = 3});
      
      // chass.driveAngle(700, 0, {.timeout = 500});
      intake.setAutoLift(false);
      //intake second ring
      chass.driveAngle(-500, 110, {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-700, 135, {.vMin = 40, .exit = new Range(150, 10)});
      Pt ring2 = {22.1, -27};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});

      lb.next();
      chass.driveAngle(670, ringAngle, {.async = true, .vMin = 50});
      pros::delay(200);
      chass.waitUntilSettled();
      // chass.driveAngle(-300,neg(90), {.vMin = 40, .exit = new Range(90, 10)});
      // chass.driveAngle(-400,neg(140), {.vMin = 20, .exit = new Range(90, 10)});
      // tsukasa.toggle();
      
      Pt stake = {45, -51.8};
      Pt scoringPosition = {39.8, -44.9};
      chass.turnTo(scoringPosition, {.exit = new Range(90, 20)});
      chass.mtpoint(scoringPosition, {.async = true, .timeout = 1400, .exit = new Range(4, 10),.drift = 3});
      pros::delay(800);
      lb.setState(keejLib::LiftState::prime);
      chass.waitUntilSettled();
      chass.setTurn(_5);
      double ang = chass.turnTo(stake, {.timeout = 700});
      chass.setTurn(_90);
      lb.next();
      pros::delay(100);
      chass.driveAngle(200, ang-10, {.timeout = 300});
      chass.driveAngle(-200, ang+10, {.timeout = 300});
      chass.driveAngle(200, ang-10, {.timeout = 300});
      lb.next();
      

      //go to corner
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 27.4
      Pt corner1 = {28.8, 5.3 };
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.async = true, .timeout = 1300, .exit = new Range(1, 10), .drift = 6});
      pros::delay(500);
      lb.setState(keejLib::LiftState::idle);
      chass.waitUntilSettled();
      // tsukasa.toggle();
      intake.move(127);
      chass.setTurn(_5);
    ang = chass.turnTo({39.2, 15}, {.timeout = 1000});
      chass.setTurn(_90);
      // chass.turn(45, {});=
      intake.setJamProtection(false);
      // chass.driveLin(600, 40, {});
chass.driveAngle(890, ang, {.timeout = 630, .slew = 3});
            intake.setJamProtection(false);
            chass.driveLin(410, -25, {});
            intake.setJamProtection(true);
      tsukasa.toggle();
      intake.move(127);
      pros::delay(300);
      chass.driveAngle(890, 45, {.timeout = 680, .slew = 2.4});
      intake.setJamProtection(false);
      tsukasa.toggle();
      chass.driveAngle(-600, 45, {.timeout = 600, .slew = 2});
      intake.setJamProtection(true);

      
      bool touch = false;
      if(touch) {
          ang = chass.turnTo({-33, -30}, {.timeout = 1400});
    //was 15,35
    // chass.mtpoint({20, -34}, {.drift = 6});
        // pros::delay(50);                ang = chass.turnTo({-33, -30}, {.timeout = 1400});
        // intake.move(20);
        // intake.setJamProtection(true);
        //was 15,35
        // chass.mtpoint({20, -34}, {.drift = 6});
        lb.setState(keejLib::LiftState::lower);
        chass.driveAngle(2100, ang, {.async = true, .timeout = 1500, .slew = 0});
        // pros::delay(600);
        chass.waitUntilSettled();
        chass.turn(neg(95), {.timeout = 500});
      
      }
      else {
          Pt ring3 = {-29, -3};
    
    
    
          chass.turn(neg(90), {.timeout = 600});
          tsukasa.toggle();
          chass.mtpoint(ring3, {.drift = 10, .within = 5});
          tsukasa.toggle();
          chass.driveAngle(900, neg(90), {});
    
          intake.move(127);
      }
      pros::delay(2000);

}