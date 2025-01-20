// #include "common.h"
#include "lift.h"
#include "pros/motors.h"

namespace lift {

Lift::Lift(pros::Motor *motor, pros::Rotation *rot, PIDConstants constants) : motor(motor), rot(rot) {
    currentState = LiftState::idle;
    pid = keejLib::PID(constants);
}

void Lift::startControl() {
    if (task == nullptr) {
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

void Lift::setControl(bool state) {
    off = !state;
}

void Lift::spin(double voltage) {
    if (off) motor -> move(voltage);
}

void Lift::control() {
    if (off) return;
    // std::cout << target << std::endl;
    double angle = rot -> get_position();
    error = angle - target;
    motor -> move(pid.out(error) + kf * cos(angle + angleOffset));
}

void Lift::setState(LiftState state) {
    currentState = state;
    setTarget(currentState);
}

void Lift::next() {
    // currentState = stateMap.get_value(currentState);
    setState(fwdMap[currentState]);
    // setTarget(currentState);
    // std::cout << currentState << std::endl;
}

void Lift::prev() {
    // currentState = stateMap.get_key(currentState);
    setState(revMap[currentState]);
    // setTarget(currentState);
}

void Lift::setTarget(LiftState state) {
    target = valueMap[state] * 100;
}
}