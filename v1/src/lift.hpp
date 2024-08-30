#include "main.h"
#include "lib.h"
using namespace keejLib; 

class Lift {
    private:
        pros::Motor *lift;
        pros::Rotation *rot;
        pros::Task *task = nullptr;
        PID pid;
        double target;
        double restAngle;
        
        enum state {
            resting,
            mid,
            raised,
        };
        
        std::unordered_map<state, double> stateVal = {
            {resting, 0},
            {mid, 90},
            {raised, 130},
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
                    while (true) {
                        control();
                        pros::delay(20);
                    }
                }};
            }
        }
        
        void control() {
            double error = target - (rot -> get_angle() + restAngle);
            if (fabs(error) < 20 && currState == resting) {
                lift -> move(0);
            }
            else {
                lift -> move(pid.out(error));
            }
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