#include "keejLib/controller.h"
#include "keejLib/piston.h"
#include "keejLib/util.h"
#include "keejlib/lib.h"
#include "pros/motors.h"
#include "robot.hpp"
#include "main.h"
#include "clamp.hpp"
#include <random>

using namespace robot;

bool lock = false;

void init() {
    lift.initTask();
    // lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void shifted(std::vector<bool> &state) {
    if (state[NR1]) {
        lift.toggle();
    }
    
    if (state[NR2]) {
        tsukasa.toggle();
    }
}

void normal(std::vector<bool> &state) {
    if (state[R1]) {
        if (tsukasa.getState()) {
            tsukasa.toggle();
        }
        intake.move(127);
    }
    else if (state[R2]) {
        intake.move(-127);
    }
    else {
        intake.move(0);
    }
    
    if (state[NL1]) {
        redirect.toggle();
    }
}

void driver(Controller::driveMode mode) {
    if (!lock) {
        dt.spinVolts(cont.drive(1, mode));
    }
    std::vector<bool> state = cont.getAll(ALLBUTTONS);
    
    if(state[L2]) {
        shifted(state);
    }
    else {
        normal(state);
    }
    
    if (state[NA]) {
        clamp::tilt();
    }
    
    if (state[NB]) {
        clamp::clamp();
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