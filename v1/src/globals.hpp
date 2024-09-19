#include "keejLib/lib.h"
#pragma once
using namespace keejLib;

namespace glb {
    
std::vector<Controller::driveMode> driveModes = {keejLib::Controller::driveMode::arcade, keejLib::Controller::driveMode::tank, keejLib::Controller::driveMode::reverseArcade, keejLib::Controller::driveMode::curvature};
// - globals
void (*auton)();

keejLib::CompState compState = keejLib::initialize;

keejLib::Controller::driveMode mode = keejLib::Controller::arcade;

Color color;

bool isMatch;

}