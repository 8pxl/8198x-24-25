#include "../constants.hpp"
#include "../../robot.hpp"
#include "../../lift/lift.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../funcs.hpp"

using namespace robot;
void rrrushPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    chass.turn(120, {.timeout = 300});
    ldoink.toggle();
    rdoink.toggle();
    chass.turn(180, {});
    pros::delay(50000);
    
    
    intake.move(127);
    chass.driveAngle(1100, 10, {.vMin = 60});
    intake.move(0);
    tsukasa.toggle();
    chass.driveAngle(1800, 20, {}, true);
    rdoink.toggle();
    pros::delay(100);
    chass.setTurn(_5);
    chass.turn(37, {});
    chass.setTurn(_90);
    ldoink.toggle();
    pros::delay(100);
    chass.driveAngle(-300, 80 , {.vMin = 80,});
    chass.driveAngle(-1000, 60 , {.vMin = 60, .vMax = 70});
    clamp.toggle();
    chass.turn(90, {});
    ldoink.toggle();
    rdoink.toggle();
    chass.turn(180, {});
    // chass.driveAngle(-900, 90, {.vMin = 50});
    
    // chass.driveAngle(1200, 10, {});
}