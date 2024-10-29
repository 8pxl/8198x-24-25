#pragma once

#include "keejLib/lib.h"

using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-16,18,-17}, {15,-13,12});
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController); 
    pros::Motor intake(20);
    pros::Motor lift(3);
}