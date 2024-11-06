#pragma once

#include "intake/vStates.h"
#include "keejLib/lib.h"
#include "lift/lift.h"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

using namespace keejLib;

namespace robot {
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController); 
    pros::Motor intakeMotor(-12);
    pros::Motor liftMotor(6);
    
    pros::ADIDigitalOut clampPiston('a');
    pros::Rotation rotationSensor(21, true);
    pros::Optical opticalSensor(20);
    Pis clamp({clampPiston}, false);
    
    lift::Lift lb(&liftMotor, &rotationSensor, &opticalSensor, {
        .kp = 0.02,
        .ki= 0.9,
        .maxIntegral = 1000000,
        .tolerance = 0,
        .integralThreshold = 50,
    });
    ifsm::Intake intake(&intakeMotor, &opticalSensor, Color::none);
    DriveTrain dt = keejLib::DriveTrain({-15,-13,-14}, {3,2,1});
}