#include "main.h"
#include "robot.hpp"

void initialize() {}
void disabled() {}
void competition_initialize() {}
void autonomous() {}

using namespace robot;
void opcontrol() {
    while(true) {
        dt.spinVolts(cont.drive(1, keejLib::Controller::driveMode::arcade));
        std::vector<bool> state = cont.getAll(ALLBUTTONS);
        
        if (state[R1]) intake.move(127);
        else if (state[R2]) intake.move(-127);
        else intake.move(0);
        
        if (state[L1]) lift.move(127);
        else if (state[L2]) lift.move(-127);
        else lift.move(0);
    }
}