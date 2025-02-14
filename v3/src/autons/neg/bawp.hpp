#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "pros/screen.h"

using namespace robot;

void bAwp() {
      chass.setTurn(_90);
      chass.setAng(_ang);
      chass.setLin(_lin);
      chass.setMTP(_chassLin, _chassAng);

      //grab mogo and score alliance stake;
      // lb.next();
        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});

      // chass.driveAngle(-1000, neg(0), {.async = true, .vMax = 60,.exit = new Range(300, 10), .slew = 3});
      // pros::delay(400);
      chass.driveAngle(-1000, neg(0), {.async = false, .vMax = 40, .exit = new Range(50, 10)}, false);
      clamp.toggle();
      pros::delay(100);
      lb.setState(LiftState::lower);
      // intake.move(127);

      // intake.move(0);

      //score alliance ring
      // chass.driveAngle(800, 10, {});
      //was 25.9
      Pt allianceStake = {25.4, 18.5};
      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      // lb.setState(keejLib::LiftState::lowest);
      // pros::delay(1500);
      // chass.driveAngle(-1300, 45, {});
      // intake.move(127);
      // chass.driveAngle(-900, 30, {.async = false, .vMax = 60,.exit = new Range(300, 10), .slew = 3});
      // chass.waitUntilSettled();
      // clamp.toggle();
      // chass.driveAngle(-900, 30, {.async = false, .vMax = 60, .exit = new Range(50, 10)}, true);

      //go to center rings
      intake.setJamProtection(false);
      chass.mtpoint({4.0, -32.4}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {-12, -45.8};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(4, 10)});
      chass.mtpoint(ring1, {.exit = new Range(5, 10), .drift = 9});
      chass.driveAngle(900, neg(86), {.exit = new Range(40, 10)});
      pros::delay(100);

      //intake second ring
      chass.driveAngle(-900, neg(110), {.exit = new Range(100, 10)});
      Pt ring2 = {-20.0, -29.0};
      intake.setJamProtection(true);
      chass.mtpoint(ring2, {.vMin = 50, .within = 4});
      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, neg(ringAngle), {.vMin = 50});

      //go to third ring
      chass.driveAngle(600, 60, {.timeout = 350, .vMin = 40, .exit = new Range(100, 10)});
      // chass.turn(45, {.exit = new Range(15, 10)});

      Pt ring3 = {29.0, -2.0};
      chass.mtpoint(ring3, {.async = true, .drift = 10, .within = 5});
      pros::delay(600);
      tsukasa.toggle();
      chass.waitUntilSettled();
      tsukasa.toggle();

      //go to corner
      chass.turn(neg(100), {.timeout = 500, .exit = new Range(15, 10)});
      chass.mtpoint({86.0, 10.0}, {.timeout = 1400, .exit = new Range(2, 10), .within = 9});
      /*
      intake.setJamProtection(false);
      // chass.mtpoint({74.0, 2.5}, {.exit = new Range(6, 10), .drift = 7, .within = 6});
      Pt corner = {104.0, 24.0};
      intake.move(127);
      chass.mtpoint(corner, {.timeout = 800, .exit = new Range(2, 10), .drift = 10, .within = 6});
      chass.driveAngle(-300, 45, {.timeout = 400, .slew = 4});


      //goal 2
      chass.turn(neg(90), {.timeout = 250});
      chass.turn(neg(140), {.async = true, .timeout = 800});
      // pros::delay(800);
      */
      clamp.toggle();
      chass.driveAngle(600, neg(135), {.vMin = 50}); 
      /*
      // chass.turnTo(ring5, {.async = true, .timeout = 600});
      chass.waitUntilSettled();
      chass.driveAngle(600, neg(135), {.vMin = 50}); 
      */
      Pt ring5 = {79.0, -30.0};
      chass.mtpoint(ring5, {.exit = new Range(4, 10), .drift = 6, .within = 4});

      Pt goal2 = {60.0, -27.3};
      double heading = chass.turnTo(goal2, {.timeout = 300, .exit = new Range(9, 10), .reverse = true});
      intake.stopOnColor(keejLib::blue, 1000);

      //clamp goal

      chass.driveAngle(-1190, 90,  {.timeout = 900, .vMax = 40, .exit = new Range(40, 10)});
      clamp.toggle();
      pros::delay(70);

      intake.move(127);
      pros::delay(500);
      chass.turn(neg(135), {.timeout = 500});
      chass.driveAngle(710, neg(135), {.async = true});
      pros::delay(300);
      // lb.setState(keejLib::LiftState::lowest);
            intake.setJamProtection(true);
            chass.waitUntilSettled();
            // lb.setState(LiftState::one);
            // intake.setColor(none);


}