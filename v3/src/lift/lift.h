#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "pros/rtos.hpp"
#include <unordered_map>
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
            {idle, one},
            {one, two},
            {two, prime},
            {prime, lower},
            {lower, lowest},
            {lowest, idle}
        };
        std::unordered_map<LiftState, LiftState> revMap = {
            {one, idle},
            {two, one},
            {prime, two},
            {lower, prime},
            {lowest, lower},
            {idle, lowest}
        };
        std::unordered_map<LiftState, double> valueMap = {
            {idle, 0},
            {one, 63},
            {two, 114},
            {prime, 349},
            {lower, 360 + 121},
            {lowest, 360 + 325}
        };
        
        PID pid;
        double angleOffset = 44;
        double kf = 0;
        double target;
        double error = 0;
        bool off = false;
        
       	LiftState currentState;

        void control();
        void updatePID(double error);
};
}