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
    int clr = cont.select({"red", "blue", "driver"});
    if (clr == 2) {
        intake.setColor(keejLib::none);
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
    // glb::auton = rAwp;
    if (glb::auton == bwallNeg) {
        imu.set_heading(342.6);
    }
    else if(glb::auton == belimsNeg || glb::auton == rctrPos || glb::auton == bAwp || glb::auton == rctrwallPos) {
        imu.set_heading(43.46);
    }
    else if (glb::auton == rAwp || glb::auton == relimsNeg || glb::auton == bctrPos || glb::auton == bctrwallPos) {
        imu.set_heading(neg(43.46));
    }
    robot::lb.startControl();

    chass.startTracking();

    
    lb.setState(keejLib::LiftState::one);
    robot::intake.startControl();

}

void disabled() {
    liftMotor.set_brake_mode(pros::MotorBrake::hold);
}
void competition_initialize() {
    liftMotor.set_brake_mode(pros::MotorBrake::hold);
}
void autonomous() {
    glb::autonRan = true;
    glb::auton();
}

void opcontrol() {
    if (glb::autonRan) {
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