#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "keejLib/angles.hpp"
using namespace keejLib; 

class Lift {
    private:
        pros::Motor *lift;
        pros::Rotation *rot;
        pros::Task *task = nullptr;
        PID pid;
        double target = 0;
        double restAngle = 10;
        double prevAngle;
        double angle = 0;
        int count = 0;
        
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
        
        state currState = resting;
        state nextState = raised;
    
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, PIDConstants constants, double restAngle) : lift(lift), rot(rot), restAngle(restAngle) {
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
            if (count % 50 == 0) {
                std::cout << error << std::endl;
            }
            count++;

        }
        
        void setTarget(double t) {
            target = t + restAngle;
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
};