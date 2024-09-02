#pragma once

#include "keejLib/lib.h"
// #include "pros/misc.hpp"
#include "lift.hpp"
#include "pros/optical.hpp"
// #include "pros/rotation.hpp"
using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-16,18,-17}, {15,-13,14});
    
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController);
    
    pros::Motor intake(20);
    pros::Motor liftMotor(12);
    
    pros::ADIDigitalOut clampPiston('A');
    pros::ADIDigitalOut tiltPiston('B');
    pros::ADIDigitalOut redirPiston('C');
    pros::ADIDigitalOut intakePiston('D');
    
    pros::Rotation rotationSensor(19);
    pros::Rotation vertTracker(11);
    pros::Rotation horizTracker(3);
    pros::Optical optical(1);
    
    pros::Imu imu(5);
    
    Chassis chass = keejLib::Chassis(&dt, {
        .horizWidth = 0,
        .vertWidth = 0,
        .trackDia = 4.0,
        .wheelDia = 2.0,
        .gearRatio = 0.75,
    }, &imu, &vertTracker, &horizTracker);
    
    Pis clamp({clampPiston}, false);
    Pis tilt({tiltPiston}, false);
    Pis redirect({redirPiston} , false);
    Pis tsukasa({intakePiston}, false);
    
    Lift lift(&liftMotor, &rotationSensor, {
        .kp = 1,
        .ki = 0,
        .kd = 0,
        .maxIntegral = 127,
        .tolerance = 0,
        .integralThreshold = 100000,
    });
}
