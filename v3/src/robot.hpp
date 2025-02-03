#pragma once

#include "keejLib/lib.h"
#include "lift/lift.h"
#include "locolib/distance.h"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "pros/vision.hpp"
#include "intake/intake.h"
#include <cmath>

using namespace keejLib;

namespace robot {
    
    pros::Controller prosController(pros::E_CONTROLLER_MASTER);
    keejLib::Controller cont = keejLib::Controller(prosController); 
    pros::MotorGroup leftChass({-14,-15,-16});
    pros::MotorGroup rightChass({11,12,13});
    pros::Motor intakeMotor(9);
    pros::Motor liftMotor(10);
    
    pros::adi::DigitalOut clampPiston('a');
    pros::adi::DigitalOut doinkArmPiston('b');
    pros::adi::DigitalOut doinkClawPiston('c');
    pros::adi::DigitalOut odomPiston('e');
    pros::adi::DigitalOut intakePiston('d');
    pros::Rotation rotationSensor(18);
    pros::Rotation vertTracker(-20);
    pros::Rotation horizTracker(8);
    pros::Optical opticalSensor(1);
    pros::Vision vision(21);
    pros::Imu imu(17);
    // pros::Distance vertDistSensor(20);
    pros::Distance horizDistSensor(2);
    Pis clamp({clampPiston}, false);
    Pis doink({doinkArmPiston}, false);
    Pis claw({doinkClawPiston}, false);
    Pis tsukasa({intakePiston}, false);
    Pis odomRelease({odomPiston}, false);
    // Pis colorSort({colorSortPiston}, false);
    
    // ifsm::Intake intake(&intakeMotor, &opticalSensor, Color::red);
    Intake intake(&intakeMotor, &opticalSensor, Color::blue);
    Lift lb(&liftMotor, &rotationSensor, {
        .kp = 0.025,
        .ki= 0,
        .kd = 0.1,
        .maxIntegral = 1000000,
        .tolerance = 0,
        .integralThreshold = 50,
    });
    // Lift::setInstance(&lb);
    DriveTrain dt = keejLib::DriveTrain(&leftChass, &rightChass);
    //4.64907 1.30551
    // 1.27811 0.703097
    // 1.13273 1.07545
    // 
    // 1.57324 1.2872
    // 
    //1.07284 1.16508
    
    std::pair<double, double> alternate = {-1.07284, 1.16508};
    
    // loco::DistanceSensorModel vd({-6.59 * 0.0254,-4.8 * 0.0254, M_PI}, vertDistSensor);
    // loco::DistanceSensorModel hd({5.65 * 0.0254,-3.4 * 0.0254,M_PI/2}, horizDistSensor);
    Chassis chass = keejLib::Chassis(&dt, {
        .horizWidth = -1.70483,
        .vertWidth = -1.15369,
        .trackDia = 4.0,
        .vertDia = 2.125,
        .horizDia = 2.75,
        .gearRatio = 0.75,
    }, &imu, &vertTracker, &horizTracker, &horizDistSensor);
    
    // pros::vision_signature_s_t  redRing = pros::Vision::signature_from_utility(1, 1319, 8061, 4690, -893, 327, -284, 1.300, 0);
    // pros::vision_signature_s_t blueRing = pros::Vision::signature_from_utility(2, -5121, -3615, -4368, 2049, 7201, 4626, 1.200, 0);
    
}   