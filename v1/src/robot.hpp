#pragma once

#include "keejLib/lib.h"
#include "pros/misc.hpp"
using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-16,18,-17}, {15,-13,14});
    // Chassis chass = keejLib::Chassis(dt, {});
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController);
    
    pros::Motor intake(20);
    
    pros::ADIDigitalOut clampPiston('A');
    pros::ADIDigitalOut tiltPiston('B');
    
    Pis clamp({clampPiston}, false);
    Pis tilt({tiltPiston}, false);
}
