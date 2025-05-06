#include "autons/constants.hpp"
#include "globals.hpp"
#include "intake/intake.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "lift/states.h"
#include "robot.hpp"
#include "autons/autons.hpp"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, keejLib::Controller::driveMode::arcade));
    std::vector<bool> state = cont.getAll(ALLBUTTONS);
    
    if (state[RIGHT]) {
        if (state[NR1]) rdoink.toggle();
        if (state[NL1]) ldoink.toggle();
        // if (state[NR2]) clamp.toggle();
        if (state[NL2]) worldsWinningMech.toggle();
        // if (state[NY] && state[RIGHT]) lb.setState(keejLib::LiftState::prime);
        if (state[RIGHT] && state[NY]) tsukasa.toggle();
    }
    else if (state[R2]) {
        lb.setControl(true);
        if (state[NL1]) lb.next();
        if (state[NL2]) lb.prev();
    }
    else if (state[NY]) {
        clamp.toggle();
        // worldsWinningMech.toggle();
    }
        // if (state[NL1]) lb.next();
        // if (state[NL2]) lb.prev();
    //     if (state[NR2]) lb.setState(keejLib::LiftState::idle);
    //     if (state[NR1]) lb.setState(keejLib::LiftState::one);
    // }
    if (!state[RIGHT]) {
        if (state[R2] && state[R1]) intake.move(-127);
        else if (state[R1]) intake.move(127);
        else intake.move(0);
    }
        if (state[L1]) {
            lb.setControl(false); 
            lb.spin(127);
        }
        else if (state[L2]) {
            lb.setControl(false); lb.spin(-127);
        }
        else lb.spin(0);
    if (state[NLEFT]) {
        auto p = chass.getPose();
        prosController.print(0, 0, "%.2f, %.2f, %.2f", p.pos.x, p.pos.y, p.heading.heading());
        // triangulatePoint();
    }
    // if (state[NX]) {
    // }
if (state[NB]) {
    if (intake.getColor() == none) {
        intake.setColor(glb::color);
    }
    else {
        intake.setColor(none);
    }
    // intake.setColor( static_cast<Color>((intake.getColor() + 1) % 3));
}
}

