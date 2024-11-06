#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "robot.hpp"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, keejLib::Controller::driveMode::arcade));
    std::vector<bool> state = cont.getAll(ALLBUTTONS);
    std::vector<bool> released = cont.getReleased();
    
    if (state[NR1]) intake.move(127);
    else if (released[R1]) intake.move(0);
    
    if (state[NR2]) intake.move(-127);
    else if (released[NR2]) intake.move(0);
    
    if (state[NL1]) lb.next();
    if (state[NL2]) lb.prev();
    // else lift.move(0);
    
    if (state[NRIGHT]) lb.score();
    if (state[NY]) clamp.toggle();
}