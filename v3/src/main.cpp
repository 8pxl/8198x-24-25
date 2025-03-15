#include "main.h"
#include "keejLib/util.h"
#include "lift/states.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
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
    
    int clr = cont.select({"red", "blue", "driver"});
    if (clr == 2) {
        intake.setColor(keejLib::none);
        odomRelease.setState(true);
    }
    else {
        glb::color = clr ? red : blue;
        intake.setColor(oppositeColor(static_cast<Color>(clr)));
        if (clr == red) {
            glb::auton = redAutons.autonsList[cont.select(redAutons.names)];
        }
        else {
            glb::auton = blueAutons.autonsList[cont.select(blueAutons.names)];
        }
    }
    
    // int clr = red;
    // glb::auton = skills;
    // if (glb::auton == skills) {
    // }
    
    // if (glb::color == blue) {
        // Pose p = chass.getPose();
        // chass.setPose({-p.pos.x, p.pos.y, p.heading});
    // }
    // 
    // if ( glb::auton != qbPos) {
        lb.setState(keejLib::LiftState::one);
        pros::delay(50);
    // }
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
    liftMotor.set_brake_mode(pros::MotorBrake::hold);
    // odomPiston.set_value(true);
    // lb.setState(keejLib::LiftState::lower);
}
void competition_initialize() {
    liftMotor.set_brake_mode(pros::MotorBrake::hold);
}
void autonomous() {
    glb::autonRan = true;
    odomRelease.setState(false);
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
    if (glb::autonRan) {
        odomRelease.setState(true);
        intake.setAutoLift(true);

        // lb.setState(LiftState::idle);
    }
    while(true) {
        // lb.setAutoControl(true);    
        // intake.setColor(none);

        // std::cout << "his" << std::endl;
        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            // init();
            // hang();
            // allianceStake();
            glb::auton();
            // intake.setSorting(true);
        }
        driver();
        
        pros::delay(10);
    }
}