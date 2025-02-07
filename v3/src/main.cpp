#include "main.h"
#include "keejLib/util.h"
#include "pros/misc.h"
#include "robot.hpp"
#include "controls.hpp"
#include "globals.hpp"
#include "units/units.hpp"

using namespace robot;

void initialize() {
    // intake.setSorting(false);
    imu.reset(true);
    // std::cout << vertDistSensor.is_installed();
    // chass.mcl.initUniform(-1.78308, -1.78308, 1.78308, 1.78308);
    // chass.mcl.addSensor(&vd);
    // chass.mcl.addSensor(&hd);

    robot::intake.startControl();

    // std::cout << "hi" << std::endl;
    // intake.setColor(glb::color);
    // intake.startControl();
    chass.startTracking();
    
    int clr = cont.select({"red", "blue"});
    glb::color = clr ? red : blue;
    
    intake.setColor(oppositeColor(static_cast<Color>(clr)));
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
    if (glb::auton != qrPos && glb::auton != qbPos) {
        lb.setState(keejLib::LiftState::one);
    }
    robot::lb.startControl();
    // if(glb::auton == qbPos) {
    //     prosController.print(0, 0, "%f", "blue pos");
    //     Pose p = chass.getPose();
    //     chass.setPose({-p.pos.x, p.pos.y, p.heading});
    // }
    
    
    // robot::vision.set_signature(0, &redRing);
    // robot::vision.set_signature(1, &blueRing);
    // lb.setState(lift::Idle::getInstance());
}

void disabled() {
    odomPiston.set_value(true);
}
void competition_initialize() {}
void autonomous() {
    odomPiston.set_value(false);
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
    // intake.stopOnColor(keejLib::red, 10000);
    while(true) {
        // lb.setAutoControl(true);        

        // std::cout << "his" << std::endl;
        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            init();
            // allianceStake();
            glb::auton();
            // intake.setSorting(true);
        }
        driver();
        
        pros::delay(10);
    }
}