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
    std::cout << "mark 1" << std::endl;    
    // int clr = cont.select({"red", "blue", "driver"});
    std::cout << "mark 2" << std::endl;
    glb::color = blue;
    glb::auton = bAwp;
    std::cout << "mark 3" << std::endl;
    if (glb::auton == qbPos) {
        imu.set_heading(342.6);
    }
    else if(glb::auton == belimsNeg || glb::auton == rringsPos || glb::auton == bAwp) {
        imu.set_heading(43.46);
    }
    intake.setColor(red);
    robot::lb.startControl();

    chass.startTracking();
    std::cout << "mark 4" << std::endl;
    // if (clr == 2) {
    //     intake.setColor(keejLib::none);
    // }
    // else {
    //     glb::color = clr ? red : blue;
    //     intake.setColor(oppositeColor(static_cast<Color>(clr)));
    //     if (clr == red) {
    //         glb::auton = redAutons.autonsList[cont.select(redAutons.names)];
    //     }
    //     else {
    //         glb::auton = blueAutons.autonsList[cont.select(blueAutons.names)];
    //     }
    // }
    
    lb.setState(keejLib::LiftState::one);
    // liftMotor.set_brake_mode(pros::MotorBrake::hold);
    pros::delay(50);
    std::cout << "mark 5" << std::endl;
    // robot::lb.startControl();
    robot::intake.startControl();

    std::cout << "mark 6" << std::endl;
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