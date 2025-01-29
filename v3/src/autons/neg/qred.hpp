#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"

using namespace robot;

void qrNeg() {
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
      Pt allianceStake = {-26.3, 17.9};
      // chass.moveWithin(allianceStake, 14.7, {});
      chass.mtpoint(allianceStake, {.drift = 12, .within = 14.7});
      lb.next();
      intake.move(127);
      pros::delay(300);

      //go to center rings
      chass.mtpoint({-4, -30}, {.exit = new Range(10, 10), .drift = 10});
      lb.setState(LiftState::idle);

      //intake first ring
      Pt firstRing = {14, -43};
      double ringAngle = chass.turnTo(firstRing, {.exit = new Range(5, 10)});
      chass.driveAngle(800, ringAngle, {});

      //intake second ring
      chass.driveAngle(-800, 110, {});
      Pt secondRing = {18, -29};
      ringAngle = chass.turnTo(secondRing, {});
      chass.driveAngle(800, ringAngle, {});

}