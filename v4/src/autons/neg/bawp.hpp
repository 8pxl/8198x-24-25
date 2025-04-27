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
      lb.setState(LiftState::alliance);

      //score alliance ring

      chass.driveLin(700, 22, {});
      chass.driveAngle(-200, 43, { .timeout = 400, .vMin = 100,});
      lb.setState(LiftState::idle);

      chass.mtpoint({-8.6, -19.6}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.8
      });
      chass.driveAngle(-500, 0, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 40, .exit = new Range(50, 10)});
      clamp.toggle();
      
      pros::delay(100);
      intake.move(127);

      // Intake first ring
      Pt ring1 = {-33.1, -30.0};
      // double ringAngle = chass.turnTo(ring1, {.exit = new Range(70, 10)});
      chass.mtpoint(ring1, {.vMin = 60, .exit = new Range(7, 10), .drift = 16, .slew = 0});
      
      // Intake second ring
      Pt ring2 = {-38.0, -49.4};
      chass.driveAngle(700, neg(125), {.timeout = 400});
      chass.driveAngle(400, neg(180), {.timeout = 300});
      chass.mtpoint(ring2, {.vMax = 50, .drift = 9});
      chass.driveAngle(700, 89, {.vMin = 30, .exit = new Range(40, 10), .slew = 0});
      chass.driveAngle(200, 80, {.vMin = 70, .exit = new Range(40, 10), .slew = 0});
      
      intake.setJamProtection(true);
      
      // Go to third ring
      Pt ring3 = {23.0, -6.5};
      chass.mtpoint(ring3, {.async = true, .exit = new Range (5, 10), .drift = 10, .within = 7, .slew = 4});
      pros::delay(500);
      tsukasa.toggle();
      chass.waitUntilSettled();
      chass.turn(110, {});
      tsukasa.toggle();
      
      // Go to ring
      chass.mtpoint({68, -11.0}, {.timeout = 1400, .exit = new Range(5, 10), .drift = 5, .within = 5});
      intake.stopOnColor(keejLib::blue, 1000);
      
      // Clamp second goal
      intake.setJamProtection(true);
      rdoink.toggle();
      chass.driveAngle(700, 45, {});
      chass.turn(neg(135), {.exit = new Range(50, 10)});
      chass.driveAngle(700, 45, {});
      clamp.toggle();
      chass.turn(135, {.exit = new Range(40, 10)});
      chass.turn(30, {});
      chass.driveAngle(-1300, 30, {.timeout = 1100, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});
      clamp.toggle();
      intake.move(127);
      
      // // Intake next ring
      Pt ring5 = {68.0, -33.9};
      chass.mtpoint(ring5, {.timeout = 1000, .vMin = 30, .exit = new Range(4, 10), .drift = 6, .within = 3});
      pros::delay(100000);
      
      // // Clamp second goal
      // Pt goal2 = {49.0, -31.9};
      // chass.driveAngle(-900, 90, {.timeout = 900, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});
      // clamp.toggle();
      // pros::delay(70);
}