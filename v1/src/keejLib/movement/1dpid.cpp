#include "keejLib/control.h"
#include "keejLib/lib.h"
#include "keejLib/util.h"

namespace keejLib {
    
void Chassis::turn(double angle, MotionParams params = {.async = false, .timeout = 2000, .vMin = 0}) {
    moving = true;
    if (params.async) {
        params.async = false;
        pros::Task task([&]() { turn(angle, params);});
        pros::delay(10);
        return;
    }
    Angle targ = Angle(angle, HEADING);
    Exit* timeout = new exit::Timeout(params.timeout);
    // Exit* range = new exit::Range(params.settleRange, params.settleTime);
    PID cont = PID(this -> angConsts);
    double error = targ.error(Angle(imu -> get_rotation(), HEADING));
    while (!params.exit -> exited({.error = fabs(error)}) && !timeout -> exited({})) {
        error = targ.error(Angle(imu -> get_rotation(), HEADING));
        double vel = cont.out(error);
        this -> dt -> spinVolts(vel, -vel);
        pros::delay(10);
    }
    this -> dt -> spinVolts(0, 0);
    moving = false;
}

}