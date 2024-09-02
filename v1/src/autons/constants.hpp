#include "keejLib/lib.h"

using namespace keejLib;

PIDConstants chassLin = {
    .kp = 2.8,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants chassAng = {
    .kp = 1.2,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};