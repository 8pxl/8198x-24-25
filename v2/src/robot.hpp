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
    pros::ADIDigitalOut doinkArmPiston('c');
    pros::ADIDigitalOut doinkClawPiston('d');
    pros::ADIDigitalOut intakePiston('b');
    pros::Rotation rotationSensor(15);
    pros::Rotation vertTracker(6, true);
    pros::Rotation horizTracker(17);
    pros::Optical opticalSensor(5);
    pros::Imu imu(16);
    Pis clamp({clampPiston}, false);
    Pis doink({doinkArmPiston}, false);
    Pis claw({doinkClawPiston}, false);
    Pis tsukasa({intakePiston}, false);
    
    ifsm::Intake intake(&intakeMotor, &opticalSensor, Color::red);
    lift::Lift lb(&liftMotor, &rotationSensor, &opticalSensor, &intake, {
        .kp = 0.025,
        .ki= 0,
        .maxIntegral = 1000000,
        .tolerance = 0,
        .integralThreshold = 50,
    });
    DriveTrain dt = keejLib::DriveTrain({-11,-12,-13}, {3,2,1});
    //4.64907 1.30551
    Chassis chass = keejLib::Chassis(&dt, {
        .horizWidth = -1.20161,
        .vertWidth = -1.45133,
        .trackDia = 4.0,
        .vertDia = 2.125,
        .horizDia = 2.75,
        .gearRatio = 0.75,
    }, &imu, &vertTracker, &horizTracker);
    
    pros::vision_signature_s_t  redRing = pros::Vision::signature_from_utility(1, 1319, 8061, 4690, -893, 327, -284, 1.300, 0);
    pros::vision_signature_s_t blueRing = pros::Vision::signature_from_utility(2, -5121, -3615, -4368, 2049, 7201, 4626, 1.200, 0);
}   