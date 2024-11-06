#pragma once

#include "lift.h"
namespace lift {
    
class Lift;

class LiftState {
    public:
        virtual void enter(Lift* lift) = 0;
        virtual void next(Lift* lift) = 0;
        virtual void prev(Lift* lift) = 0;
        virtual void exit(Lift* lift) = 0;
        virtual ~LiftState() {}
};

}