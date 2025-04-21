#include "../constants.hpp"
#include "../../robot.hpp"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../../lift/lift.h"
#include "../funcs.hpp"


using namespace robot;
void qbPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
chass.setMTPose(_mposeLin, _mposeAng);
    chass.setLin(_lin);
    lb.setState(keejLib::LiftState::lower);
    // chass.mtpose({{-7, 40}, h(0)}, 0.2, {.async = true, .settleRange = 6, .drift = 4,});
    chass.driveAngle(1450, neg(12), {.async = true, .vMin = 100, .exit = new Range(60, 10),});
    pros::delay(400);
    intake.move(127);
    pros::delay(369);
    // intake.stopOnColor(blue, 1000);
    lb.setState(keejLib::LiftState::lowest);
    chass.waitUntilSettled();

    chass.driveAngle(-500, neg(30), {});
    chass.driveAngle(-900, neg(90), {});
    intake.move(0);
}