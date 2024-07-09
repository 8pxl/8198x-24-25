// #include "main.h"
#include "keejLib/controller.h"
#include "keejLib/lib.h"
#include "robot.hpp"
#include "controls.hpp"

// - globals
void (*auton)();
bool color;
keejLib::Controller::driveMode mode = keejLib::Controller::arcade;

void initialize() {
    mode = keejLib::driveModes[cont.select(DRIVEMODE_NAMES)];
    color = cont.select({"red", "blue"});
}

void autonomous() {auton();}

void opcontrol() {
    while (true) {
        driver(mode);
        pros::delay(20);
    }
}