#pragma once
#include "keejLib/control.h"
#include "keejLib/lib.h"
#include <numeric>

namespace keejLib {
    
VelocityController::VelocityController(PIDConstants constants, double ka): pid(PID(constants)), ema(EMA(ka)) {}

void VelocityController::setVelocity(double v) {target = v;}

double VelocityController::getVoltage(double curr) {
    double error = target - curr;
    return(pid.out(error));
}

ChassVelocities VelocityManager::update(std::pair<double, double> vals) {
    if (slew.has_value()) vl = sign(vals.first) * std::min(fabs(vl) + slew.value(), fabs(vals.first));
    // std::cout << linMin << " " << linMax << " " << angMin << " " << angMax << std::endl;
    vl = sign(vals.first) * std::clamp(fabs(vals.first), linMin, linMax);
    va = sign(vals.second) * std::clamp(fabs(vals.second), angMin, angMax);
    // std::cout << "vl: " << vl << " va: " << va << std::endl;
    //desaturate;
    // vl = (127 * (1+ratio)) / (2*ratio);
    // va = 127 - vl;
    double left = vl + va;
    double right = vl - va;
    double sum = fabs(left) + fabs(right);
    if (sum < 127) return {left, right};
    return {127 * (left/sum), 127 * (right/sum)};
}
void VelocityManager::setLinMin(double newLinMin) {
    linMin = newLinMin;
}

void VelocityManager::setLinMax(double newLinMax) {
    linMax = newLinMax;
    if (linMin > linMax) {
        //should not be here
        std::cout << "lin min > max !!" << std::endl;
        std::swap(linMin, linMax); 
    }
}

void VelocityManager::setAngMin(double newAngMin) {
    angMin = newAngMin;
}

void VelocityManager::setAngMax(double newAngMax) {
    angMax = newAngMax;
    if (angMin > angMax) {
        //should not be here
        std::cout << "ang min > max !!" << std::endl;
        std::swap(angMin, angMax);
    }
}

void VelocityManager::setSlew(double newSlew) {
    slew = newSlew;
}
}