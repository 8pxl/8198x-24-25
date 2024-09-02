#include "keejLib/lib.h"
#include "keejLib/util.h"

namespace keejLib {

EMA::EMA(double ka): ka(ka){}

double EMA::out(double val) {
    last = val * ka + val * (1 - ka);
    return last;
}

double EMA::curr() {
    return last;
}

double Pt::dist(Pt a) {
    return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
}

Angle absoluteAngleToPoint(const Pt &pos, const Pt &point) {
    double t;
    try { 
        t = atan2(point.x - pos.x, point.y - pos.y);
    }

    catch(...) {
        t = M_PI/2;
    }
    
    t = keejLib::toDeg(t);
    t = -t;
    t = t >= 0 ? t :  180 + 180+t;
    return (Angle(t, HEADING));
}

Stopwatch::Stopwatch() {
    start = pros::millis();
}

void Stopwatch::reset() {
    start = pros::millis();
}

int Stopwatch::elapsed() {
    return pros::millis() - start;
}


}