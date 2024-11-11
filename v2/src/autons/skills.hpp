#include "constants.hpp"

using namespace robot;

void skills() {
    lb.setAutoControl(false);
    chass.setTurn(_90);
    chass.setAng(_angBig);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    
    lb.next();
    lb.next();
    chass.driveAngle(-400, 0, {.async = false, .timeout = 600, .vMin = 0, .exit = new Range(800, 40)});
    clamp.toggle();
}