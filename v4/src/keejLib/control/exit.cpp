#include "keejLib/control.h"
#include "keejLib/lib.h"
#include <cmath>

namespace keejLib {
exit::Timeout::Timeout(int timeout) : sw(Stopwatch()), timeout(timeout) {};

bool exit::Timeout::exited(exitParams params) {
    return (sw.elapsed() > timeout);
}

exit::Range::Range(double range, int timeout) : range(range), timeout(timeout), sw(Stopwatch()) {};

bool exit::Range::exited(exitParams params) {
    if (params.error > range) {
        sw.reset();
    }
    return (sw.elapsed() > timeout);
}

exit::Perp::Perp(Pt target, Angle targetHeading): target(target), targetHeading(targetHeading) {
}

bool exit::Perp::exited(exitParams params) {
    int newSide = computeSide(
        params.pose.pos, 
        target.value_or(params.target),
        targetHeading.value_or(params.targetHeading)
    );
    if (side.has_value() && newSide != side.value()) {
        return true;
    }
    side = newSide;
    return false;
}
}