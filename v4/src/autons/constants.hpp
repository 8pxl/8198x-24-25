#pragma once

#include "keejLib/control.h"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
using namespace robot;
using namespace exit;

using namespace keejLib;

PIDConstants _180 {
    .kp = 5.3,
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
    .kp = 6,
    .ki = 0.5,
    .kd = 66,
    .maxIntegral = 100,
    .tolerance = 0.001,
    .integralThreshold = 2.5,
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
    .kp = 6.9,
    .ki = 0.4,
    .kd = 26,
    .maxIntegral = 100,
    .tolerance = 0.01,
    .integralThreshold = 1,
};

PIDConstants _linSmall {
    .kp = 0.09,
    .ki = 0,
    .kd = 0.03,
    .maxIntegral = 300,
    .tolerance = 20,
    .integralThreshold = 100,
};

PIDConstants _lin {
    .kp = 0.163,
    .ki = 0,
    .kd = 0.03,
    .maxIntegral = 0,
    .tolerance = 20,
    .integralThreshold = 0,
};

PIDConstants _linBigger {
    .kp = 0.3,
    .ki = 0,
    .kd = 0.03,
    .maxIntegral = 0,
    .tolerance = 20,
    .integralThreshold = 0,
};
// // 
// PIDConstants _lin {
//     .kp = 0.93,
//     .ki = 0,
//     .kd = 0,
//     .maxIntegral = 0,
//     .tolerance = 0,
//     .integralThreshold = 0,
// };
PIDConstants _angSmall {
    .kp = 1.2,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 0,
    .tolerance = 0,
    .integralThreshold = 0,
};

PIDConstants _ang {
    .kp = 2,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 0,
    .tolerance = 0,
    .integralThreshold = 0,
};

PIDConstants _angBig {
    .kp = 3,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 0,
    .tolerance = 0,
    .integralThreshold = 0,
};

PIDConstants _chassLin = {
    .kp = 4.2,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _chassAngSmall = {
    .kp = 1.5,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _chassAng = {
    .kp = 2.3,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _chassAngBig = {
    .kp = 2.6,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _mposeLin = {
    .kp = 4.3,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _mposeAng = {
    .kp = 3,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};

PIDConstants _mposeAngMogo = {
    .kp = 0.2,
    .ki = 0,
    .kd = 0,
    .maxIntegral = 1000,
    .tolerance = 0,
    .integralThreshold = 3,
};
PIDConstants _ttp {
    .kp = 8,
    .ki = 0.5,
    .kd = 66,
    .maxIntegral = 100,
    .tolerance = 0.001,
    .integralThreshold = 2.5,
};
