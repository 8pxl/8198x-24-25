#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;

void bAwp() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);
      lb.setState(LiftState::lower);

      Pose p = chass.getPose();
      chass.setPose({-p.pos.x, p.pos.y, p.heading});
            lb.setState(LiftState::lower);
      //score alliance ring
            Pt allianceStake = {25.6, 18.4};

      // chass.moveWithin(allianceStake, 14.7, {});
      /* OLD CLAMP
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.8});
      lb.next();
      pros::delay(200);

      chass.mtpoint({1.1, -7.0}, {.timeout = 1100, .vMin = 55, .exit = new Range(5, 10), .drift = 9,});
      chass.driveAngle(-300, neg(0), {.async = false, .timeout = 1000, .vMin = 30, .vMax = 55,.exit = new Range(90, 10)});
      chass.driveAngle(-1020, neg(8), {.async = false, .timeout = 1000, .vMin = 45, .vMax = 70, .exit = new Range(80, 10)});
      clamp.toggle();
      pros::delay(100);
      */
      
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.4});
      lb.next();
      pros::delay(200);

      // chass.mtpoint({0.5, -11.4}, {.timeout = 1100, .vMin = 85, .exit = new Range(3, 10), .drift = 9,});

      chass.mtpoint({3.1, -12.8}, {.timeout = 1100, .vMin = 85, .exit = new Range(3, 10), .drift = 9,});
      chass.driveAngle(-400, neg(20), {.async = false, .timeout = 1000, .vMin = 60, .vMax = 75,.exit = new Range(130, 10)});
      chass.driveAngle(-550, neg(20), {.async = false, .timeout = 1000, .vMin = 60, .vMax = 70, .exit = new Range(100, 10)});
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);

      //go to center rings
      // chass.mtpoint({4.0, -30.0}, {.vMin = 40, .exit = new Range(10, 10), .drift = 8, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-22.1, -28};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(70, 10)});
      chass.mtpoint(ring1, {.vMin = 60, .exit = new Range(7, 10), .drift = 6, .slew = 0});


      //intake second ring
      // chass.driveAngle(-900, neg(110), {.exit = new Range(100, 10)});
      Pt ring2 = {-27.0, -45.4};
      chass.driveAngle(700, neg(125), {.timeout = 400});
      chass.driveAngle(400, neg(180), {.timeout = 300});
      chass.mtpoint(ring2, {.vMax = 50, .drift = 9,});
            chass.driveAngle(700, 89, {.vMin = 30, .exit = new Range(40, 10), .slew = 0});
            chass.driveAngle(200, 80, {.vMin = 70, .exit = new Range(40, 10), .slew = 0});


      intake.setJamProtection(true);

      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, neg(ringAngle), {.vMin = 50});

      //go to third ring
      // chass.driveAngle(600, 60, {.timeout = 350, .vMin = 40, .exit = new Range(100, 10)});
      // chass.turn(45, {.exit = new Range(15, 10)});

      Pt ring3 = {34.0, 0.5};
      chass.mtpoint(ring3, {.async = true, .drift = 10, .within = 5, .slew = 4});
      pros::delay(500);
      tsukasa.toggle(); 
      chass.waitUntilSettled();
      tsukasa.toggle(); 

      //go to corner
      // chass.turn(neg(90), {.timeout = 600, .exit = new Range(15, 10)});
      // chass.driveAngle(500, 120, {.vMin = 50});
      chass.mtpoint({88.5, -7.0}, {.timeout = 1400,.exit = new Range(2, 10), .drift = 5, .within = 9});
      intake.setJamProtection(false);
      // chass.mtpoint({74.0, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      Pt corner = {100, 15.0};
      intake.move(127);
      double ang =chass.turnTo(corner, {.timeout = 330});
      chass.driveAngle(1900, ang, {.timeout = 1000, .vMax = 90, .slew = 4});
      // chass.mtpoint(corner, {.timeout = 800, .exit = new Range(2, 10), .drift = 10, .within = 3});
      chass.driveAngle(-200, 45, {.timeout = 300, .slew = 4});

      /* 
      //goal 2
      chass.turn(neg(90), {.timeout = 250});
      chass.turn(neg(140), {.async = true, .timeout = 800});
      // pros::delay(800);
      */
      intake.setJamProtection(true);
      chass.turn(neg(135), {.vMax = 70, .exit = new Range(10, 10)});
      pros::delay(200);
      clamp.toggle();
      chass.driveAngle(550, neg(135), {.timeout = 600, .vMin = 60}); 
      /*
      // chass.turnTo(ring5, {.async = true, .timeout = 600});
      chass.waitUntilSettled();
      chass.driveAngle(600, neg(135), {.vMin = 50}); 
      */
      // Pt ring5 = {79.0, -31.0};
      Pt ring5 = {79, -29.9};
      robot::intake.move(100);
      intake.stopOnColor(keejLib::blue, 1000);
      chass.mtpoint(ring5, {.timeout = 1000, .vMin = 30, .exit = new Range(4, 10), .drift = 6, .within = 3});

      Pt goal2 = {60.0, -27.9};
      // double heading = chass.turnTo(goal2, {.timeout = 300, .exit = new Range(9, 10), .reverse = true});

      //clamp goal

      chass.driveAngle(-900, 90,  {.timeout = 900, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});

      clamp.toggle();
      pros::delay(70);

      intake.move(127);
      chass.turn(neg(160), {.timeout = 300, .vMax = 50});
      chass.driveAngle(700, neg(160), {.async = true});
      pros::delay(300);
      lb.next();
      intake.move(0);
      // lb.setState(keejLib::LiftState::lowest);
            intake.setJamProtection(true);
            chass.waitUntilSettled();
            // lb.setState(LiftState::one);
            // intake.setColor(none);


}