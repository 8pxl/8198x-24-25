#include "main.h"
#include "keejLib/lib.h"
#include "robot.hpp"
#include "controls.hpp"
// #include "autons/test.cpp"

std::vector<Controller::driveMode> driveModes = {keejLib::Controller::driveMode::arcade, keejLib::Controller::driveMode::tank, keejLib::Controller::driveMode::reverseArcade, keejLib::Controller::driveMode::curvature};
// - globals
void (*auton)();
bool color;
keejLib::Controller::driveMode mode = keejLib::Controller::arcade;

void initialize() {
    // init();
    mode = driveModes[robot::cont.select(DRIVEMODE_NAMES)];
    // color = cont.select({"red", "blue"});
}

void autonomous() {auton();}

void opcontrol() {
    while (true) {
        // driver(mode);
        pros::delay(20);
    }
}