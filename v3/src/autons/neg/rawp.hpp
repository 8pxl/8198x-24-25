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
      lb.next();
      chass.driveAngle(-930, 0, {.async = true, .exit = new Range(180, 10), .slew = 2.3});
      pros::delay(400);
      intake.move(127);
      chass.waitUntilSettled();
      clamp.toggle();
      chass.driveAngle(-930, 0, {.async = false, .exit = new Range(50, 10),}, true);

      intake.move(0);
      lb.setState(LiftState::lower);

      //score alliance ring
      // chass.driveAngle(800, neg(10), {});
      Pt allianceStake = {-26.3, 18.9};
      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      //go to center rings
      chass.mtpoint({-4, -30}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {12.5, -44.6};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.drift = 9});
      chass.driveAngle(800, 90, {});

      //intake second ring
      chass.driveAngle(-800, 110, {.exit = new Range(30, 10)});
      Pt ring2 = {20, -28};
      chass.mtpoint(ring2, {.vMin = 50, .within = 4});
      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, ringAngle, {.vMin = 50});

      //go to third ring
      chass.driveAngle(600, neg(60), {.vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {-29, -1};
      chass.mtpoint(ring3, {.drift = 10, .within = 5});

      //go to corner
      // chass.driveAngle(2600, neg(78), {});  
      intake.setJamProtection(false);
      chass.mtpoint({-73, 3}, {.exit = new Range(13, 10), .drift = 8, .within = 6});
      Pt corner = {-102, 24};
      intake.move(127);
      chass.mtpoint(corner, {.timeout = 900, .exit = new Range(0, 100000), .drift = 10, .within = 5});
      chass.driveAngle(600, neg(45), {.timeout  = 600, .exit = new Range(0, 100000)});
      chass.driveAngle(-600, neg(65), {});


      //goal 2
      Pt ring5 = {-78.5, -22};
      chass.turnTo(ring5, {.async = true, .timeout = 600});
      intake.setJamProtection(true);
      pros::delay(300);
      clamp.toggle();
      chass.waitUntilSettled();
      chass.mtpoint(ring5, {.within = 4});
      intake.move(40);

      Pt goal2 = {-60, -23};
      double heading = chass.turnTo(goal2, {.exit = new Range(6, 10), .reverse = true});

      //clamp goal

      chass.driveAngle(-950, heading, {.exit = new Range(180, 10), .slew = 2.3});
      clamp.toggle();
      chass.driveAngle(-950, heading, {.exit = new Range(50, 10),}, true);

      clamp.toggle();
      intake.move(127);
      chass.turn(180, {.timeout = 600});
      chass.driveAngle(600, 180, {});

}