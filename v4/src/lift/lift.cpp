#include "lift.h"
#include "../robotState/robotState.h"
#include "keejLib/util.h"
#include "liblvgl/widgets/lv_label.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "states.h"
#include <ostream>

namespace keejLib {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    // std::cout << motor->is_installed() << std::endl;
    currentState = LiftState::idle;
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
    if (task == nullptr) {
        calibrate();
        motor -> set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        task = new pros::Task{[this] {
            while (true) {
                control();
                pros::delay(10);
            }
        }};
    }
    pros::delay(20);
}

void Lift::calibrate() {
    bool x = motor -> is_installed();
    if (x) {
        std::cout << "motor is installed" << std::endl;
    }
    else {
        std::cout << "motor is not installed" << std::endl;
    }
    double current = motor -> get_current_draw();
    pros::delay(100);
    motor -> move(-70);
    pros::delay(100);
    while (current < 980) {
        current = motor -> get_current_draw();
        pros::delay(10);
        // std::cout << current << std::endl;
    }
    motor -> tare_position();
    motor -> move(0);
    // std::cout << "old angle: " << angle << std::endl;
    // if (angle > 32000) {
    //     // std::cout << "set to: " << angle - 36000 << std::endl;
    //     rot ->set_position(angle - 36000);
    // }
    // std::cout << "new angle: " << rot -> get_position() << std::endl;

}
void Lift::setControl(bool state) {
    off = !state;
    if (state == true) {
        if (motor -> get_position() >= 800) {
            if (currentState == LiftState::two || currentState == LiftState::one) {setState(LiftState::idle);}
            else setState(LiftState::idle);
        }
    }
}

void Lift::spin(double voltage) {
    if (off) {
        motor -> move(voltage);
        //snapping
        // std::cout << "rot position: " << rot -> get_position() << std::endl;
        // std::cout << "target: " << target << std::endl;
        // std::cout << "error: " << abs(rot -> get_position()- target) << std::endl; 
;
        if (voltage == 0 && (abs(motor -> get_position()- target) <= snapRange)) {
    // std::cout << (abs(rot -> get_position()- target)) << std::endl;
    // std::cout << snapRange << std::endl;
            off = false;
        }
    }
}

void Lift::control() {
    if (off) return;
    auto s = RobotState::getInstance();
    currentState = s->getLiftState();
    setTarget(currentState);
    double angle = (motor -> get_position()) * 0.4;
    // if (angle > 360 * 100 && (currentState  == LiftState::two)|| ) {
    //     currentState = LiftState::idle;
    // }
    error =  target - angle;
    // std::cout << error << std::endl;
    // std::cout << "angle" << angle << std::endl;
    motor -> move((pid.out(error) + kf * cos(angle + angleOffset)));
    if (currentState == LiftState::idle && fabs(error) < 70) {
        motor -> move(0);
        if (calibrateTimer.elapsed() > 18000 && idleTimer.elapsed() > 5000) {
            calibrate();
            calibrateTimer.reset();
        }
    }
    else (idleTimer.reset());
    // std::cout << "target: " << target << std::endl;
}

void Lift::setState(LiftState state) {
    currentState = state;
    setTarget(currentState);
    auto s = RobotState::getInstance();
    s -> setLiftState(currentState);
    pid.resetIntegral();    
    // setControl(true);
}

void Lift::next() {
    setState(fwdMap[currentState]);
}

void Lift::prev() {
    setState(revMap[currentState]);
}

void Lift::setTarget(LiftState state) {
    target = valueMap[state];
}
}