#include "constants.hpp"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "rPos.hpp"
#include "bPos.hpp"

using namespace robot;
using namespace exit;

void test() {
    // chass.measureOffsets(5);
    // chass.setLin(_lin);
    // chass.setAng(_ang);
    // chass.driveAngle(9, 0, {.timeout = 1500, .vMin=0, .exit = new Range(1, 100), .reverse=false});
    lb.setAutoControl(false);

pros::delay(700);
    intake.setSorting(false);
pros::delay(700);
intake.move(0); 
pros::delay(700);
intake.move(127);
lb.next();
intake.setSorting(true);
pros::delay(700);

}
keejLib::Autons autons = {{bPos, rPos, test}, {"bPos", "rPos", "test"}};