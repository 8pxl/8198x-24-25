#include "main.h"
#include "lift/states.h"
#include "pros/misc.h"
#include "robot.hpp"
#include "controls.hpp"
#include "globals.hpp"

using namespace robot;
void initialize() {
    // intake.setSorting(false);
    intake.setColor(glb::color);
    intake.startControl();
    lb.startControl();
    imu.reset();
    chass.startTracking();
    
    // int clr = cont.select({"red", "blue"});
    // glb::color = clr ? blue : red;
    // glb::auton = autons.autonsList[cont.select(autons.names)];
    
    int clr = red;
    glb::auton = skills;
    // if (glb::auton == skills) {
    lb.setState(lift::Two::getInstance());
    // }
    
    // if (glb::color == blue) {
    //     Pose p = chass.getPose();
    //     chass.setPose({-p.pos.x, p.pos.y, p.heading});
    // }
    
    robot::vision.set_signature(0, &redRing);
    robot::vision.set_signature(1, &blueRing);
}

void disabled() {}
void competition_initialize() {}
void autonomous() {
    glb::auton();
}

void opcontrol() {
    
    intake.startControl();
    lb.startControl();
    
    lb.setState(lift::Idle::getInstance());
    pros::delay(180);
    // intake.setSorting(true);
    lb.setAutoControl(true);
    // for (int i = 0; i < 100; i++) {
    //     lb.setAutoControl(true);
    // }
    while(true) {
        lb.setAutoControl(true);        

        // std::cout << "his" << std::endl;
        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            glb::auton();
            intake.setSorting(true);
            lb.setAutoControl(true);
        }
        driver();
        
        pros::delay(10);
    }
}