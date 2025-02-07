#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;

void rAwp() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
      Pt allianceStake = {-26.9, 20.1};
      lb.setState(LiftState::lowest);
      // chass.moveWithin(allianceStake, 14.7, {});
      // chass.mtpoint(allianceStake, {.async = true, .drift = 9, .within = 14.7});
      pros::delay(1200);
      chass.waitUntilSettled();
      intake.move(127);
      chass.mtpoint({-3,-9}, {.drift = 5});
            lb.setState(LiftState::idle);
      
      chass.turn(0, {.exit = new Range(10, 10)});
      chass.driveAngle(-1000, 0, {.async = true, .vMax = 60,.exit = new Range(300, 10), .slew = 3});
      pros::delay(400);
      // intake.move(127);
      chass.waitUntilSettled();
      clamp.toggle();
      chass.driveAngle(-1000, 0, {.async = false, .vMax = 60, .exit = new Range(50, 10)}, true);

      // intake.move(0);

      //score alliance ring
      // chass.driveAngle(800, neg(10), {});

      //go to center rings
      chass.mtpoint({-4, -32}, {.exit = new Range(10, 10), .drift = 10});

      //intake first ring
      Pt ring1 = {12.5, -43.4};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(4, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9});
      chass.driveAngle(800, 86, {.exit = new Range(40, 10)});

      //intake second ring
      chass.driveAngle(-800, 110, {.exit = new Range(100, 10)});
      Pt ring2 = {20, -28};
      chass.mtpoint(ring2, {.vMin = 50, .within = 4});
      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, ringAngle, {.vMin = 50});

      //go to third ring
      chass.driveAngle(600, neg(60), {.timeout = 350, .vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {-29, -3};
      tsukasa.toggle();
      chass.mtpoint(ring3, {.drift = 10, .within = 5});
      tsukasa.toggle();

      //go to corner
      chass.mtpoint({-86, 10}, {.exit = new Range(2, 10), .drift = 10, .within = 9});
      intake.setJamProtection(false);
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      Pt corner = {-104, 24};
      intake.move(127);
      chass.mtpoint(corner, {.timeout = 800, .exit = new Range(2, 10), .drift = 10, .within = 6});
      chass.driveAngle(-300, neg(45), {.timeout = 400, .slew = 4});


      //goal 2
      Pt ring5 = {-77, -28};
      chass.turn(90, {.timeout = 250});
      chass.turn(140, {.async = true, .timeout = 800});
      // pros::delay(800);
      chass.driveAngle(600, 135, {.vMin = 50}); 
      clamp.toggle();
      /*
      // chass.turnTo(ring5, {.async = true, .timeout = 600});
      chass.waitUntilSettled();
      chass.driveAngle(600, 135, {.vMin = 50}); 
      */
      lb.setState(LiftState::lower);
      chass.mtpoint(ring5, {.exit = new Range(4, 10), .drift = 6, .within = 4});
      intake.stopOnColor(keejLib::red, 1000);

      Pt goal2 = {-60, -23};
      double heading = chass.turnTo(goal2, {.timeout = 400, .exit = new Range(9, 10), .reverse = true});

      //clamp goal

      chass.driveAngle(-1050, heading, {.exit = new Range(180, 10), .slew = 4});
      clamp.toggle();
      chass.driveAngle(-1050, heading, {.exit = new Range(50, 10),}, true);

      chass.turn(160, {.timeout = 200});
      intake.move(127);
      pros::delay(100);
      chass.driveAngle(730, 160, {.async = true});
      pros::delay(300);
      // lb.setState(keejLib::LiftState::lowest);
            intake.setJamProtection(true);
            // intake.setColor(none);


}