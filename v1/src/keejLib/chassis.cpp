#include "chassis.h"
#include "main.h"
#include "keejlib/lib.h"
#include <numeric>

namespace keejLib {
    
DriveTrain::DriveTrain(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports) : pros::MotorGroup(concat(left_ports, right_ports)){}

std::vector<std::int8_t> DriveTrain::concat(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports) {
    std::vector<std::int8_t> ports(left_ports);
    ports.insert(ports.end(), right_ports.begin(), right_ports.end());
    return ports;
}

void DriveTrain::spinVolts(int left, int right) {
    _motor_group_mutex.take();
    int half = _motor_count / 2;
    for (int i = 0; i < half; i++) {
        _motors[i].move(left);
        _motors[i + half].move(right);
    }
    _motor_group_mutex.give();
}

void DriveTrain::spinVolts(std::pair<double, double> volts) {
    spinVolts(volts.first, volts.second);
}
double DriveTrain::getAvgVelocity() {
    std::vector<double> v = (get_actual_velocities());
    return (std::reduce(v.begin(), v.end()) / v.size());
}

double DriveTrain::getAvgPosition() {
    std::vector<double> v = (get_positions());
    return (std::reduce(v.begin(), v.end()) / v.size());
}

Chassis::Chassis(keejLib::DriveTrain *dt, keejLib::ChassConstants constants, pros::Imu *imu, pros::Rotation *vertEnc, pros::Rotation *horizEnc) : dt(dt), chassConsts(constants), imu(imu), vertEnc(vertEnc), horizEnc(horizEnc) {}

void Chassis::setLin(PIDConstants linear) {
    linConsts = linear;
}

void Chassis::setAng(PIDConstants ang) {
    angConsts = ang;
}
}