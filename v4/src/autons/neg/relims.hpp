#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;

void relimsNeg() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
      lb.setState(LiftState::alliance);

      //score alliance ring

      // chass.moveWithin(allianceStake, 14.7, {});
      // chass.driveAngle(180, neg(43), {.timeout = 700});
      chass.driveLin(700, 24, {});
      // chass.driveLin(700, 33, {});
      chass.driveAngle(-200, neg(43), { .timeout = 400, .vMin = 100,});
      lb.setState(LiftState::idle);

      chass.mtpoint({9.9, -15.02}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.96
      });
      // chass.driveAngle(-1200, neg(30), {.async = false, .timeout = 1000, .vMin = 70, .vMax = 80, .exit = new Range(100, 10)});
      chass.setAng(_angSmall);
      chass.driveAngle(-300, 26, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.driveAngle(-500, 38, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.setAng(_ang);
      clamp.toggle();
      pros::delay(100);
      lb.setState(keejLib::LiftState::idle);

      //intake first ring
      Pt ring1 = {23.1, -48.4};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9, .slew = 0});
      pros::delay(100);
      chass.driveAngle(700, 90, {.exit = new Range(40, 10), .slew = 3});
      
      //intake second ring
      chass.driveAngle(-700, 110, {.vMin = 70, .exit = new Range(200, 10), .slew = 0});
      chass.driveAngle(-700, 135, {.vMin = 40, .exit = new Range(150, 10)});
      Pt ring2 = {33.1, -31.0};
      ringAngle = chass.turnTo(ring2, {.exit = new Range(14, 10)});
      chass.driveAngle(600, ringAngle, {.vMin = 90, .exit = new Range(100, 10), });
      // chass.mtpoint(ring2, {.vMin = 90, .exit = new Range(3,10)});
      chass.driveAngle(-300, 50, {.vMin = 80, .exit = new Range(90, 10)});

      //go to corner
      Pt corner1 = {41.4, 4.6};
      worldsWinningMech.toggle();
      chass.mtpoint(corner1, {.timeout = 1500, .exit = new Range(1, 10), .drift = 6});
      intake.move(127);
      chass.setTurn(_5);
      double ang = chass.turnTo({50.6, 11.0}, {.timeout = 600});
      chass.setTurn(_90);
      intakeCorner(ang, 45);

      
      bool touch = true;
      if(touch) {
          pros::delay(600);
          ang = chass.turnTo({-22.0, -34.0}, {.timeout = 1400});
        lb.setState(keejLib::LiftState::lower);
        worldsWinningMech.toggle();
        chass.driveAngle(2100, ang, {.async = true, .timeout = 1500, .slew = 0});
        chass.waitUntilSettled();
        chass.turn(neg(95), {.timeout = 500});
      
      }
      else {
          Pt ring3 = {-18.0, -3.0};
          chass.turn(neg(90), {.timeout = 600});
          tsukasa.toggle();
          worldsWinningMech.toggle();
          chass.mtpoint(ring3, {.drift = 18, .within = 5});
          tsukasa.toggle();
      }
      pros::delay(2000);

}