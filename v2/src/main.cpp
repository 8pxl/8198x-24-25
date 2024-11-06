#include "main.h"
#include "robot.hpp"
#include "controls.hpp"

using namespace robot;
void initialize() {
    lb.startControl();
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