#include "keejLib/control.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <type_traits>

namespace keejLib {

    void Chassis::moveWithin(Pt target, double dist, MotionParams params, double angle) {
        // chassMutex.take();
        if (params.async) {
            params.async = false;
            pros::Task task([&]() { moveWithin(target, dist, params);});
            pros::delay(10);
            return;
        }
        this -> waitUntilSettled();

        if (params.exit == nullptr) {
            params.exit = new exit::Range(5, 50);
        }

        moving = true;
        if (clr == blue) target = translate(target);
        Exit* timeout = new exit::Timeout(params.timeout);
        
        PID linCont(mtpLin);
        // PID angCont(angConsts);
        PID angCont(mtpAng);
        
        double linError = pose.pos.dist(target);
        Angle heading;
        if (angle == -1) heading = Angle(imu->get_heading(), HEADING);
        else heading = Angle(angle, HEADING);
        double prev = 0;
        while (!params.exit -> exited({.error = fabs(linError)}) && !timeout -> exited({})) {
            linError = pose.pos.dist(target) - dist;
            if (linError < 0 && params.vMin != 0) break;
            double angularError = heading.error(Angle(imu -> get_heading(), HEADING));
        
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
            //only slews when accelerating
            if (params.slew != 0) vl = std::min(prev + params.slew, vl);
            prev = vl;
            if (params.reverse) vl = -vl;
            
            this -> dt -> spinVolts({vl + va, vl - va});
            pros::delay(10);
        }
        this -> dt -> spinAll(0);
        moving = false;
        // chassMutex.give()
    }
    

void Chassis::driveAngle(double dist, double angle, MotionParams params = { .vMin = 0, .slew = 2}, bool absolute) {
    // chassMutex.take();
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { driveAngle(dist, angle, params);});
        pros::delay(10);
        return;
    }
    if (params.exit == nullptr) {
        params.exit = new exit::Range(20, 20);
    }
    this -> waitUntilSettled();
    // double prev = dt -> getAvgVelocity();
    moving = true;
    if (clr == blue) angle = neg(angle);
    Angle targ = Angle(angle, HEADING);
    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont = PID(this -> linConsts);
    PID angCont = PID(this -> angConsts);
    double linError = dist;
    double traveled = 0;
    if (!absolute) this -> dt -> tare_position();
    // double prev = chassConsts.wheelDia * M_PI * (vertEnc->get_position()/36000.0);
    double prev =  dt -> getAvgVelocity(true);
    while (!params.exit -> exited({.error = fabs(linError)}) && !timeout -> exited({})) {
        linError = dist - (this -> dt -> getAvgPosition());
        if (params.vMin > 0 && linError * sign(dist) < 0) {
            break;
        }
        double angularError = targ.error(Angle(imu -> get_heading(), HEADING));
    
        if (std::abs(angularError) < this -> angConsts.tolerance) {
            angularError = 0;
        }
        double va = angCont.out(angularError);
        double vl = linCont.out(linError);
        if (std::abs(vl) < params.vMin) {
            vl = params.vMin * sign(vl);
        }
        if (std::abs(vl) > params.vMax) {
            vl = params.vMax * sign(vl);
        }
        
        if (std::abs(vl) + std::abs(va) > 127) {
          vl = (127 - std::abs(va)) * sign(vl);
        }
        if (params.slew != 0) vl = keejLib::sign(vl) * std::min(fabs(prev) + params.slew, fabs(vl));
        prev = vl;
        
        this -> dt -> spinVolts({vl + va, vl - va});
        pros::delay(20);
    }
    this -> dt -> spinAll(0);
    moving = false;
    // chassMutex.give();
}

