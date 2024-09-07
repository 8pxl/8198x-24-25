#include "keejLib/control.h"
#include "keejLib/lib.h"

using namespace keejLib;

PIDConstants _180 {
    .kp = 5.9,
    .ki = 0.6,
    .kd = 70,
    .maxIntegral = 20,
    .tolerance = 0.05,
    .integralThreshold = 1.1,
};

PIDConstants _135 {
    .kp = 6.3,
    .ki = 0.43,
    .kd = 49,
    .maxIntegral = 100,
    .tolerance = 0.01,
    .integralThreshold = 1,
};

PIDConstants _90 {
    .kp = 6.3,
    .ki = 0.7,
    .kd = 56.5,
    .maxIntegral = 100,
    .tolerance = 0.001,
    .integralThreshold = 1,
};

PIDConstants _45 {
    .kp = 4.9,
    .ki = 0.4,
    .kd = 26,
    .maxIntegral = 100,
    .tolerance = 0.01,
    .integralThreshold = 1,
};

PIDConstants _30 {
    .kp = 5.9,
    .ki = 0.6,
    .kd = 70,
    .maxIntegral = 100,
    .tolerance = 0.05,
    .integralThreshold = 1,
};

PIDConstants _15 {
    .kp = 4.9,
    .ki = 0.4,
    .kd = 26,
    .maxIntegral = 100,
    .tolerance = 0.01,
    .integralThreshold = 1,
};

PIDConstants _5 {
    .kp = 4.9,
    .ki = 0.4,
    .kd = 26,
    .maxIntegral = 100,
    .tolerance = 0.01,
    .integralThreshold = 1,
};

PIDConstants _lin {
    .kp = 0.13,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 0,
    .tolerance = 40,
    .integralThreshold = 0,
};

PIDConstants _ang {
    .kp = 1.4,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 0,
    .tolerance = 0,
    .integralThreshold = 0,
};

// PIDConstants chassLin = {
//     .kp = 4,
//     .ki = 0,
//     .kd = 0,
//     .maxIntegral = 1000,
//     .tolerance = 0,
//     .integralThreshold = 3,
// };

// PIDConstants chassAng = {
//     .kp = 1.4,
//     .ki = 0,
//     .kd = 0,
//     .maxIntegral = 1000,
//     .tolerance = 0,
//     .integralThreshold = 3,
// };
