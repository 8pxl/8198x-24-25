#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "../intake/intake.h"
#include "pros/rtos.hpp"
#include "vStates.h"
using namespace keejLib;

namespace lift {

class LiftState;

class Lift{
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, pros::Optical *optical, ifsm::Intake *intake, PIDConstants constants);
       	inline LiftState* getCurrentState() const { return currentState; }
       	void next();
        void prev();
        void toggle();
        void score();
       	void setState(LiftState& newState);
        void setTarget(double target);
        void startControl();
        
        double getDerivative();
        bool getReboud();
        void setRebound(bool rebound);
        double getError();
        Color getColor();
        void setAutoControl(bool on);
        bool getAutoControl();
        
        pros::Mutex autoControlMutex = pros::Mutex();
    
    private:
        pros::Motor *motor;
        pros::Rotation *rot;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        ifsm::Intake *intake;
        
        bool autoControl = true;
        
        PID pid;
        double target;
        double error = 0;
        
       	LiftState* currentState;
        
        bool rebound = false;
        void control();
        void updatePID(double error);
        void home();
};
}