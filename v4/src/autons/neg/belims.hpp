#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;

void belimsNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
      lb.setState(LiftState::alliance);

      //score alliance ring

      // chass.moveWithin(allianceStake, 14.7, {});
      // chass.driveAngle(180, 43, {.timeout = 700});
      chass.driveLin(700, 28, {});
      chass.driveAngle(-200, 43, { .timeout = 400, .vMin = 100,});
      lb.setState(LiftState::idle);

      chass.mtpoint({-10.9, -17.6}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.8
      });
      // pros::delay(100000);
      // chass.mtpose({{-8, -19.6}, h(0)}, 0.5, {.timeout = 1100, .vMin = 60,.settleRange = 5, .exit = new Range(3, 10), .drift = 6,});
      // chass.driveAngle(-400, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50,.exit = new Range(130, 10)});
      // chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.driveAngle(-500, neg(30), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.driveAngle(-400, neg(36), {.async = false, .timeout = 1000, .vMin = 50, .vMax = 60, .exit = new Range(100, 10)});
      // chass.driveAngle(-400, neg(50), {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      clamp.toggle();
      pros::delay(100);
            // intake.move(0);

      //go to center rings
      // chass.mtpoint({4.7, -31}, {.exit = new Range(10, 10), .drift = 10, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-23.1, -48.4};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9, .slew = 0});
      pros::delay(100);
      chass.driveAngle(800, neg(90), {.exit = new Range(40, 10), .slew = 3});
      
      //intake second ring
      chass.driveAngle(-700, neg(110), {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-700, neg(135), {.vMin = 40, .exit = new Range(150, 10)});
      Pt ring2 = {-33.1, -31.0};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});
      chass.driveAngle(600, ringAngle, {.vMin = 90, .exit = new Range(100, 10), });
      // chass.mtpoint(ring2, {.vMin = 90, .exit = new Range(3,10)});
      chass.driveAngle(-300, neg(50), {.vMin = 80, .exit = new Range(90, 10)});

      //go to corner
      Pt corner1 = {-41.4, 4.6};
      worldsWinningMech.toggle();
      chass.mtpoint(corner1, {.timeout = 1500, .exit = new Range(1, 10), .drift = 6, .within = 2});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({-50.6, 11.0}, {.timeout = 600});
      chass.setTurn(_90);
      intakeCorner(ang, neg(45));

      
      bool touch = true;
      if(touch) {
          pros::delay(600);
          ang = chass.turnTo({22.0, -34.0}, {.timeout = 1400});
        lb.setState(keejLib::LiftState::lower);
        worldsWinningMech.toggle();
        chass.driveAngle(2100, ang, {.async = true, .timeout = 1500, .slew = 0});
        chass.waitUntilSettled();
        chass.turn(95, {.timeout = 500});
      
      }
      else {
          Pt ring3 = {18.0, -3.0};
          chass.turn(90, {.timeout = 600});
          tsukasa.toggle();
          worldsWinningMech.toggle();
          chass.mtpoint(ring3, {.drift = 18, .within = 5});
          tsukasa.toggle();
      }
      pros::delay(2000);

}