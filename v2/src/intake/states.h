#pragma once

#include "main.h"
#include "keejLib/lib.h"
#include "intake.h"
#include "vStates.h"


using namespace keejLib;

namespace intake {
class Intake;

class Idle : public IntakeState {
    public: 
        void enter(Intake* Intake) override;
        void next(Intake* Intake) override;
        void prev(Intake* Intake) override;
        void control(Intake* Intake) override;
        void exit(Intake* Intake) override;
        State getState() override;

        static IntakeState& getInstance();
    private:
    	Idle() {}
    	Idle(const Idle& other);
    	Idle& operator=(const Idle& other);
};

class On : public IntakeState {
    public: 
        void enter(Intake* Intake) override;
        void next(Intake* Intake) override;
        void prev(Intake* Intake) override;
        void control(Intake* Intake) override;
        void exit(Intake* Intake) override;
        State getState() override;
        static IntakeState& getInstance();
    private:
    	On() {}
    	On(const On& other);
    	On& operator=(const On& other);
};

class Sort : public IntakeState {
    public: 
        void enter(Intake* Intake) override;
        void next(Intake* Intake) override;
        void prev(Intake* Intake) override;
        void control(Intake* Intake) override;
        void exit(Intake* Intake) override;
        State getState() override;
        static IntakeState& getInstance();
    private:
    	Sort() {}
    	Sort(const Sort& other);
    	Sort& operator=(const Sort& other);
};
}