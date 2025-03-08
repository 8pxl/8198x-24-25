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
      lb.setState(LiftState::lower);

      //score alliance ring
            Pt allianceStake = {-25.6, 18.4};

      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 2, .within = 13.8});
      lb.next();
      pros::delay(200);

      chass.mtpoint({-1.5, -7}, {.timeout = 1100, .vMin = 55, .exit = new Range(5, 10), .drift = 9,});
      chass.driveAngle(-300, 0, {.async = false, .timeout = 1000, .vMin = 30, .vMax = 55,.exit = new Range(90, 10)});
      chass.driveAngle(-1020, 0, {.async = false, .timeout = 1000, .vMin = 45, .vMax = 70, .exit = new Range(80, 10)});
      clamp.toggle();
      pros::delay(100);

      // intake.move(0);

      //go to center rings
      // chass.mtpoint({-4, -30}, {.vMin = 40, .exit = new Range(10, 10), .drift = 8, .slew = 0});
      intake.move(127);
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {22.1, -30};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(70, 10)});
      chass.mtpoint(ring1, {.vMin = 60, .exit = new Range(7, 10), .drift = 6, .slew = 0});


      //intake second ring
      // chass.driveAngle(-900, 110, {.exit = new Range(100, 10)});
      Pt ring2 = {27, -44.4};
      chass.driveAngle(700, 125, {.timeout = 400});
      chass.driveAngle(400, 180, {.timeout = 300});
      chass.mtpoint(ring2, {.vMax = 50, .drift = 9,});
            chass.driveAngle(900, neg(89), {.vMin = 30, .exit = new Range(40, 10), .slew = 0});


      intake.setJamProtection(true);

      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, ringAngle, {.vMin = 50});

      //go to third ring
      // chass.driveAngle(600, neg(60), {.timeout = 350, .vMin = 40, .exit = new Range(100, 10)});
      // chass.turn(neg(45), {.exit = new Range(15, 10)});

      Pt ring3 = {-31, -5};
      chass.mtpoint(ring3, {.async = true, .drift = 10, .within = 5, .slew = 4});
      pros::delay(600);
      tsukasa.toggle(); 
      chass.waitUntilSettled();
      tsukasa.toggle();

      //go to corner
      // chass.driveAngle(500, imu.get_heading(), {.timeout = 300});
      // chass.turn(90, {.timeout = 600, .exit = new Range(15, 10)});
      // chass.driveAngle(500, neg(120), {.vMin = 50});
      chass.mtpoint({-88.5, -8}, {.timeout = 1400,.exit = new Range(2, 10), .drift = 5, .within = 9});
      intake.setJamProtection(false);
      // chass.mtpoint({-74, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      Pt corner = {-99, 15};
      intake.move(127);
      double ang =chass.turnTo(corner, {.timeout = 330});
      chass.driveAngle(1900, ang, {.timeout = 500, .vMax = 70, .slew = 4});
      chass.driveAngle(1900, ang, {.timeout = 500, .slew = 4});
      // chass.mtpoint(corner, {.timeout = 800, .exit = new Range(2, 10), .drift = 10, .within = 3});
      chass.driveAngle(-200, neg(45), {.timeout = 300, .slew = 4});

      /* 
      //goal 2
      chass.turn(90, {.timeout = 250});
      chass.turn(140, {.async = true, .timeout = 800});
      // pros::delay(800);
      */
      chass.turn(135, {.exit = new Range(10, 10)});
      pros::delay(200);
      clamp.toggle();
      chass.driveAngle(550, 135, {.timeout = 600, .vMin = 60}); 
      /*
      // chass.turnTo(ring5, {.async = true, .timeout = 600});
      chass.waitUntilSettled();
      chass.driveAngle(600, 135, {.vMin = 50}); 
      */
      // Pt ring5 = {-79, -31};
      Pt ring5 = {-79, -29.6};
      intake.stopOnColor(keejLib::red, 1000);
      chass.mtpoint(ring5, {.exit = new Range(4, 10), .drift = 6, .within = 4});

      Pt goal2 = {-60, -27.9};
      // double heading = chass.turnTo(goal2, {.timeout = 300, .exit = new Range(9, 10), .reverse = true});

      //clamp goal

      chass.driveAngle(-900, neg(90),  {.timeout = 900, .vMin = 55, .vMax = 70, .exit = new Range(90, 10)});

      clamp.toggle();
      pros::delay(70);

      intake.move(127);
      chass.turn(160, {.timeout = 300, .vMax = 50});
      chass.driveAngle(700, 160, {.async = true});
      pros::delay(300);
      lb.next();
      // lb.setState(keejLib::LiftState::lowest);
            intake.setJamProtection(true);
            chass.waitUntilSettled();
            // lb.setState(LiftState::one);
            // intake.setColor(none);


}