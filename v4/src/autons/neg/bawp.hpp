#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;

void bAwp() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);
      lb.setState(LiftState::alliance);

      //score alliance ring

      chass.driveLin(700, 25, {});
      chass.driveAngle(-200, 43, { .timeout = 400, .vMin = 100,});
      lb.setState(LiftState::idle);

      chass.mtpoint({-9.5, -16.7}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.8
      });
      chass.driveAngle(-300, neg(30), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.driveAngle(-500, neg(36), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      clamp.toggle();
      // chass.driveAngle(-250, neg(20), {.async = false, .timeout = 1000, .vMin = 30, .vMax = 40, .exit = new Range(50, 10)});
      
      chass.waitUntilSettled();
      pros::delay(200);
      intake.move(127);

      // Intake first ring
      Pt ring1 = {-32.1, -32.3};
      // double ringAngle = chass.turnTo(ring1, {.exit = new Range(70, 10)});
      chass.driveAngle(600, neg(68), {.vMin = 60, .exit = new Range(50, 10)});
      chass.mtpoint(ring1, {.vMin = 60, .exit = new Range(7, 10), .drift = 5, .slew = 0});
      
      // Intake second ring
      Pt ring2 = {-32.0, -49.9};
      chass.driveAngle(700, neg(145), {.timeout = 600});
      chass.driveAngle(500, neg(180), {.timeout = 300});
      chass.mtpoint(ring2, {.vMin = 50, .vMax = 70,.exit = new Range(6, 10),  .drift = 9});
      chass.driveAngle(700, 89, {.vMin = 70, .exit = new Range(40, 10), .slew = 0});
      chass.driveAngle(200, 80, {.vMin = 70, .exit = new Range(40, 10), .slew = 0});
      
      intake.setJamProtection(true);
      
      // Go to third ring
      Pt ring3 = {23.0, -7.9};
      chass.mtpoint(ring3, {.async = true,.vMin = 90, .exit = new Range (9, 10), .drift = 10, .within = 7, .slew = 4});
      pros::delay(500);
      tsukasa.toggle();
      chass.waitUntilSettled();
      // chass.turn(110, {});
      // chass.driveAngle(-400, 110, {});
      tsukasa.toggle();
      chass.driveAngle(300, 90,{.timeout = 250, .vMin = 100} );
      
      // Go to ring
      chass.mtpoint({61, -13.0}, {.timeout = 1400,.vMin = 100, .exit = new Range(5, 10),  .drift = 5, .within = 5,});
      intake.stopOnColor(keejLib::blue, 1000);
      
      // Clamp second goal
      intake.setJamProtection(true);
      rdoink.toggle();
      Pt corner = {68, 5};
      chass.mtpoint(corner, {.vMin = 40, .exit = new Range(3, 10), .within = 3,});
      intakeCorner(45, 45);
      chass.driveAngle(300, 45, {.timeout = 650, .vMin = 20,});
      chass.turn(neg(80), {.exit = new Range(50, 10)});
      rdoink.toggle();
      clamp.toggle();
      chass.turn(135, {.exit = new Range(60, 10)});
      Pt goal2 = {49.4, -31.9};
      double goalAng = chass.turnTo(goal2, {.exit = new Range(3, 20), .reverse = true});
      chass.driveAngle(-1590, goalAng, {.timeout = 1100, .vMin = 55, .vMax = 90, .exit = new Range(90, 10)});
      clamp.toggle();
      pros::delay(100);
      
      // // Intake next ring
      Pt ring5 = {69.5, -33.9};
      chass.mtpoint(ring5, {.async = true, .timeout = 1000, .vMin = 100, .exit = new Range(4, 10), .drift = 6, .within = 3, .turnBias=0.7});
      pros::delay(200);
      intake.move(127);
      chass.waitUntilSettled();
      chass.mtpoint({33, -37}, {.async = true, .timeout = 1100, .vMin = 80,});
      pros::delay(900);
      // lb.setState(LiftState::prime);
      intake.move(0);
      chass.waitUntilSettled();
      chass.driveAngle(-700, 45, {.timeout = 600});
      lb.setState(keejLib::LiftState::two);
      
      // // Clamp second goal
      // Pt goal2 = {49.0, -31.9};
      // chass.driveAngle(-900, 90, {.timeout = 900, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});
      // clamp.toggle();
      // pros::delay(70);
}