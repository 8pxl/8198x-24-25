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
        else {
            state = opened;
        }
        robot::tilt.toggle();
    }
    
    void clamp() {
        if (state == tilted) {
            robot::tilt.setState(false);
            pros::delay(200);
            state = opened;
        }
        else {
            state = clamped;
        }
        robot::clamp.toggle();
        state 
    }
}