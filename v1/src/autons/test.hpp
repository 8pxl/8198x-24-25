#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/util.h"

using namespace robot;
void test() {
    chass.setAng(chassAng);
    chass.setLin(chassLin);
    
    chass.mtp({14, 14, Angle(45, keejLib::DEG)}, 0.3, {false, 6000, 0, new exit::Range(0.1, 6000), 0, 0});
    // 
    // std::cout << absoluteAngleToPoint({0,0}, {10,10}).heading() << std::endl;
    // chass.turn(absoluteAngleToPoint({0,0}, {10,10}).heading(), {.async = false, .timeout = 2000, .vMin = 0, .exit = new exit::Range(0.01, 500)});
}