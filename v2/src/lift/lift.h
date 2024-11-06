#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "vStates.h"
using namespace keejLib;

namespace lift {

class LiftState;

class Lift{
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, pros::Optical *optical, PIDConstants constants);
       	inline LiftState* getCurrentState() const { return currentState; }
       	void next();
        void prev();
       	void setState(LiftState& newState);
        void setTarget(double target);
        void startControl();
    
    private:
        pros::Motor *motor;
        pros::Rotation *rot;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        
        PID pid;
        double target;
        
       	LiftState* currentState;
        
        void control();
        void updatePID(double error);
        void home();
};
}