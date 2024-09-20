#pragma once

#include "../robot.hpp"
#include "../globals.hpp"
#include "keejLib/util.h"
using namespace robot;

void spitColor() {
    std::pair<int, int> clr;
    
    if (glb::color == blue) {
        //opposite color
        clr = {6, 17};
    }
    else {
        clr =  {200, 230};
    }
    
    pros::Task task([=]() {
        optical.set_led_pwm(100);
        while (glb::compState == keejLib::autonomous) {
            double hue = optical.get_hue();
            if (hue >= clr.first && hue <= clr.second) {
                robot::tsukasa.toggle();
                robot::intake.move(-127);
                pros::delay(200);
                robot::intake.move(127);
                // robot::tsukasa.toggle();
                break;
            }
            else robot::intake.move(127);
            pros::delay(10);
        }
        optical.set_led_pwm(0);
    });
    pros::delay(10);
}
void stopOnColor() {
    std::pair<int, int> clr;
    
    if (glb::color == red) {
        clr = {6, 17};
    }
    else {
        clr =  {200, 230};
    }
    
    pros::Task task([=]() {
        optical.set_led_pwm(100);
        while (glb::compState == keejLib::autonomous) {
            double hue = optical.get_hue();
            if (hue >= clr.first && hue <= clr.second) {
                break;
            }
            pros::delay(10);
        }
        robot::intake.move(0);
        optical.set_led_pwm(0);
    });
    pros::delay(10);
}