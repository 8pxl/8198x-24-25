#include "keejLib/controller.h"
#include "keejLib/util.h"
#include "keejlib/lib.h"
#include "pros/motors.h"
#include "robot.hpp"
#include "main.h"
#include "clamp.hpp"
#include <random>

using namespace robot;

void init() {
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

bool lock = false;
void driver(Controller::driveMode mode) {
    if (!lock) {
        dt.spinVolts(cont.drive(1, mode));
    }
    auto state = cont.getAll(ALLBUTTONS);
    
    if (state[R1]) {
        // baseArm.move(127);
        intake.move(127);
    }
    else if (state[R2]) {
        // baseArm.move(-127);
        intake.move(-127);
    }
    else {
        intake.move(0);
    }
    
    if (state[L1]) {
        lift.move(127);
    }
    else if (state[L2]) {
        lift.move(-127);
    }
    else {
        lift.brake();
    }
    
    if (state[NA]) {
        clamp::tilt();
    }
    
    if (state[NB]) {
        clamp::clamp();
    }
    
    if (state[NY]) {
        redirect.toggle();
    }
    
    if (state[NUP]) {
        if (lock) {
            prosController.clear();
        }
        else {
            prosController.print(0, 0, "locked :3");
        }
        lock = !lock;
    }
}