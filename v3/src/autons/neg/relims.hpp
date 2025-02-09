#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;

void relimsNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);


      //grab mogo and score alliance stake;
      // lb.next();
      chass.driveAngle(-1000, 0, {.async = true, .vMax = 60,.exit = new Range(300, 10), .slew = 3});
      pros::delay(400);
      // intake.move(127);
      chass.waitUntilSettled();
      clamp.toggle();
      chass.driveAngle(-1000, 0, {.async = false, .vMax = 60, .exit = new Range(50, 10)}, true);

      // intake.move(0);
      lb.setState(LiftState::lower);

      //score alliance ring
      // chass.driveAngle(800, neg(10), {});
      // Pt allianceStake = {-25.9, 18.6};
            Pt allianceStake = {-25.4, 18.6};

      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      //go to center rings
      chass.mtpoint({-4, -32}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {12.5, -45.8};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.drift = 9, .within = 1});
      chass.driveAngle(800, 86, {.vMax = 70, .exit = new Range(40, 10)});

      //intake second ring
      chass.driveAngle(-500, 110, {.vMin = 70, .exit = new Range(200, 10)});
      chass.driveAngle(-700, 135, {.vMin = 30, .exit = new Range(150, 10)});
      Pt ring2 = {22.1, -28};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(5, 10)});
      chass.driveAngle(900, ringAngle, {.vMin = 50});
      chass.driveAngle(-500, 70, {.vMin = 50, .exit = new Range(90, 10)});

      //go to corner
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 27.4
      Pt corner1 = {29.3, 7};
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(1, 10), .drift = 7});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({41, 17}, {});
      chass.setTurn(_90);
      // chass.turn(45, {});=
      intake.setJamProtection(false);
      // chass.driveLin(600, 40, {});
chass.driveAngle(470, ang, {.timeout = 600, .slew = 3});
            chass.driveLin(600, -25, {});
            intake.setJamProtection(true);
      tsukasa.toggle();
      // pros::delay(50);
      intake.move(127);
      chass.driveAngle(800, 45, {.timeout = 600, .slew = 2.4});
      tsukasa.toggle();
      chass.driveAngle(-600, 45, {.timeout = 600, .slew = 2});
      
      //go to third ring
      chass.driveAngle(-600, 45, {.vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {-29, -3};
      tsukasa.toggle();

      chass.turn(neg(90), {.timeout = 300});
      chass.mtpoint(ring3, {.drift = 10, .within = 5});

      intake.move(127);

      Pt corner2 = {-90, 24};
      chass.mtpoint(corner2, {.async = true, .timeout = 1200, .exit = new Range(1, 10), .drift = 10, .within = 9});
      pros::delay(400);
      tsukasa.toggle();
      chass.waitUntilSettled();
      pros::delay(2000);
      //touch:
      // ang = chass.turnTo({-15, -30}, {.timeout = 800});
      // intake.move(20);
      // lb.next();
      // chass.mtpoint({-13, -32}, {});

}