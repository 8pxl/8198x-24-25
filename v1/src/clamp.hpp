#pragma once
#include "robot.hpp"

using namespace robot;

namespace clamp {
    
    enum State {
        opened,
        clamped,
        tilted
    };
    
    State state = opened;
    
    void tilt() {
        if (state == opened) {
            robot::clamp.setState(true);
            pros::delay(200);
            state = tilted;
        }
        else if (state == tilted){
            state = clamped;
        }
        else {
            state = tilted;
        }
        robot::tilt.toggle();
    }
    
    void clamp() {
        if (state == tilted) {
            robot::tilt.setState(false);
            pros::delay(200);
            state = opened;
        }
        else if (state == opened){
            state = clamped;
        }
        else {
            state = opened;
        }
        robot::clamp.toggle();
    }
}