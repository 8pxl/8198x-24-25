#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;

void belimsNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
      Pose p = chass.getPose();
      chass.setPose({-p.pos.x, p.pos.y, p.heading});
      lb.setState(LiftState::lower);

      //score alliance ring
            Pt allianceStake = {25.6, 18.4};

      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.4});
      lb.next();
      pros::delay(200);

      chass.mtpoint({4.1, -12.8}, {.timeout = 1100, .vMin = 85, .exit = new Range(3, 10), .drift = 9,});
      chass.driveAngle(-400, neg(20), {.async = false, .timeout = 1000, .vMin = 60, .vMax = 75,.exit = new Range(130, 10)});
      chass.driveAngle(-550, neg(20), {.async = false, .timeout = 1000, .vMin = 60, .vMax = 70, .exit = new Range(100, 10)});
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);

      //go to center rings
      chass.mtpoint({4.0, -31.4}, {.exit = new Range(10, 10), .drift = 10, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-12.1, -43.8};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9, .slew = 0});
      pros::delay(100);
      chass.driveAngle(900, neg(90), {.exit = new Range(40, 10), .slew = 3});

      //intake second ring
      chass.driveAngle(-500, neg(110), {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-700, neg(135), {.vMin = 40, .exit = new Range(150, 10)});
      Pt ring2 = {-22.1, -28.0};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});
      chass.driveAngle(600, ringAngle, {.vMin = 50});
      chass.driveAngle(-200, neg(40), {.vMin = 50, .exit = new Range(90, 10)});

      //go to corner
      // chass.mtpoint({74.0, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 27.4
      Pt corner1 = {-30.8, 5.3};
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(1, 10), .drift = 6});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({-39.2, 15.0}, {.timeout = 600});
      chass.setTurn(_90);
      intakeCorner(ang, neg(45));

      
      bool touch = false;
      if(touch) {
          ang = chass.turnTo({33.0, -30.0}, {.timeout = 1400});
    //was 15,35
    // chass.mtpoint({-20.0, -34.0}, {.drift = 6});
        // pros::delay(50);                ang = chass.turnTo({33.0, -30.0}, {.timeout = 1400});
        // intake.move(20);
        // intake.setJamProtection(true);
        //was 15,35
        // chass.mtpoint({-20.0, -34.0}, {.drift = 6});
        lb.setState(keejLib::LiftState::lower);
        chass.driveAngle(2100, ang, {.async = true, .timeout = 1500, .slew = 0});
        // pros::delay(600);
        chass.waitUntilSettled();
        chass.turn(95, {.timeout = 500});
      
      }
      else {
          Pt ring3 = {29.0, -3.0};
    
    
    
          chass.turn(90, {.timeout = 600});
          tsukasa.toggle();
          chass.mtpoint(ring3, {.drift = 10, .within = 5});
          tsukasa.toggle();
          chass.driveAngle(2100, 80, {.exit = new Range(100, 10)});
          intake.move(127);
          doink.toggle();
          chass.driveAngle(1000, 60, {.timeout = 600});
          chass.turn(neg(136), {});
          
    
          // Pt corner2 = {80.0, 24.0};
          // chass.mtpoint(corner2, {.async = true, .timeout = 1200, .exit = new Range(1, 10), .drift = 10, .within = 9});
          // pros::delay(400);
          // tsukasa.toggle();
          // chass.waitUntilSettled();
          // pros::delay(2000);
      }
      pros::delay(2000);

}