#include "keejLib/control.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"

namespace keejLib {
    
void Chassis::turn(double angle, MotionParams params) {
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { turn(angle, params);});
        pros::delay(10);
        return;
    }
    this -> waitUntilSettled();
    if (params.exit == nullptr) {
        params.exit = new exit::Range(1.5, 20);
    }
    moving = true;
    // if (clr == blue) angle = neg(angle);
    Angle targ = Angle(angle, HEADING);
    Exit* timeout = new exit::Timeout(params.timeout);
    PID cont = PID(this -> turnConsts);
    double error = targ.error(Angle(imu -> get_heading(), HEADING));

    while (!params.exit -> exited({.error = fabs(error)}) && !timeout -> exited({})) {
        error = targ.error(Angle(imu -> get_heading(), HEADING));
        double vel = cont.out(error);
        this -> dt -> spinVolts({vel, -vel});
        pros::delay(10);
    }
    this -> dt -> spinAll(0);
    moving = false;
}

double Chassis::turnTo(Pt target, MotionParams params) {
    // chassMutex.take();
    if (params.async) {
        params.async = false;
        double returnVal;
        pros::Task task([&]() {returnVal = turnTo(target, params);});
        pros::delay(10);
        return returnVal;
    }
    this -> waitUntilSettled();
    if (params.exit == nullptr) {
        params.exit = new exit::Range(1.5, 20);
    }
    moving = true;
    if (clr == blue) target = translate(target);
    Angle targ = absoluteAngleToPoint(pose.pos, target);
    if (params.reverse) targ = targ.reverseDir();
    Exit* timeout = new exit::Timeout(params.timeout);
    // Exit* range = new exit::Range(params.settleRange, params.settleTime);
    PID cont = PID(this -> turnConsts);
    double error = targ.error(Angle(imu -> get_heading(), HEADING));
    while (!params.exit -> exited({.error = fabs(error)}) && !timeout -> exited({})) {
        targ = absoluteAngleToPoint(pose.pos, target);
        if (params.reverse) targ = targ.reverseDir();
        error = targ.error(Angle(imu -> get_heading(), HEADING));
        double vel = cont.out(error);
        this -> dt -> spinVolts({vel, -vel});
        // std::cout << "turnto: " << error << std::endl;
        pros::delay(10);
    }
    this -> dt -> spinAll(0);
    moving = false;
    return targ.heading();
    // chassMutex.give();
}

// void Chassis::linTo(Pt target, MotionParams params) {
//     if (params.async) {
//         params.async = false;
//         pros::Task task([&]() { linTo(target, params);});
//         pros::delay(10);
//         return;
//     }
//     this -> waitUntilSettled();
//     moving = true;

//     heading = Angle(angle, HEADING);
// }
}