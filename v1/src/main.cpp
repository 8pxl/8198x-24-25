#include "main.h"
#include "keejLib/chassis.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "pros/misc.h"
#include "robot.hpp"
#include "controls.hpp"
#include "autons/test.hpp"

std::vector<Controller::driveMode> driveModes = {keejLib::Controller::driveMode::arcade, keejLib::Controller::driveMode::tank, keejLib::Controller::driveMode::reverseArcade, keejLib::Controller::driveMode::curvature};
// - globals
void (*auton)();
keejLib::Controller::driveMode mode = keejLib::Controller::arcade;

void initialize() {
    lift.initTask();
    // init();
    imu.reset(false);
    robot:chass.startTracking();
    mode = driveModes[cont.select(DRIVEMODE_NAMES)];
    int clr = cont.select({"red", "blue"});
    Color color = clr ? blue : red;
    lift.setColor(color);
    // color = 
    // chass.setAng(chassAng);
    // auto x = chass.measureOffsets(10);
    // std::cout << x.first << " " << x.second << std::endl;
}

void autonomous() {auton();}

void opcontrol() {
    Angle a = Angle(0, keejLib::DEG);
    Angle b = Angle(M_PI/2, keejLib::RAD);
    while (true) {
        // std::cout << "horiz: " <<  robot::horizTracker.get_angle() << std::endl;
        driver(mode);
        pros::delay(20);
        
        if(robot::prosController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            test();
        }
        // robot::prosController.print(0,0, "%f", robot::optical.get_hue());
    }
}