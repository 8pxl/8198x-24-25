#include "constants.hpp"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "rPos.hpp"

using namespace robot;
using namespace exit;

void test() {
    // chass.measureOffsets(5);
    chass.setLin(_lin);
    chass.setAng(_ang);
    chass.driveAngle(9, 0, {.timeout = 1500, .vMin=0, .exit = new Range(1, 100), .reverse=false});
}
keejLib::Autons autons = {{test, rPos}, {"test", "rPos"}};