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
    imu.reset(true);
    chass.startTracking();
    robot::intake.startControl();
    
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
    
    lb.setState(keejLib::LiftState::one);
    pros::delay(50);
    robot::lb.startControl();
}

void disabled() {
    liftMotor.set_brake_mode(pros::MotorBrake::hold);
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
    if (glb::autonRan) {
        odomRelease.setState(true);
        intake.setAutoLift(true);
    }
    while(true) {

        if(robot::prosController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            glb::auton();
        }
        driver();
        
        pros::delay(10);
    }
}