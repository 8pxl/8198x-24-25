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

      //grab mogo and score alliance stake;
      lb.next();
      chass.driveAngle(-970, 0, {.async = true, .exit = new Range(50, 10), .slew = 2.5});
      pros::delay(400);
      intake.move(127);
      chass.waitUntilSettled();

      intake.move(0);
      lb.setState(LiftState::lower);
      clamp.toggle();

      //score alliance ring
      // chass.driveAngle(800, neg(10), {});
      Pt allianceStake = {-26.3, 18.9};
      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      //go to center rings
      chass.mtpoint({-4, -30}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt ring1 = {12.5, -41};
      double ringAngle = chass.turnTo(ring1, {.exit = new Range(3, 10)});
      chass.driveAngle(700, ringAngle, {});

      //intake second ring
      chass.driveAngle(-800, 110, {.exit = new Range(30, 10)});
      Pt ring2 = {18, -26};
      chass.mtpoint(ring2, {.vMin = 50, .within = 8});
      // ringAngle = chass.turnTo(ring2, {.exit = new Range(13, 10)});
      // chass.driveAngle(1000, ringAngle, {.vMin = 50});

      //go to third ring
      chass.driveAngle(600, neg(60), {.vMin = 40, .exit = new Range(100, 10)});
      Pt ring3 = {-29, -1};
      chass.mtpoint(ring3, {.drift = 10, .within = 5});

      //go to corner
      chass.driveAngle(2600, neg(90), {});  
      intake.move(-127);
      
      Pt corner = {-113, 23};
      chass.driveAngle(-800, neg(90), {.async = true}); 
      intake.move(127);
      chass.mtpoint(corner, {.timeout = 1000, .exit = new Range(0, 100000), .drift = 10, .within = 5});


      //goal 2
      Pt ring5 = {-80, -20};
      chass.turnTo(ring5, {});
      clamp.toggle();
      chass.mtpoint(ring5, {.within = 5});

      Pt goal2 = {-80, -20};
      chass.turnTo(goal2, {.reverse = true});
      chass.driveAngle(-970, 0, {.async = true, .exit = new Range(50, 10), .slew = 2.5});
      clamp.toggle();

}