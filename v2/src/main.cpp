#include "main.h"
#include "pros/misc.h"
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
    glb::auton = autons.autonsList[cont.select(autons.names)];
    
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
void autonomous() {
    glb::auton();
}

void opcontrol() {
    intake.setSorting(true);
    lb.setAutoControl(true);
    while(true) {
        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            glb::auton();
            intake.setSorting(true);
            lb.setAutoControl(true);
        }
        driver();
        
        pros::delay(10);
    }
}