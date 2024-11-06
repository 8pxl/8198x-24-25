#pragma once

#include "intake.h"
namespace ifsm {

class Intake;

class IntakeState {
    public:
        enum State {
            idle,
            on,
            sort,
        };    
        virtual void enter(Intake* lift) = 0;
        virtual void next(Intake* lift) = 0;
        virtual void prev(Intake* lift) = 0;
        virtual void control(Intake* lift) = 0;
        virtual void exit(Intake* lift) = 0;
        virtual State getState() = 0;
        virtual ~IntakeState() {}
};
}