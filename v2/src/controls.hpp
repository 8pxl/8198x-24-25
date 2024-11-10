#include "autons/constants.hpp"
#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "robot.hpp"
#include "autons/autons.hpp"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, keejLib::Controller::driveMode::arcade));
    std::vector<bool> state = cont.getAll(ALLBUTTONS);
    std::vector<bool> released = cont.getReleased();
    
    // if (state[R1]) intakeMotor.move(127);
    // else if (state[R2]) intakeMotor.move(-127);
    // else intakeMotor.move(0);
    // std::cout << released[R1] << std::endl;
    if (state[R1]) intake.move(127);
    else if (state[R2]) intake.move(-127);
    else intake.move(0);
    
    
    if (state[NL1]) lb.next();
    if (state[NL2]) lb.prev();
    
    if (state[NRIGHT]) lb.toggle();
    if (state[NY]) clamp.toggle();
    
    if (state[NB]) doink.toggle();
    if (state[NA]) claw.toggle();
    if (state[NUP]) tsukasa.toggle();
    if (state[NDOWN]) {
        // test();
        // rPos();
        bPos();
        // chass.setTurn(_90);
        // auto x = chass.measureOffsets(5);
        // std::cout << x.first << " " << x.second << std::endl;
    }
    if (state[NLEFT]) {
        auto p = chass.getPose();
        prosController.print(0, 0, "%.2f, %.2f, %.2f", p.pos.x, p.pos.y, p.heading.heading());
    }
}

