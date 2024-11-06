#pragma once

#include "main.h"
#include "keejLib/lib.h"
// #include "common.h"
#include "lift.h"
#include "vStates.h"


using namespace keejLib;

namespace lift {
    
#define ONE_RING 115
#define TWO_RING 152
#define PRIME 433.57
#define LOWER 586.59
#define LOWEST 756.39

class Lift;

class Idle : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	Idle() {}
    	Idle(const Idle& other);
    	Idle& operator=(const Idle& other);
};

class One : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	One() {}
    	One(const One& other);
    	One& operator=(const One& other);
};

class Two : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	Two() {}
    	Two(const Two& other);
    	Two& operator=(const Two& other);
};

class Prime : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	Prime() {}
    	Prime(const Prime& other);
    	Prime& operator=(const Prime& other);
};

class Lower : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	Lower() {}
    	Lower(const Lower& other);
    	Lower& operator=(const Lower& other);
};

class Lowest : public LiftState {
    public: 
        void enter(Lift* lift) override;
        void next(Lift* lift) override;
        void prev(Lift* lift) override;
        void exit(Lift* lift) override;
        static LiftState& getInstance();
    private:
    	Lowest() {}
    	Lowest(const Lowest& other);
    	Lowest& operator=(const Lowest& other);
};
}