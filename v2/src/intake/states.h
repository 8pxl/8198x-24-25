#include "main.h"
#include "keejLib/lib.h"
#include "common.h"

using namespace keejLib;

namespace intake {


class IntakeState {
    public:
        virtual void enter(Intake* intake) = 0;
        virtual void next(Intake* intake) = 0;
        virtual void prev(Intake* intake) = 0;
        virtual void exit(Intake* intake) = 0;
        virtual ~IntakeState() {}
};

class Idle : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	Idle() {}
    	Idle(const Idle& other);
    	Idle& operator=(const Idle& other);
};

class One : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	One() {}
    	One(const One& other);
    	One& operator=(const One& other);
};

class Two : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	Two() {}
    	Two(const Two& other);
    	Two& operator=(const Two& other);
};

class Prime : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	Prime() {}
    	Prime(const Prime& other);
    	Prime& operator=(const Prime& other);
};

class Lower : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	Lower() {}
    	Lower(const Lower& other);
    	Lower& operator=(const Lower& other);
};

class Lowest : public IntakeState {
    public: 
        void enter(Intake* intake) override;
        void next(Intake* intake) override;
        void prev(Intake* intake) override;
        void exit(Intake* intake) override;
        static IntakeState& getInstance();
    private:
    	Lowest() {}
    	Lowest(const Lowest& other);
    	Lowest& operator=(const Lowest& other);
};
}