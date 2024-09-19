#pragma once

#include "../robot.hpp"
#include "../globals.hpp"

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
        while (true) {
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