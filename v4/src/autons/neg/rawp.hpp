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

      chass.driveLin(700, 28, {});
      // chass.driveLin(700, 33, {});
      chass.driveAngle(-200, neg(43), { .timeout = 400, .vMin = 100,});
      lb.setState(LiftState::idle);

      chass.mtpoint({9.6, -16.1}, {.timeout = 1100, .vMin = 70, .exit = new Range(3, 10), .drift = 6, .turnBias = 0.8
      });
      // chass.driveAngle(-1200, neg(30), {.async = false, .timeout = 1000, .vMin = 70, .vMax = 80, .exit = new Range(100, 10)});
      chass.setAng(_angSmall);
      chass.driveAngle(-300, 30, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.driveAngle(-500, 36, {.async = false, .timeout = 1000, .vMin = 40, .vMax = 50, .exit = new Range(100, 10)});
      chass.setAng(_ang);
      clamp.toggle();
      lb.setState(keejLib::LiftState::idle);
      // chass.driveAngle(-250, 20, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 40, .exit = new Range(50, 10)});
      
      chass.waitUntilSettled();
      pros::delay(200);
      intake.move(127);

      // Intake first ring
      Pt ring1 = {32.1, -32.3};
      // double ringAngle = chass.turnTo(ring1, {.exit = new Range(70, 10)});
      chass.driveAngle(600, 72, {.vMin = 60, .exit = new Range(50, 10)});
      chass.mtpoint(ring1, {.vMin = 100, .exit = new Range(7, 10), .drift = 5, .slew = 0});
      
      // Intake second ring
      Pt ring2 = {32.0, -49.9};
      chass.driveAngle(360, 135, {.timeout = 600, .vMin = 80});
      chass.driveAngle(310, 180, {.timeout = 300, .vMin = 60});
      chass.mtpoint(ring2, {.vMin = 50, .vMax = 70,.exit = new Range(6, 10),  .drift = 9});
      chass.driveAngle(700, neg(89), {.vMin = 70, .exit = new Range(40, 10), .slew = 0});
      // chass.driveAngle(200, neg(80), {.vMin = 70, .exit = new Range(40, 10), .slew = 0});
      
      intake.setJamProtection(true);
      
      // Go to third ring
      Pt ring3 = {-23.0, -7.9};
      chass.mtpoint(ring3, {.async = true,.vMin = 50, .exit = new Range (9, 10), .drift = 10,.within = 7.3, .slew = 4});
      pros::delay(300);
      tsukasa.toggle();
      chass.waitUntilSettled();
      chass.driveAngle(-200, neg(83.5), {.timeout = 300});
      // chass.turn(neg(110), {});
      // chass.driveAngle(-400, neg(110), {});
      // tsukasa.toggle();
      // chass.driveAngle(300, neg(83),{.timeout = 250, .vMin = 100} );
      
      // Go to ring
      chass.setMTP(_chassLin, _chassAngSmall);
      chass.mtpoint({-64.9, -5.0}, {.async = true, .timeout = 1400,.vMin = 100, .exit = new Range(5, 10),  .drift = 5,});
      pros::delay(300);
      worldsWinningMech.toggle();
    tsukasa.toggle();
    chass.waitUntilSettled();
      chass.setMTP(_chassLin, _chassAng);
      // intake.stopOnColor(keejLib::blue, 1000);
      
      // Clamp second goal
      intake.setJamProtection(true);
      // rdoink.toggle();
      Pt corner = {-89.2, 9.0};
      chass.mtpoint(corner, {.timeout = 1200, .vMin = 50, .exit = new Range(5, 10), .drift = 2, .within = 2,.turnBias = 0.8});
      intake.setJamProtection(false);
      chass.driveAngle(-200, neg(45), {.timeout = 480, .vMax = 35});
      // chass.driveLin(100, -50, {});
      intake.setJamProtection(true);
      tsukasa.toggle();
      intake.move(127);
      pros::delay(300);
      intake.stopOnColor(keejLib::blue, 0);
      chass.driveAngle(890, neg(45), {.timeout = 680, .vMax = 60, .slew = 2.4});
      intake.setJamProtection(false);
      tsukasa.toggle();
      
      chass.driveAngle(-300, neg(90), {.timeout = 600, .vMin = 90});
      chass.driveAngle(-300, neg(150), {.timeout = 600, .vMin = 90});
      worldsWinningMech.toggle();
      // chass.turn(neg(180), {.async = true, .timeout = 750});
      // intake.move(0);
      clamp.toggle();
      
      Pt ring5 = {-71.0, -42.6};
      if (!intake.isMoving()) tsukasa.setState(true);
      chass.mtpoint(ring5, {.async = false, .timeout = 1000, .vMin = 30, .exit = new Range(5, 10), .drift = 5});
      tsukasa.setState(false);
      chass.driveAngle(-300, neg(120), {.timeout = 400, .vMax=50});
      // chass.turn(neg(90), {.timeout=300});
      
        Pt goal2 = {-43.0, -30.0};
      chass.setTurn(_135);
      chass.setTurn(_90);
      double angle = chass.turnTo(goal2, {.exit = new Range(5, 10), .reverse = true});
      // chass.mtpoint(goal2, {.async = false, .timeout = 1300, .vMin = 40, .exit = new Range(4, 10)});
      chass.driveAngle(-1000, neg(angle), {.timeout = 800, .vMin = 55, .vMax = 90, .exit = new Range(90, 10)});
      clamp.toggle();
      
      // chass.driveAngle(-400, neg(180), {.vMax = 60});
      chass.turn(neg(225), {.async = true,.vMax = 60});
      pros::delay(100);
      intake.move(127);
      // chass.driveAngle(500, neg(180), {.vMax = 50});
      worldsWinningMech.toggle();
      pros::delay(2000);
      
      
      // // chass.driveAngle(-700, neg(110), {.async = true, .timeout = 550, .vMin = 90});
      // // chass.turn(80, {.exit = new Range(50, 10)});
      // // rdoink.toggle();
      // pros::delay(350);
      // clamp.toggle();
      // chass.waitUntilSettled();
      // // chass.turn(neg(135), {.exit = new Range(60, 10)});
      // // Pt goal2 = {-50.4, -34.9};
      // // chass.setTurn(_135);
      // // double goalAng = chass.turnTo(goal2, {.timeout = 500, .exit = new Range(3, 20), .reverse = true});
      // // chass.setTurn(_90);
      // // chass.mtpoint(goal2, {.async = false, .timeout = 1300, .vMin = 40, .exit = new Range(4, 10)});
      // // chass.driveAngle(-400, neg(60), {.timeout = 500, .vMin = 55, .vMax = 90, .exit = new Range(90, 10)});
      // clamp.toggle();
      // pros::delay(100);
      // intake.move(127);
      
      // // // Intake next ring
      // pros::delay(200);
      // chass.waitUntilSettled();
      // // chass.mtpoint({-50.0, -37.0}, {.async = false, .timeout = 1100, .vMin = 80,});
      // chass.mtpoint({-33.0, -37.0}, {.async = true, .timeout = 1100, .vMin = 80,});

      // // chass.turn(neg(180), {});
      // // worldsWinningMech.toggle();
      // pros::delay(900);
      // // lb.setState(LiftState::prime);
      // intake.move(0);
      // chass.waitUntilSettled();
      // chass.driveAngle(-700, neg(45), {.timeout = 600});
      // lb.setState(keejLib::LiftState::two);
      
      // // // Clamp second goal
      // // Pt goal2 = {-49.0, -31.9};
      // // chass.driveAngle(-900, neg(90), {.timeout = 900, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});
      // // clamp.toggle();
      // // pros::delay(70);
}