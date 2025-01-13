#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "pros/rtos.hpp"
using namespace keejLib;

namespace lift {

enum LiftState {
    idle,
    one,
    two,
    prime,
    lower,
    lowest
};


class Lift{
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, PIDConstants constants);
       	void next();
        void prev();
        void toggle();
        void score();
       	void setState(LiftState newState);
        void setTarget(double target);
        void startControl();
    
    private:
        pros::Motor *motor;
        pros::Rotation *rot;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        stde::bimap<LiftState, LiftState> stateMap = {
            {idle, one},
            {one, two},
            {two, prime},
            {prime, lower},
            {lower, lowest},
            {lowest, idle}
        };
        
        PID pid;
        double angleOffset = 20;
        double kf = 0.5;
        double target;
        double error = 0;
        
       	LiftState currentState;

        void control();
        void updatePID(double error);
};
}