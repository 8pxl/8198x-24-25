#pragma once
#include "../lift/states.h"
#include "pros/rtos.hpp"

namespace keejLib {
class RobotState {
public:
    static RobotState* instance;
    static RobotState* getInstance() {
        if (instance == nullptr) {
            instance = new RobotState();
        }
        return instance;
    }

    LiftState getLiftState();
    void setLiftState(LiftState state);

private:
    pros::Mutex mutex;
    RobotState() = default;
    LiftState liftState = LiftState::idle;
};
} // namespace keejLib