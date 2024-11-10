#pragma once

#include "keejLib/util.h"
#include "main.h"
#include "keejLib/lib.h"
#include "vStates.h"

using namespace keejLib;

namespace ifsm {
    
class IntakeState;

class Intake {
    public:
        Intake(pros::Motor *intake, pros::Optical *optical, Color sort);
       	inline IntakeState* getCurrentState() const { return currentState; }
       	void next();
       	void setState(IntakeState& newState);
        void move(double speed);
        void setSpeed(double speed);
        void startControl();
        double getSpeed();
        Color getOptical();
        Color getColor();
        void setPwm(int pwm);
        void setSorting(bool state);
        bool getSorting();
    
    private:
        pros::Motor *motor;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        
        double speed;
       	IntakeState* currentState;
        bool sort = true;
        
        void control();
        Color color;
};
}