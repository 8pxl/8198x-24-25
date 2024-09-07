#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"

using namespace robot;
using namespace exit;
void test() {
    
    // chass.mtpose({15, 15, Angle(90, keejLib::HEADING)}, 0.7, {
    //     .timeout = 6000,
    //     .settleRange = 0.5,
    //     .exit = new exit::Range(0.1, 6000),
    //     .mtpRotBias = 0,
    // });
    // chass.mtpoint({15,15}, {
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(1.6, 400),
    //     .mtpRotBias = 0,
    //     .reverse = false
    // });
    // 
    // 
    // std::cout << absoluteAngleToPoint({0,0}, {10,10}).heading() << std::endl;
    // chass.turn(absoluteAngleToPoint({0,0}, {10,10}).heading(), {.async = false, .timeout = 2000, .vMin = 0, .exit = new exit::Range(0.01, 500)});
    chass.setAng(_90);
    chass.turn(90, {.async = true, .timeout=100000, .settleRange = 5, .settleTime = 200});
    while (!chass.isSettled()) {
        prosController.print(0, 0, "%f", imu.get_heading());
    }
}

void awp() {
    // chass.driveAngle(1200, 0, {.async = false, .timeout=2000});
}

keejLib::Autons autons = {{awp},
                    {"solo awp",}};