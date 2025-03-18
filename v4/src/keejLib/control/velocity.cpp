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
    vl = sign(vl) * std::clamp(fabs(vl), linMin, linMax);
    va = sign(va) * std::clamp(fabs(va), angMin, angMax);
    
    //desaturate
    double left = vl - va;
    double right = vl + va;
    double sum = fabs(left) + fabs(right);
    if (sum >= 127) {
        left /= sum;
        right /= sum;
    }
    return {left, right};
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