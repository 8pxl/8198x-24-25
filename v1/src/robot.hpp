#pragma once

#include "keejLib/lib.h"
// #include "pros/misc.hpp"
#include "lift.hpp"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
// #include "pros/rotation.hpp"
using namespace keejLib;

namespace robot {
    DriveTrain dt = keejLib::DriveTrain({-16,18,-17}, {15,-13,12});
    
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController);
    
    pros::Motor intake(20);
    pros::Motor liftMotor(3);
    
    pros::ADIDigitalOut clampPiston('D');
    pros::ADIDigitalOut tiltPiston('B');
    pros::ADIDigitalOut redirPiston('C');
    pros::ADIDigitalOut intakePiston('A');
    pros::ADIDigitalOut holderPiston('E');
    
    pros::Rotation rotationSensor(19);
    pros::Rotation vertTracker(11, false);
    pros::Rotation horizTracker(6, true);
    pros::Optical optical(1);
    
    pros::Imu imu(5);
    
    
    /*
    .horizWidth = 0.756774,
    .vertWidth = 1.48165, */
    Chassis chass = keejLib::Chassis(&dt, {
        .horizWidth = -0.75768,
        .vertWidth = 0.536951,
        .trackDia = 4.0,
        .wheelDia = 2.125,
        .gearRatio = 0.75,
    }, &imu, &vertTracker, &horizTracker);
    
    Pis clamp({clampPiston}, false);
    Pis tilt({tiltPiston}, false);
    Pis redirect({redirPiston} , false);
    Pis tsukasa({intakePiston}, false);
    Pis holder({holderPiston}, false);
    
    Lift lift(&liftMotor, &rotationSensor, &optical, &redirect, &holder, {
        .kp = 1,
        .ki = 0,
        .kd = 0,
        .maxIntegral = 127,
        .tolerance = 0,
        .integralThreshold = 100000,
    });
}
