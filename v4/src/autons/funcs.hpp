#pragma once
#include "../robot.hpp"
#include "keejLib/util.h"
#include "main.h"
#include "../globals.hpp"
using namespace robot;
#define h(x) keejLib::Angle(x, HEADING)


void turnToRing(int timeout) {
    int sigId;
    int desiredCenter;
    switch (glb::color) {
        case blue:
            sigId = 1;
            desiredCenter = 158;
            break;
        case red:
            sigId = 0;
            desiredCenter = 158;
            break;
        case none:
            sigId = 2;
    }
    Stopwatch timer;
    keejLib::PID pidCont({.kp = 0.1});
    
    while (timer.elapsed() < timeout) {
        auto x = robot::vision.get_by_sig(0, sigId);
        int center = x.x_middle_coord;
        std::cout << center << std::endl;
        int error = center - desiredCenter;
        double vel = pidCont.out(error);
        pros::delay(10);
        // robot::dt.spinVolts(vel, -vel);
    }
}

void intakeCorner(double ang1, double ang2) {
    intake.move(127);
    chass.driveAngle(1190, ang1, {.timeout = 700,.vMin = 55, .vMax = 60, .slew = 3});
    intake.setJamProtection(false);
    chass.driveAngle(-185, ang1, {.timeout = 480, .vMax = 35});
    intake.setJamProtection(true);
    tsukasa.toggle();
    intake.move(127);
    pros::delay(300);
    chass.driveAngle(890, ang2, {.timeout = 680, .vMax = 60, .slew = 2.4});
    intake.setJamProtection(false);
    tsukasa.toggle();
}