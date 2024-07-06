#include "keejLib/controller.h"
#include "keejLib/util.h"
#include "keejlib/lib.h"
#include "robot.hpp"
#include "main.h"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, Controller::driveMode::arcade));
    auto state = cont.getAll(ALLBUTTONS);
    
    if (state[R1]) {
        intake.move(127);
    }
    else if (state[R2]) {
        intake.move(-127);
    }
    else {
        intake.move(0);
    }
}