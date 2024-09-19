#pragma once

#include "keejLib/lib.h"
// #include "lift.hpp"
#include "robot.hpp"
#include "main.h"
#include "clamp.hpp"
// #include "keejLib/lib.hpp"

using namespace robot;

bool lock = false;
bool liftOff = false;

keejLib::Stopwatch shiftSw;
void shifted(std::vector<bool> &state) {
    if (liftOff) {
        if (state[NR1]) {
            liftMotor.move(127);
        }
        
        if (state[NL1]) {
            liftMotor.move(-127);
        }
        
        else {
            liftMotor.brake();
        }
    }
    else {
        if (state[NR1]) {
            lift.toggle();
        }
        
        if (state[NL1]) {
            lift.switchState();
        }  
    }
    
    if (state[NR2]) {
        tsukasa.toggle();
    } 
    
    if (state[NX]) {
        prosController.rumble("-");
        lift.addTrim(20);
    }
    else if (state[NB]) {
        prosController.rumble(".");
        lift.addTrim(-20);
    }
    
    if (state[NA]) {
        liftOff = !liftOff;
        lift.setOff(liftOff);
    }
    // if (shiftSw.elapsed() > 600) {
    //     lift.setSate(Lift::state::resting);
    //     shiftSw.reset();
    // }
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
        prosController.rumble("-");
        redirect.toggle();
    }
    
    if (state[NA]) {
        prosController.rumble("-");
        clamp::tilt();
    }
    
    if (state[NB]) {
        prosController.rumble(".");
        clamp::clamp();
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
        shiftSw.reset();
        normal(state);
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