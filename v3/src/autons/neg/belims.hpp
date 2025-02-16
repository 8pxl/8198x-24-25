#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

using namespace robot;

void belimsNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});
      //grab mogo and score alliance stake;
      // lb.next();
      chass.driveAngle(-1000, neg(0), {.async = false, .timeout = 1000, .vMax = 55, .exit = new Range(50, 10)}, false);
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);
      lb.setState(LiftState::lower);

      //score alliance ring
      // chass.driveAngle(800, 10, {});
      Pt allianceStake = {25.6, 18.4};
      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      //go to center rings
      chass.mtpoint({4.0, -32.0}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-12.5, -45.7};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      intake.setJamProtection(false);
      chass.mtpoint(ring1, {.drift = 9, .within = 1});
      pros::delay(300);
      chass.driveAngle(800, neg(86), {.vMax = 60, .exit = new Range(40, 10)});

      //intake second ring
      chass.driveAngle(-600, neg(110), {.vMin = 70, .exit = new Range(200, 10)});
      chass.driveAngle(-800, neg(140), {.vMin = 30, .exit = new Range(150, 10)});
      intake.setJamProtection(true);
      Pt ring2 = {-22.1, -28.0};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(10, 10)});
      chass.driveAngle(1100, ringAngle, {.timeout = 700,.vMin = 4});
      chass.driveAngle(-400, neg(70), {.timeout = 250, .vMin = 4, .exit = new Range(90, 10)});

      //go to corner
      // chass.mtpoint({74.0, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 28.1, 7.2
      Pt corner1 = {-32.1, 6.9};
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(1, 10), .drift = 7});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({-39.2, 17.0}, {});
      chass.setTurn(_90);
      // chass.turn(neg(45), {});=
      intake.setJamProtection(false);
      // chass.driveLin(600, 40, {});
chass.driveAngle(890, ang, {.timeout = 600, .slew = 3});
            // pros::delay(400);
            chass.driveLin(620, -25, {});
            intake.setJamProtection(true);
      tsukasa.toggle();
      // pros::delay(50);
      intake.move(127);
      chass.driveAngle(900, neg(45), {.timeout = 680, .slew = 2.4});
      tsukasa.toggle();
      chass.driveAngle(-600, neg(45), {.timeout = 600, .slew = 2});
      
      //go to third ring
      chass.driveAngle(-600, neg(45), {.vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {29.0, -3.0};
      pros::delay(400);
      // tsukasa.toggle();

      // chass.turn(90, {.timeout = 500});
      // chass.mtpoint(ring3, {.drift = 10, .within = 5});

      intake.move(127);
      // pros::delay(100);

      //touch
      // chass.driveAngle(-500, imu.get_heading(), {.timeout = 400});
      ang = chass.turnTo({15, -30}, {.timeout = 800});
      intake.move(20);
      lb.next();
      //was 15,35
      chass.mtpoint({14, -34}, {.drift = 6});


      // Pt corner2 = {80, 24.0};
      // chass.mtpoint(corner2, {.async = true, .timeout = 1200, .exit = new Range(1, 10), .drift = 10, .within = 9});
      // pros::delay(600);
      // tsukasa.toggle();
      // chass.waitUntilSettled();
      // pros::delay(2000);
}