#include "main.h"
#include "pros/misc.h"
#include "robot.hpp"
#include "controls.hpp"
#include "globals.hpp"
#include "units/units.hpp"
#include "locolib/particleFilter.h"

using namespace robot;

void initialize() {
    // intake.setSorting(false);
    imu.reset(true);
    // std::cout << vertDistSensor.is_installed();
    // chass.mcl.initUniform(-1.78308, -1.78308, 1.78308, 1.78308);
    // chass.mcl.addSensor(&vd);
    // chass.mcl.addSensor(&hd);

    robot::lb.startControl();
    robot::intake.startControl();

    // std::cout << "hi" << std::endl;
    // intake.setColor(glb::color);
    // intake.startControl();
    chass.startTracking();
    
    int clr = cont.select({"red", "blue"});
    intake.setColor(static_cast<Color>(clr));
    // glb::color = clr ? blue : red;
    glb::auton = autons.autonsList[cont.select(autons.names)];
    
    // int clr = red;
    // glb::auton = skills;
    // if (glb::auton == skills) {
    // }
    
    // if (glb::color == blue) {
        // Pose p 
        // = chass.getPose();
        // chass.setPose({-p.pos.x, p.pos.y, p.heading});
    // }
    // 
    if(glb::auton == bPos) {
        prosController.print(0, 0, "%f", "blue pos");
        Pose p = chass.getPose();
        chass.setPose({-p.pos.x, p.pos.y, p.heading});
    }
    
    
    // robot::vision.set_signature(0, &redRing);
    // robot::vision.set_signature(1, &blueRing);
    // lb.setState(lift::Idle::getInstance());
}

void disabled() {}
void competition_initialize() {}
void autonomous() {
    glb::auton();
}

void opcontrol() {
    
    // intake.startControl();
    // lb.startControl();
    
    // lb.setState(lift::Idle::getInstance());
    // pros::delay(180);
    // intake.setSorting(true);
    // lb.setAutoControl(true);
    // for (int i = 0; i < 100; i++) {
    //     lb.setAutoControl(true);
    // }
    while(true) {
        // lb.setAutoControl(true);        

        // std::cout << "his" << std::endl;
        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            glb::auton();
            // intake.setSorting(true);
        }
        driver();
        
        pros::delay(10);
    }
}