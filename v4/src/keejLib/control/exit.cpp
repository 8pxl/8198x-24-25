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

exit::Perp::Perp(Pt target, Angle targetHeading): target(target), targetHeading(targetHeading) {}

exit::Perp::Perp(Pt target): target(target) {}

int exit::Perp::computeSide(exitParams params) {
    return keejLib::computeSide(
        params.pose.pos, 
        target.value_or(params.target),
        targetHeading.value_or(params.targetHeading)
    );
}

bool exit::Perp::exited(exitParams params) {
    int newSide = computeSide(params);
    if (side.has_value() && newSide != side.value()) {
        return true;
    }
    side = newSide;
    return false;
}

exit::Within::Within(Pt target, double range, int timeout) : target(target), range(range), timeout(timeout), sw(Stopwatch()) {};

bool exit::Within::exited(exitParams params) {
    if (params.pose.pos.dist(target) > range) {
        sw.reset();
    }
    return (sw.elapsed() > timeout);
}
}