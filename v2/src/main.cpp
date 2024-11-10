#include "main.h"
#include "robot.hpp"
#include "controls.hpp"
#include "globals.hpp"

using namespace robot;
void initialize() {
    intake.startControl();
    lb.startControl();
    imu.reset();
    chass.startTracking();
    
    int clr = cont.select({"red", "blue"});
    glb::color = clr ? blue : red;
    
    intake.setColor(glb::color);
    
    if (glb::color == blue) {
        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});
    }
    
    robot::vision.set_signature(0, &redRing);
    robot::vision.set_signature(1, &blueRing);
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}

void opcontrol() {
    intake.setSorting(true);
    lb.setAutoControl(true);
    while(true) {
        driver();
        pros::delay(10);
    }
}