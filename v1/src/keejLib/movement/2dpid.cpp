#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include <cmath>

namespace keejLib {

std::pair<double, double> Chassis::pidMTPVel(Pt target, MotionParams params, PID *lCont, PID *rCont) {
    double linearError = pose.pos.dist(target);
    // std::cout << lineanrError << std::endl;
    Angle currHeading = pose.heading;
    Angle targetHeading = absoluteAngleToPoint(pose.pos, target);
    double rotationError = targetHeading.error(currHeading);
    // double cre = fabs(rotationError) > 90 ? 0.1 : cos(toRad(rotationError));
    double cre = 1;
    double angularVel = rCont -> out(rotationError);
    // std::cout << angularVel << std::endl;
    double linearVel = cre * lCont -> out(linearError);
    
    // linearVel = std::clamp(linearVel, -params.vMin, params.vMin);
    if (std::abs(linearVel) + std::abs(angularVel) > 127) {
        linearVel = (127 - std::abs(angularVel)) * sign(linearVel);
    }
    double rVel = (linearVel - (fabs(angularVel) * params.mtpRotBias)) + angularVel;
    double lVel = (linearVel - (fabs(angularVel) * params.mtpRotBias)) - angularVel;
    // std::cout << lVel << " " << rVel << std::endl;
    return(std::make_pair(lVel, rVel));
}

void Chassis::driveAngle(double dist, double angle, MotionParams params) {
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { driveAngle(dist, angle, params);});
        pros::delay(10);
        return;
    }
    Angle targ = Angle(angle, HEADING);
    
    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont = PID(this -> linConsts);
    PID angCont = PID(this -> angConsts);
    double linError;
    this -> dt -> tare_position();
    while (params.exit -> exited({.error = linError}) || timeout -> exited({})) {
        linError = dist - (this -> dt -> getAvgPosition());
        double angularError = targ.error(Angle(imu -> get_rotation(), HEADING));
    
        if (std::abs(angularError) < this -> angConsts.tolerance) {
            angularError = 0;
        }
        double va = angCont.out(angularError);
        double vl = linCont.out(linError);
        
        if (std::abs(vl) + std::abs(va) > 127) {
          vl = (127 - std::abs(va)) * sign(vl);
        }
        
        this -> dt -> spinVolts(vl - va, vl + va);
    }
}

void Chassis::mtp(Pose target, double dLead, MotionParams params) {
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { mtp(target, dLead, params);});
        return;
    }

    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont(linConsts);
    PID angCont(angConsts);
    while (timeout -> exited({}) || params.exit -> exited({.error = pose.pos.dist(target.pos), .pose = pose })) {
        double h = std::hypot(pose.pos.x - target.pos.x, pose.pos.y - target.pos.y);
        Pt carrot = {target.pos.x - (h * sin(pose.heading.rad()) * dLead), target.pos.y - (h * cos(pose.heading.rad()) * dLead)};
        std::cout << h << std::endl;
        dt -> spinVolts(pidMTPVel(carrot, params, &linCont, &angCont));
        pros::delay(10);
    }
}

}