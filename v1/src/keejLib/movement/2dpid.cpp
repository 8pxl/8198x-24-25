#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace keejLib {


void Chassis::driveAngle(double dist, double angle, MotionParams params = {.vMin = 0}) {
    moving = true;
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
    while (!params.exit -> exited({.error = fabs(linError)}) && !timeout -> exited({})) {
        linError = dist - (this -> dt -> getAvgPosition());
        double angularError = targ.error(Angle(imu -> get_rotation(), HEADING));
    
        if (std::abs(angularError) < this -> angConsts.tolerance) {
            angularError = 0;
        }
        double va = angCont.out(angularError);
        double vl = linCont.out(linError);
        if (std::abs(vl) < params.vMin) {
            vl = params.vMin * sign(vl);
        }
        
        if (std::abs(vl) + std::abs(va) > 127) {
          vl = (127 - std::abs(va)) * sign(vl);
        }
        
        this -> dt -> spinVolts(vl + va, vl - va);
    }
    this -> dt -> spinVolts(0, 0);
    moving = false;
}

void Chassis::mtpoint(Pt target, MotionParams params) {
    moving = true;
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { mtpoint(target, params);});
        return;
    }

    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont(linConsts);
    PID angCont(angConsts);
    double dist = pose.pos.dist(target);
    double linearError = dist;
    double prevLin = dist;
    double pct = 0;
    bool close = false;
    int dir = params.reverse ? -1 : 1;
    double angularVel;
    //https://www.desmos.com/calculator/cnp2vnubnx
    while (timeout -> exited({}) || params.exit -> exited({.error = pose.pos.dist(target), .pose = pose })) {
        Angle currHeading = pose.heading;
        Angle targetHeading = absoluteAngleToPoint(pose.pos, target);
        if (dir < 0) targetHeading = Angle(reverseDir(targetHeading.heading()), HEADING);
        double angularError = targetHeading.error(currHeading);
        // std::cout << angularError << std::endl;
        double adjHeading = pose.heading.deg();
        if (adjHeading > 180) adjHeading = adjHeading - 180;
        double m = tan(toRad(adjHeading));
        int side = pose.pos.y < (- 1 / m) * (pose.pos.x - target.x) + target.y;
        if (side == 0) side = -1;
        dir = side * (params.reverse ? -1 : 1);
        if (close) {
            if (std::fabs(angularError) > 80) {
                angularError = 0;
            }
            // angularVel = 0;
            double tx = (m *(target.y - pose.pos.y + pose.pos.x*m + target.x/m)) / (m*m + 1);
            double ty = -m * (tx - target.x) + target.y;
            linearError = pose.pos.dist({tx, ty});
        }
        else {
            linearError = pose.pos.dist(target);
        }
        linearError *= cos(toRad(angularError));
        angularVel = angCont.out(angularError);
        prevLin = linearError;
        // std::cout << close << std::endl;
        
        if (linearError < params.settleRange && !close) close = true;
        // std::cout << angularVel << std::endl;
        // std::cout << linearError << std::endl;
        double linearVel = dir * linCont.out(linearError);
        
        // linearVel = std::clamp(linearVel, -params.vMin, params.vMin);
        if (std::abs(linearVel) + std::abs(angularVel) > 127) {
            linearVel = (127 - std::abs(angularVel)) * sign(linearVel);
        }
        double lVel = linearVel + angularVel;
        double rVel = linearVel - angularVel;
        // double x = angCont.out(angularError)
        dt -> spinVolts(lVel, rVel);
        pros::delay(10);
        // std::cout << lVel << " " << rVel << std::endl;
    }
    moving = false;
}
void Chassis::mtpose(Pose target, double dLead, MotionParams params) {
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { mtpose(target, dLead, params);});
        return;
    }

    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont(linConsts);
    PID angCont(angConsts);
    
    bool close = false;
    Pt carrot = target.pos;
    double distToTarget = pose.pos.dist(target.pos);
    
    while (timeout -> exited({}) || params.exit -> exited({.error = distToTarget, .pose = pose })) {
        if (distToTarget < params.settleRange && !close) {
            close = true;
        }
        
        if (!close) {
            double h = std::hypot(pose.pos.x - target.pos.x, pose.pos.y - target.pos.y);
            carrot = {target.pos.x - (h * sin(pose.heading.rad()) * dLead), target.pos.y - (h * cos(pose.heading.rad()) * dLead)};
        }
        else {
            carrot = target.pos;
        }
        Angle currHeading = pose.heading;
        Angle targetHeading = absoluteAngleToPoint(pose.pos, carrot);
        if (params.reverse) targetHeading = Angle(reverseDir(targetHeading.heading()), HEADING);
        double angularError = targetHeading.error(currHeading);
        
        double linearError = pose.pos.dist(carrot);
        
        if (close) {
            linearError *= cos(angularError);
        }
        else {
            linearError *= sign(cos(angularError));
        }
        
        double angularVel = angCont.out(angularError);
        double linearVel = linCont.out(linearError);
        
        // linearVel = std::clamp(linearVel, -params.vMin, params.vMin);
        if (std::abs(linearVel) + std::abs(angularVel) > 127) {
            linearVel = (127 - std::abs(angularVel)) * sign(linearVel);
        }
        double lVel = (linearVel - (fabs(angularVel) * params.mtpRotBias)) + angularVel;
        double rVel = (linearVel - (fabs(angularVel) * params.mtpRotBias)) - angularVel;
        dt -> spinVolts(lVel, rVel);
        pros::delay(10);
    }
}

}