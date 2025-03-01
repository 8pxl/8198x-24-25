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
      lb.setState(LiftState::lower);

      //score alliance ring
            Pt allianceStake = {-25.6, 18.4};

      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.8});
      lb.next();
      pros::delay(200);

      chass.mtpoint({-2.9, -5}, {.timeout = 1100, .vMin = 40, .exit = new Range(3, 10), .drift = 9,});
      chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 55,.exit = new Range(90, 10)});
      chass.driveAngle(-800, 0, {.async = false, .timeout = 1000, .vMin = 20, .vMax = 55, .exit = new Range(80, 10)});
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);

      //go to center rings
      chass.mtpoint({-4, -32}, {.exit = new Range(10, 10), .drift = 10, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {13.1, -45.3};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9, .slew = 0});
      chass.driveAngle(900, 86, {.exit = new Range(40, 10), .slew = 0});

      //intake second ring
      chass.driveAngle(-500, 110, {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-700, 135, {.vMin = 40, .exit = new Range(150, 10)});
      Pt ring2 = {22.1, -28};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});
      chass.driveAngle(600, ringAngle, {.vMin = 50});
      chass.driveAngle(-200,40, {.vMin = 50, .exit = new Range(90, 10)});

      //go to corner
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 27.4
      Pt corner1 = {30.3, 6 };
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(1, 10), .drift = 7});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({39.2, 16}, {});
      chass.setTurn(_90);
      // chass.turn(45, {});=
      intake.setJamProtection(false);
      // chass.driveLin(600, 40, {});
chass.driveAngle(890, ang, {.timeout = 600, .slew = 3});

            chass.driveLin(620, -25, {});
            intake.setJamProtection(false);
      tsukasa.toggle();
      // pros::delay(50);
      intake.move(127);
      chass.driveAngle(930, 45, {.timeout = 680, .slew = 2.4});
      tsukasa.toggle();
      chass.driveAngle(-600, 45, {.timeout = 600, .slew = 2});
            ang = chass.turnTo({-33, -30}, {.timeout = 800});
      intake.move(20);
      intake.setJamProtection(true);
      //was 15,35
      // chass.mtpoint({20, -34}, {.drift = 6});
      lb.setState(keejLib::LiftState::lower);
      chass.driveAngle(2100, ang, {.async = true, .timeout = 1900, .slew = 0});
      // pros::delay(600);
      chass.waitUntilSettled();
      chass.turn(neg(90), {});
      // Pt ring3 = {-29, -3};
      // pros::delay(400);
      // ang = chass.turnTo({-15, -30}, {.timeout = 800});
      // intake.move(20);
      // lb.next();
      // chass.mtpoint({-14, -34}, {.drift = 6});


      // tsukasa.toggle();

      // chass.turn(neg(90), {.timeout = 400});
      // chass.mtpoint(ring3, {.drift = 10, .within = 5});

      // intake.move(127);

      // Pt corner2 = {-80, 24};
      // chass.mtpoint(corner2, {.async = true, .timeout = 1200, .exit = new Range(1, 10), .drift = 10, .within = 9});
      // pros::delay(400);
      // tsukasa.toggle();
      // chass.waitUntilSettled();
      // pros::delay(2000);
      //touch:

}