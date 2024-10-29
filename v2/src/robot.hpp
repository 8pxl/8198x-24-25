#pragma once

#include "keejLib/lib.h"

using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-10,9,8}, {-20,10,18});
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController); 
    pros::Motor intake(7);
    pros::Motor lift(3);
}