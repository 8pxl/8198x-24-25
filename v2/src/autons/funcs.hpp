#include "../robot.hpp"
#include "keejLib/util.h"
#include "main.h"
#include "../globals.hpp"

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