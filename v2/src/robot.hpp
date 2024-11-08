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
    pros::Motor intakeMotor(-14);
    pros::Motor liftMotor(4);
    
    pros::ADIDigitalOut clampPiston('a');
    pros::ADIDigitalOut doinkArmPiston('b');
    pros::ADIDigitalOut doinkClawPiston('c');
    pros::Rotation rotationSensor(15);
    pros::Rotation vertTracker(6, true);
    pros::Rotation horizTracker(17);
    pros::Optical opticalSensor(5);
    pros::Imu imu(16);
    Pis clamp({clampPiston}, false);
    Pis doink({doinkArmPiston}, false);
    Pis claw({doinkClawPiston}, false);
    
    lift::Lift lb(&liftMotor, &rotationSensor, &opticalSensor, {
        .kp = 0.025,
        .ki= 0.9,
        .maxIntegral = 1000000,
        .tolerance = 0,
        .integralThreshold = 50,
    });
    // ifsm::Intake intake(&intakeMotor, &opticalSensor, Color::none);
    DriveTrain dt = keejLib::DriveTrain({-11,-12,-13}, {3,2,1});
    //4.64907 1.30551
    Chassis chass = keejLib::Chassis(&dt, {
        .horizWidth = -4.812,
        .vertWidth = -1.30551,
        .trackDia = 4.0,
        .wheelDia = 2.125,
        .gearRatio = 0.75,
    }, &imu, &vertTracker, &horizTracker);
}