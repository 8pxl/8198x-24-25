#pragma once

#include "keejLib/util.h"
#include "main.h"
#include "keejLib/lib.h"
#include "pros/optical.hpp"
// #include "robot.hpp"
#include <cstdlib>
// #include "keejLib/angles.hpp"
// #include "keejLib/
using namespace keejLib; 

class Lift {
    public:
        enum state {
            resting,
            mid,
            raised,
        };
        
        std::unordered_map<state, double> stateVal = {
            {resting, 0},
            {mid, 600},
            {raised, 800},
        };
    private:
        pros::Motor *lift;
        pros::Rotation *rot;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        keejLib::Pis *redirect;
        PID pid;
        double target = 0;
        double prevAngle;
        double angle = 0;
        std::pair<int, int> color;
        
        state currState = resting;
        state nextState = raised;
        
        Stopwatch sw;
    
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, pros::Optical *optical, keejLib::Pis *redirect, PIDConstants constants) : lift(lift), rot(rot), optical(optical), redirect(redirect) {
            pid = PID(constants);
        }
        void initTask() {
            if (task == nullptr) {
                task = new pros::Task{[=] {
                    prevAngle = rot -> get_angle();
                    while (true) {
                        if (currState == resting) {
                            if (sw.elapsed() > 3000 && fabs(angle) <= 9) {
                                rot -> reset_position();
                            }
                        }
                        else {
                            sw.reset();
                        }
                        angle -= angError((rot -> get_angle()) / 100.0, prevAngle);
                        prevAngle = rot -> get_angle()/100.0;
                        control();
                        
                        pros::delay(10);
                    }
                }};
            }
        }
        
        void control() {
            double error = target - (angle);
            if (fabs(error) > 150 && fabs(error) < 400 && currState == resting) {
                lift -> move(-80);
            }
            else if (fabs(error) < 150 && currState == resting) {
                lift -> move(0);
            }
            else {
                lift -> move(pid.out(error));
            }
            double hue = optical->get_hue();
            
            if (currState != resting && redirect ->getState()) {
                optical -> set_led_pwm(100);
                if (hue >= color.first && hue <= color.second) {
                    setState(resting);
                }
            }
            else {
                optical -> set_led_pwm(0);
            }
            
        }
        
        void setTarget(double t) {
            target = t;
        }
        
        void setState(state s) {
            nextState = currState;
            currState = s;
            setTarget(stateVal[s]);
        }
        
        void toggle() {
            if (currState == resting) {
                setState(nextState);
            }
            else {
                setState(resting);
            }
        }
        
        state getNext(state s) {
            switch (s) {
                case mid:
                    return (raised);
                    break;
                case raised:
                    return (mid);
                    break;
                case resting:
                    return resting;
            }
        }
        
        void switchState() {
            state s;
            if (currState == resting) {
                s = getNext(nextState);
            }
            else {
                s = getNext(currState);
            }
            setState(s);
        }
        
        void setColor(Color clr) {
            if (clr == red) {
                color = {6, 17};
            }
            else {
                color =  {200, 230};
            }
        }
};