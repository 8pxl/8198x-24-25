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
              lb.setState(LiftState::lower);

      Pt allianceStake = {25.6, 18.4};
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.8});
      lb.next();
      pros::delay(200);

      chass.mtpoint({2.9, -5}, {.timeout = 1100, .vMin = 40, .exit = new Range(3, 10), .drift = 9,});
      chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 55,.exit = new Range(90, 10)});
      chass.driveAngle(-800, 0, {.async = false, .timeout = 1000, .vMin = 20, .vMax = 55, .exit = new Range(80, 10)});
      clamp.toggle();
      pros::delay(100);

      //go to center rings
      chass.mtpoint({4.0, -32.0}, {.exit = new Range(10, 10), .drift = 10});
            intake.move(127);

      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-13.1, -44.4};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      intake.setJamProtection(false);
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 8, .slew = 0});
      pros::delay(100);
      chass.driveAngle(900, neg(86), {.exit = new Range(40, 10), .slew = 0});


      //intake second ring
      chass.driveAngle(-600, neg(110), {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-800, neg(140), {.vMin = 30, .exit = new Range(150, 10)});
      intake.setJamProtection(true);
      Pt ring2 = {-22.1, -28.0};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});
      chass.driveAngle(600, ringAngle, {.vMin = 50});
      chass.driveAngle(-200,neg(40), {.vMin = 50, .exit = new Range(90, 10)});

      //go to corner
      // chass.mtpoint({74.0, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      //was 28.1, 7.2 , -32.2, 6.8
      Pt corner1 = {-32.1, 7.0};
      // chass.turnTo(corner1, {.t  imeout = 200});
      chass.mtpoint(corner1, {.timeout = 1300, .exit = new Range(1, 10), .drift = 7});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({-39.2, 17.1}, {});
      chass.setTurn(_90);
      // chass.turn(neg(45), {});=
      intake.setJamProtection(false);
      // chass.driveLin(600, 40, {});
chass.driveAngle(890, ang, {.timeout = 600, .slew = 3});
            // pros::delay(400);
            chass.driveLin(620, -25, {});
            intake.setJamProtection(false);
      tsukasa.toggle();
      // pros::delay(50);
      intake.move(127);
      chass.driveAngle(930, neg(45), {.timeout = 680, .slew = 2.4});
      tsukasa.toggle();
      chass.driveAngle(-600, neg(45), {.timeout = 600, .slew = 2});
            ang = chass.turnTo({33, -30}, {.timeout = 1000});
      intake.move(20);
      intake.setJamProtection(true);
      //was 15,35
      // chass.mtpoint({20, -34}, {.drift = 6});
      lb.setState(keejLib::LiftState::lower);
      chass.driveAngle(2100, ang, {.async = true, .timeout = 1500, .slew = 0});
      // pros::delay(600);
      chass.waitUntilSettled();
      chass.turn(90, {.timeout = 500});
      

      //awp
      //       pros::delay(400);
      // // chass.driveAngle(-3100, neg(45), {.async = true, .exit = new Range(10, 10)});
      // pros::delay(400);
      // intake.move(0);
      // chass.waitUntilSettled();
      // lb.next();
      // pros::delay(1000);
      //-END AWP
      //go to third ring
      // chass.driveAngle(-600, neg(45), {.vMin = 40, .exit = new Range(100, 10)});
      // Pt ring3 = {29.0, -3.0};
      // pros::delay(400);
      // // tsukasa.toggle();

      // // chass.turn(90, {.timeout = 500});
      // // chass.mtpoint(ring3, {.drift = 10, .within = 5});

      // intake.move(127);
      // // pros::delay(100);

      // //touch
      // chass.driveAngle(-500, imu.get_heading(), {.timeout = 400});
      // ang = chass.turnTo({15, -30}, {.timeout = 800});
      // intake.move(20);
      // lb.next();
      // //was 15,35
      // chass.mtpoint({14, -34}, {.drift = 6});


      // Pt corner2 = {80, 24.0};
      // chass.mtpoint(corner2, {.async = true, .timeout = 1200, .exit = new Range(1, 10), .drift = 10, .within = 9});
      // pros::delay(600);
      // tsukasa.toggle();
      // chass.waitUntilSettled();
      // pros::delay(2000);
}