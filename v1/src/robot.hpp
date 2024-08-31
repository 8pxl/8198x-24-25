#pragma once

#include "keejLib/lib.h"
// #include "lift.hpp"
using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-16,18,-17}, {15,-13,14});
    Chassis chass = keejLib::Chassis(&dt, {});
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController);
    
    pros::Motor intake(20);
    pros::Motor liftMotor(12);
    
    pros::ADIDigitalOut clampPiston('A');
    pros::ADIDigitalOut tiltPiston('B');
    pros::ADIDigitalOut redirPiston('C');
    pros::ADIDigitalOut intakePiston('D');
    
    pros::Rotation rotationSensor(19);
    
    Pis clamp({clampPiston}, false);
    Pis tilt({tiltPiston}, false);
    Pis redirect({redirPiston} , false);
    Pis tsukasa({intakePiston}, false);
    
    // Lift lift(&liftMotor, &rotationSensor, {
    //     .kp = 1,
    //     .ki = 0,
    //     .kd = 0,
    //     .maxIntegral = 127,
    //     .tolerance = 0,
    //     .integralThreshold = 100000,
    // });
}
