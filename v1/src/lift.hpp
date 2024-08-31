#pragma once

#include "main.h"
#include "keejLib/lib.h"
// #include "keejLib/angles.hpp"
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
            {mid, 340},
            {raised, 800},
        };
    private:
        pros::Motor *lift;
        pros::Rotation *rot;
        pros::Task *task = nullptr;
        PID pid;
        double target = 0;
        double prevAngle;
        double angle = 0;
        
        state currState = resting;
        state nextState = raised;
    
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, PIDConstants constants) : lift(lift), rot(rot) {
            pid = PID(constants);
        }
        void initTask() {
            if (task == nullptr) {
                task = new pros::Task{[=] {
                    prevAngle = rot -> get_angle();
                    while (true) {
                        angle += angError((rot -> get_angle()) / 100.0, prevAngle);
                        prevAngle = rot -> get_angle()/100.0;
                        control();
                        
                        pros::delay(10);
                    }
                }};
            }
        }
        
        void control() {
            double error = target - (angle);
            if (fabs(error) > 200 & fabs(error) < 400 && currState == resting) {
                lift -> move(-40);
            }
            else if (fabs(error) < 200 && currState == resting) {
                lift -> move(0);
            }
            else {
                lift -> move(pid.out(error));
            }
        }
        
        void setTarget(double t) {
            target = t;
        }
        
        state setSate(state s) {
            state prev = currState;
            currState = s;
            setTarget(stateVal[s]);
            return prev;
        }
        
        void toggle() {
            nextState = setSate(nextState);
        }
        
        void switchState() {
            switch (currState) {
                case resting:
                    setSate(nextState);
                    break;
                case mid:
                    setSate(raised);
                    break;
                case raised:
                    setSate(mid);
                    break;
            }
        }
};