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
      chass.driveAngle(-930, 0, {.async = true, .exit = new Range(180, 10), .slew = 5});
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
      chass.mtpoint({-4, -32}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {12.5, -44.6};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.drift = 9});
      chass.driveAngle(800, 87, {.exit = new Range(40, 10)});

      //intake second ring
      chass.driveAngle(-800, 110, {.exit = new Range(30, 10)});
      Pt ring2 = {20, -28};
      chass.mtpoint(ring2, {.vMin = 50, .within = 4});
      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, ringAngle, {.vMin = 50});

      //go to third ring
      chass.driveAngle(600, neg(60), {.vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {-29, -3};
      chass.mtpoint(ring3, {.drift = 10, .within = 5});

      //go to corner
      chass.mtpoint({-87, -1}, {.exit = new Range(2, 10), .drift = 10, .within = 9});
      pros::delay(300);
      intake.setJamProtection(false);
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      Pt corner = {-107, 24};
      intake.move(127);
      chass.mtpoint(corner, {.timeout = 790, .exit = new Range(1, 10), .drift = 10, .within = 9});
      chass.driveAngle(-300, neg(45), {.timeout = 600, .slew = 2});


      //goal 2
      Pt ring5 = {-79, -26};
      pros::delay(500);
      chass.turn(90, {.timeout = 250});
      chass.turn(140, {.async = true, .timeout = 340});
      pros::delay(300);
      // chass.turnTo(ring5, {.async = true, .timeout = 600});
      clamp.toggle();
      chass.waitUntilSettled();
      chass.driveAngle(500, 135, {.vMin = 30});
      chass.mtpoint(ring5, {.exit = new Range(4, 10), .drift = 6, .within = 4});
      intake.move(30);

      Pt goal2 = {-60, -23};
      double heading = chass.turnTo(goal2, {.timeout = 400, .exit = new Range(9, 10), .reverse = true});

      //clamp goal

      chass.driveAngle(-1050, heading, {.exit = new Range(180, 10), .slew = 4});
      clamp.toggle();
      chass.driveAngle(-1050, heading, {.exit = new Range(50, 10),}, true);

      intake.move(127);
      chass.turn(180, {.timeout = 300});
      chass.driveAngle(600, 180, {});
            intake.setJamProtection(true);
            intake.setColor(none);


}