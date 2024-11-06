#include "main.h"
#include "keejLib/lib.h"
#include "common.h"
using namespace keejLib;

namespace intake {

class Intake{
    public:
        Intake(pros::Motor *intake, pros::Optical *optical);
       	inline IntakeState* getCurrentState() const { return currentState; }
       	void next();
       	void setState(IntakeState& newState);
        void setTarget(double target);
        
        void startControl();
    
    private:
        pros::Motor *motor;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        
        PID pid;
        double target;
        
       	IntakeState* currentState;
        
        void control();
};
}