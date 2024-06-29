#include "keejlib/lib.h"
#include "robot.hpp"
#include "main.h"

using namespace robot;

void driver() {
    dt.spinVolts(cont.drive(1, Controller::driveMode::arcade));
}