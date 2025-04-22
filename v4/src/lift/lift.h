#pragma once

#include "keejLib/util.h"
#include "main.h"
#include "keejLib/lib.h"
#include "pros/rtos.hpp"
#include "states.h"

namespace keejLib {
class Lift {
    public:
        Lift(pros::Motor *lift, pros::Rotation *rot, PIDConstants constants);
       	void next();
        void prev();
        void toggle();
        void score();
       	void setState(LiftState newState);
        void setTarget(LiftState state);
        void startControl();
        void spin(double voltage);
        void setControl(bool on);
    
    private:
        pros::Motor *motor;
        pros::Rotation *rot;
        pros::Optical *optical;
        pros::Task *task = nullptr;
        // stde::bimap<LiftState, LiftState> stateMap = {
        //     {idle, one},
        //     {one, two},
        //     {two, prime},
        //     {prime, lower},
        //     {lower, lowest},
        //     {lowest, idle}
        // };
        std::unordered_map<LiftState, LiftState> fwdMap = {
            {LiftState::idle, LiftState::one},
            {LiftState::one, LiftState::two},
            {LiftState::two, LiftState::prime},
            {LiftState::prime, LiftState::lower},
            {LiftState::lower, LiftState::lowest},
            {LiftState::lowest, LiftState::idle}
        };
        std::unordered_map<LiftState, LiftState> revMap = {
            {LiftState::one, LiftState::idle},
            {LiftState::two, LiftState::one},
            {LiftState::prime, LiftState::two},
            {LiftState::lower, LiftState::prime},
            {LiftState::lowest, LiftState::lower},
            {LiftState::idle, LiftState::lowest}
        };
        std::unordered_map<LiftState, double> valueMap = {
            {LiftState::idle, 0},
            {LiftState::one, 174-40},
            {LiftState::two, 226-30},
            {LiftState::prime, 476},
            {LiftState::lower, 360 + 290},
            {LiftState::lowest, 360 + 700}
        };
        
        PID pid;
        double angleOffset = 0;
        double kf = 0;
        double target;
        double error = 0;
        bool off = false;
        Stopwatch idleTimer;
        Stopwatch calibrateTimer;
        const int snapRange = 30;
        
       	LiftState currentState;

        void calibrate();
        void control();
        void updatePID(double error);
};
}