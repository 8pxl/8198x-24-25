#include "robotState.h"

namespace keejLib {
    RobotState* RobotState::instance = nullptr;

    LiftState RobotState::getLiftState()  {
        mutex.take();
        auto returnVal = liftState;
        mutex.give();
        return returnVal; 
    }

    void RobotState::setLiftState(LiftState state) {
        mutex.take();
        liftState = state;
        mutex.give();
    }
}