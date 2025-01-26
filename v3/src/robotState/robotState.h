#pragma once
#include "../lift/states.h"

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

    LiftState getLiftState() const { return liftState; }
    void setLiftState(LiftState state) { liftState = state; }

private:
    RobotState() = default;
    LiftState liftState = LiftState::idle;
};
} // namespace keejLib