void Chassis::mtpoint(Pt target, MotionParams params = {.slew = 4}) {
    // chassMutex.take();
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { mtpoint(target, params);});
        pros::delay(10);
        return;
    }
    this -> waitUntilSettled();
    if (params.exit == nullptr) {
        params.exit = new exit::Range(3, 20);
    }
    moving = true;
    if (clr == blue) target = translate(target);

    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont(mtpLin);
    PID angCont(mtpAng);
    double dist = pose.pos.dist(target);
    double linearError = dist;
    double pct = 0;
    bool close = false;
    int dir = params.reverse ? -1 : 1;
    double angularVel;
    int prevSide = -2;
    int side;
    double maxSlipSpeed;
    double prevLin = dt -> getAvgVelocity(true);
    //https://www.desmos.com/calculator/cnp2vnubnx
    while (!timeout -> exited({}) && !params.exit -> exited({.error = dist, .pose = pose })) {
        Angle currHeading = pose.heading;
        Angle targetHeading = absoluteAngleToPoint(pose.pos, target);
        if (dir < 0) targetHeading = Angle(reverseDir(targetHeading.heading()), HEADING);
        double angularError = targetHeading.error(currHeading);
        double adjHeading = pose.heading.rad();
        if (adjHeading > M_PI) adjHeading = - (2*M_PI - adjHeading);
        double m = tan(adjHeading);
        if (params.debug) {
            std::printf("curr: (%.3f, %.3f, %.3f) \n", pose.pos.x, pose.pos.y, pose.heading.heading());
            std::printf(" target: (%.3f, %.3f, %.3f) \n", target.x, target.y, targetHeading.heading());
            std::printf(" angularError: %.3f \n", angularError);
        }

        if (close) {
            if (std::fabs(angularError) > 20) {
                angularError = 0;
            }
            double tx = (m *(target.y - pose.pos.y + pose.pos.x*m + target.x/m)) / (m*m + 1);
            double ty = m * (tx - pose.pos.x) + pose.pos.y;
            linearError = pose.pos.dist({tx,ty});
            
            side = pose.pos.y < (- 1 / m) * (pose.pos.x - tx) + ty;
            if (side == 0) side = -1;
            if (adjHeading < 0) side = -side;
            dir = side * (params.reverse ? -1 : 1);
        }
        else {
            linearError = pose.pos.dist(target);
            side = pose.pos.y < (- 1 / m) * (pose.pos.x - target.x) + target.y;
            if (side == 0) side = -1;
            if (adjHeading < 0) side = -side;
            dir = side * (params.reverse ? -1 : 1);
        }
        if (prevSide != -2) {
            if (side != prevSide && params.vMin != 0) {
                break;
            }
        }
        if (params.within > 0) linearError -= params.within;
        dist = linearError;
        prevSide = side;
        if (fabs(linearError) < params.settleRange && !close) close = true;
        linearError *= cos(toRad(angularError));
        angularVel = angCont.out(angularError);

        double linearVel = dir * linCont.out(linearError);
        
        double radius = 1 / fabs(curvature(pose, {target, Angle(0, RAD)}));
        if (params.drift == 0) maxSlipSpeed = 127;
        else maxSlipSpeed = sqrt(params.drift * radius * 9.8);
        linearVel = std::clamp(linearVel, -maxSlipSpeed, maxSlipSpeed);
        
        linearVel = std::max(fabs(linearVel), params.vMin) * sign(linearVel);
        linearVel = std::min(fabs(linearVel), params.vMax) * sign(linearVel);
        if (params.slew != 0) linearVel = keejLib::sign(linearVel) * std::min(fabs(prevLin) + params.slew, fabs(linearVel));
        prevLin = linearVel;
        if (std::abs(linearVel) + std::abs(angularVel) > 127) {
            linearVel = (127 - std::abs(angularVel)) * sign(linearVel);
        }
        double lVel = linearVel + angularVel;
        double rVel = linearVel - angularVel;
        // double x = angCont.out(angularError)
        dt -> spinVolts({lVel, rVel});
        pros::delay(10);
        // std::cout << lVel << " " << rVel << std::endl;
    }
    dt -> spinAll(0);
    moving = false;
    // chassMutex.give();
}
void Chassis::mtpose(Pose target, double dLead, MotionParams params) {
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { mtpose(target, dLead, params);});
        pros::delay(10);
        return;
    }
    this -> waitUntilSettled();
    moving = true;
    
    Exit* timeout = new exit::Timeout(params.timeout);
    PID linCont(linConsts);
    PID angCont(angConsts);
    
    bool close = false;
    Pt carrot = target.pos;
    int dir = params.reverse ? -1 : 1;
    double linearError = pose.pos.dist(target.pos);;
    double angularVel = 0;
    double radius = 0;
    
    while (!timeout -> exited({}) && !params.exit -> exited({.error = pose.pos.dist(target.pos), .pose = pose })) {
        if (!close) {
            double h = std::hypot(pose.pos.x - target.pos.x, pose.pos.y - target.pos.y);
            carrot = {target.pos.x - (h * sin(toRad(target.heading.heading())) * dLead), target.pos.y - (h * cos(toRad(target.heading.heading())) * dLead)};
        }
        Angle currHeading = pose.heading;
        Angle targetHeading = absoluteAngleToPoint(pose.pos, carrot);
        if (dir < 0) targetHeading = Angle(reverseDir(targetHeading.heading()), HEADING);
        double angularError = targetHeading.error(currHeading);
        // std::cout << angularError << std::endl;`
        double adjHeading = pose.heading.rad();
        if (adjHeading > M_PI) adjHeading = - (2*M_PI - adjHeading);
        double m = tan(adjHeading);
        Pt adjTarg;
        if (close) {
            if (std::fabs(angularError) > 20) {
                angularError = 0;
            }
            // angularVel = 0;
            double tx = (m *(target.pos.y - pose.pos.y + pose.pos.x*m + target.pos.x/m)) / (m*m + 1);
            double ty = m * (tx - pose.pos.x) + pose.pos.y;
            adjTarg = {tx,ty};
            linearError = pose.pos.dist({tx,ty});
            if (linearError < params.settleRange && !close) close = true;
            
            int side = pose.pos.y < (- 1 / m) * (pose.pos.x - tx) + ty;
            if (side == 0) side = -1;
            if (adjHeading < 0) side = -side;
            dir = side * (params.reverse ? -1 : 1);
            
            linearError *= cos(toRad(angularError));
            // std::cout << tx << " " << ty << std::endl;
            // std::printf("(%.3f, %.3f, %.3f, (%.3f, %.3f), %f),", pose.pos.x, pose.pos.y, toDeg(adjHeading), tx, ty, radius);
        }
        else {
            adjTarg = carrot;
            linearError = pose.pos.dist(carrot);
            if (linearError < params.settleRange && !close) close = true;
            // std::printf("(%.3f, %.3f, %.3f, (%.3f, %.3f), %f),", pose.pos.x, pose.pos.y, toDeg(adjHeading), carrot.x, carrot.y, radius);
            // 
            // double h = pose.heading.heading();
            // if (h > 180) h = - (360 - h);
            // h = toRad(h);
            // std::printf("(%.3f, %.3f, %.3f, (%.3f, %.3f), %f),", pose.pos.x, pose.pos.y, toDeg(adjHeading), carrot.x, carrot.y, radius);
            int side = pose.pos.y < (- 1 / m) * (pose.pos.x - carrot.x) + carrot.y;
            if (side == 0) side = -1;
            if (adjHeading < 0) side = -side;
            dir = side * (params.reverse ? -1 : 1);
            
            linearError *= sign(cos(toRad(angularError)));
            // std::printf("(%.3f, %.3f, %.3f),", pose.pos.x, pose.pos.y, pose.heading.heading());
        }
        angularVel = angCont.out(angularError);
        // std::cout << close << std::endl;
        
        // std::cout << angularVel << std::endl;
        // std::cout << linearError << std::endl;
        double linearVel = dir * linCont.out(linearError);
        
        radius = 1 / fabs(curvature(pose, {adjTarg, target.heading}));
        double maxSlipSpeed = sqrt(params.drift * radius * 9.8);
        // double maxSlipSpeed = 127 - std::min(127.0, (fabs(angularError) * params.drift));
        linearVel = std::clamp(linearVel, -maxSlipSpeed, maxSlipSpeed);
        // linearVel = std::clamp(linearVel, -params.vMin, params.vMin);
        if (std::abs(linearVel) + std::abs(angularVel) > 127) {
            linearVel = (127 - std::abs(angularVel)) * sign(linearVel);
        }
        
        double lVel = linearVel + angularVel;
        double rVel = linearVel - angularVel;
        // double x = angCont.out(angularError)
        // 
        dt -> spinVolts({lVel, rVel});
        // 
        pros::delay(10);

    }
    moving = true;
}

}