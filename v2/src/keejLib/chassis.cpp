#include "keejLib/chassis.h"
#include "locolib/particleFilter.h"
#include "main.h"
#include "keejLib/lib.h"
#include "pros/motor_group.hpp"
#include "keejLib/util.h"
#include "units/units.hpp"
#include <numeric>

namespace keejLib {

void DriveTrain::spinVolts(int left, int right) {
    leftMotors->move(left);
    rightMotors->move(right);
}

void DriveTrain::spinVolts(std::pair<double, double> volts) {
    spinVolts(volts.first, volts.second);
}

void DriveTrain::tare_position() {
    leftMotors->tare_position_all();
    rightMotors->tare_position_all();
}
double DriveTrain::getAvgVelocity() {
    std::vector<double> vl = leftMotors->get_actual_velocity_all();
    std::vector<double> vr = rightMotors->get_actual_velocity_all();
    return (std::reduce(vl.begin(), vl.end()) + std::reduce(vr.begin(), vr.end()) / (leftMotors->size() + rightMotors->size()));
}

double DriveTrain::getAvgPosition() {
    std::vector<double> pl = leftMotors->get_position_all();
    std::vector<double> pr = rightMotors->get_position_all();
    return (std::reduce(pl.begin(), pl.end()) + std::reduce(pr.begin(), pr.end()) / (leftMotors->size() + rightMotors->size()));
}

// units::Angle Chassis::getHeading() {
//     return 1_rad;
// }
Chassis::Chassis(keejLib::DriveTrain *dt, keejLib::ChassConstants constants, pros::Imu *imu, pros::Rotation *vertEnc, pros::Rotation *horizEnc) : 
    dt(dt), 
    chassConsts(constants), 
    imu(imu), 
    vertEnc(vertEnc), 
    horizEnc(horizEnc), 
    mcl(loco::ParticleFilter<50>([&imu](){
        units::Angle ang = imu->get_heading();
        return ang;
    })) 
{}


Chassis::Chassis(keejLib::DriveTrain *dt, keejLib::ChassConstants constants, std::pair<double, double> alternateOffsets, pros::Imu *imu, pros::Rotation *vertEnc, pros::Rotation *horizEnc) : 
    dt(dt), 
    chassConsts(constants), 
    alternateOffsets(alternateOffsets), 
    imu(imu), 
    vertEnc(vertEnc), 
    horizEnc(horizEnc),
    mcl(loco::ParticleFilter<50>([&imu](){
        units::Angle ang = imu->get_rotation();
        return ang;
    })) 
{}

std::pair<double, double> Chassis::measureOffsets(int iterations) {
    std::pair<double, double> offsets = {0,0};
    for (int i = 0; i < iterations; i++) {
        std::pair<double, double> deltaEnc = {0, 0};
        imu -> reset(true);
        double imuStart = imu -> get_heading();
        double vel = i%2 == 0 ? 30 : -30;
        // this -> turn(target, {.async = true, .timeout=1000, .exit = new exit::Range(0.01, 500)});
        this->dt->spinVolts(vel, -vel);
        Stopwatch s;
        PrevOdom prev = {0,0};
        vertEnc -> reset_position();
        horizEnc -> reset_position();
        while (s.elapsed() < 1400) {
            double currVert = vertEnc -> get_position() / 100.0;
            double currHoriz = horizEnc -> get_position()/ 100.0;
            
            deltaEnc.first += fabs((currVert- prev.vert));
            deltaEnc.second += fabs(currHoriz - prev.horiz);
            // std::cout << "vert: " << deltaEnc.first << " horiz: " << deltaEnc.second << std::endl;
            prev.vert = currVert;
            prev.horiz = currHoriz;
            pros::delay(10);
            
            if (s.elapsed() > 800) {
                this->dt->spinVolts(0, 0);
            }
        }
        double delta = toRad(fabs(angError(imu -> get_heading(), imuStart)));
        // std::cout << delta << std::endl;
        offsets.first += ((deltaEnc.first * M_PI * chassConsts.vertDia) / 360) / delta;
        offsets.second += ((deltaEnc.second * M_PI * chassConsts.horizDia) / 360) / delta;
    }
    return {offsets.first / iterations, offsets.second / iterations};
}

void Chassis::setLin(PIDConstants linear) {
    // chassMutex.take();
    linConsts = linear;
    // chassMutex.give();
}

void Chassis::setAng(PIDConstants ang) {
    // chassMutex.take();
    angConsts = ang;
    // chassMutex.give();
}

void Chassis::setMTP(PIDConstants lin, PIDConstants ang) {
    // chassMutex.take();
    mtpLin = lin;
    mtpAng = ang;
    // chassMutex.give()
}

void Chassis::setTurn(PIDConstants turn) {
    // chassMutex.take();
    turnConsts = turn;
    // chassMutex.give();
}

void Chassis::waitUntilSettled() {
    while (moving) {
        pros::delay(10);
    }
}

bool Chassis::isSettled() {
    // chassMutex.take();
    return !moving;
    // chassMutex.give();
}

Pose Chassis::getPose() {
    // chassMutex.take();
    return pose;
    // chassMutex.give();
}

void Chassis::setColor(Color c) {
    // chassMutex.take();
    clr = c;
    // chassMutex.give();
}

void Chassis::setPose(Pose p) {
    // chassMutex.take();
    pose = p;
    // chassMutex.give();
}

void Chassis::useAlternateOffsets(bool yes) {
    alternateMutex.take();
    useAltOffsets = yes;
    alternateMutex.give();
}
}