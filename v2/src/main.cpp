#include "main.h"
#include "robot.hpp"
#include "controls.hpp"

using namespace robot;
void initialize() {
    intake.startControl();
    lb.startControl();
    imu.reset();
    chass.startTracking();
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}

void opcontrol() {
    while(true) {
        driver();
        pros::delay(10);
    }
}