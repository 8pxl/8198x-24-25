#pragma once

#include "keejLib/lib.h"
#include "lift/lift.h"
#include "locolib/distance.h"
#include "pros/abstract_motor.hpp"
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
    pros::MotorGroup leftChass({-17,-16,-15}, pros::MotorGears::blue);
    pros::MotorGroup rightChass({14,13,12}, pros::MotorGears::blue);
    pros::Motor intakeMotor(-11);
    pros::Motor liftMotor(10, pros::MotorGears::green);
    
    pros::adi::DigitalOut clampPiston('a');
    pros::adi::DigitalOut rightDoinker('e');
    pros::adi::DigitalOut intakePiston('c');
    pros::adi::DigitalOut leftDoinker('d');
    pros::adi::DigitalIn limit('f');
    pros::Rotation rotationSensor(22);
    pros::Rotation vertTracker(8);
    pros::Rotation horizTracker(-9);
    pros::Optical opticalSensor(6);
    pros::Distance intakeDistance(7);
    pros::Imu imu(18);
    pros::Vision vision(22);
    // pros::Distance vertDistSensor(20);
    Pis clamp({clampPiston}, false);
    Pis rdoink({rightDoinker}, false);
    Pis ldoink({leftDoinker}, false);
    Pis tsukasa({intakePiston}, false);
    // Pis colorSort({colorSortPiston}, false);
    
    // ifsm::Intake intake(&intakeMotor, &opticalSensor, Color::red);
    Intake intake(&intakeMotor, &opticalSensor, &limit, Color::blue);
    Lift lb(&liftMotor, &rotationSensor,  {
        .kp = 0.6,
        .ki= 0.08,
        .kd = 0.1,
        .maxIntegral = 1000000,
        .tolerance = 0,
        .integralThreshold = 60,
    });
    // Lift::setInstance(&lb);
    DriveTrain dt = keejLib::DriveTrain(&leftChass, &rightChass, {.cartridge = 600});
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
        .horizWidth = -2.22922,
        .vertWidth = -0.563394,
        .trackDia = 4.0,
        .vertDia = 2.75,
        .horizDia = 2.75,
    }, &imu, &vertTracker, &horizTracker);
    
    // pros::vision_signature_s_t  redRing = pros::Vision::signature_from_utility(1, 1319, 8061, 4690, -893, 327, -284, 1.300, 0);
    // pros::vision_signature_s_t blueRing = pros::Vision::signature_from_utility(2, -5121, -3615, -4368, 2049, 7201, 4626, 1.200, 0);
    
}   