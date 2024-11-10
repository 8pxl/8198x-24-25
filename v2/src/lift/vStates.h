#pragma once

#include "lift.h"
namespace lift {


class Lift;

class LiftState {
    public:
        enum State {
            idle,
            one,
            two,
            prime,
            lower,
            lowest
        };    
        virtual void enter(Lift* lift) = 0;
        virtual void next(Lift* lift) = 0;
        virtual void prev(Lift* lift) = 0;
        virtual void toggle(Lift* lift) = 0;
        virtual void control(Lift* lift) = 0;
        virtual void exit(Lift* lift) = 0;
        virtual State getState() = 0;
        virtual ~LiftState() {}
};

}