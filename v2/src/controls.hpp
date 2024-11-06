#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "robot.hpp"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, keejLib::Controller::driveMode::arcade));
    std::vector<bool> state = cont.getAll(ALLBUTTONS);
    
    if (state[R1]) intake.move(127);
    else if (state[R2]) intake.move(-127);
    else intake.move(0);
    
    if (state[NL1]) lb.next();
    if (state[NL2]) lb.prev();
    // else lift.move(0);
    
    if (state[NRIGHT]) clamp.toggle();
}