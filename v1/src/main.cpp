#include "main.h"
#include "keejLib/lib.h"
#include "robot.hpp"
#include "controls.hpp"

// - globals
void (*auton)();
bool color;

void initialize() {
}

void autonomous() {auton();}

void opcontrol() {
    while (true) {
        driver();
        pros::delay(10);
    }
}