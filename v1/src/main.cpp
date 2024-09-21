#include "main.h"
#include "keejLib/chassis.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "robot.hpp"
#include "controls.hpp"
#include "autons/autons.hpp"
#include "globals.hpp"

using namespace glb;

void initialize() {
    lift.initTask(&compState);
    imu.reset(true);
    
    // chass.setAng(chassAng);
    // chass.setTurn(_90);
    // auto x = chass.measureOffsets(10);
    // std::cout << x.first << " " << x.second << std::endl;
    robot:chass.startTracking();
    auton = autons.autonsList[cont.select(autons.names)];
    // mode = driveModes[cont.select(DRIVEMODE_NAMES)];
    mode = keejLib::Controller::arcade;
    int clr = cont.select({"red", "blue"});
    color = clr ? blue : red;
    
    isMatch = !cont.select({"match", "test"});
    lift.setColor(color);
    chass.setLin(_lin);
    chass.setColor(color);
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    // color = 
    // chass.setAng(chassAng);
}

void autonomous() {
    lift.setOff(false);
    compState = keejLib::autonomous;
    auton();
    compState = keejLib::teleop;
}

void opcontrol() {
    compState = keejLib::teleop;
    lift.setOff(false);
    redirect.setState(false);
    while (true) {
        // std::cout << "horiz: " <<  robot::horizTracker.get_angle() << std::endl;
        driver(mode);
        pros::delay(20);
        if (!isMatch) {
            if(robot::prosController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
                compState = keejLib::autonomous;
                auton();
                compState = keejLib::teleop;
                // awp2();
                // test();
            }
            
            if(robot::prosController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
                // triangulatePoint();
                printPoint();   
                // test();
            }
        }
        // robot::prosController.print(0,0, "%f", robot::optical.get_hue());
    }
}