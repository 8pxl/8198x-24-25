#pragma once
#include "keejLib/lib.h"

namespace glb {
    keejLib::Color color;
    bool autonRan = false;
    
    void (*auton)();
}