#include "keejLib/lib.h"
#include "pros/misc.hpp"
#pragma once
using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({3,2,3}, {4,5,6});
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController);
}