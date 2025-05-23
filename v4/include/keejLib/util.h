#pragma once
#include <string>
#include <vector>
// #include "Eigen/Eigen"
namespace keejLib {
    
    #define ALLBUTTONS {pros::E_CONTROLLER_DIGITAL_L1, pros::E_CONTROLLER_DIGITAL_L2, pros::E_CONTROLLER_DIGITAL_R1, pros::E_CONTROLLER_DIGITAL_R2, pros::E_CONTROLLER_DIGITAL_UP, pros::E_CONTROLLER_DIGITAL_DOWN, pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT, pros::E_CONTROLLER_DIGITAL_X, pros::E_CONTROLLER_DIGITAL_B, pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A}
    #define maxslew 254
    typedef void(*fptr)();
    struct Autons{std::vector<fptr> autonsList; std::vector<std::string> names; };
    #define neg(a) 360-a
    
    enum buttons {
        L1 = 0,
        NL1 = 1,
        L2 = 2,
        NL2 = 3,
        R1 = 4,
        NR1 = 5,
        R2 = 6,
        NR2 = 7,
        UP = 8,
        NUP = 9,
        DOWN = 10,
        NDOWN = 11,
        LEFT = 12,
        NLEFT = 13,
        RIGHT = 14,
        NRIGHT = 15,
        X = 16,
        NX = 17,
        B = 18,
        NB = 19,
        Y = 20,
        NY = 21,
        A = 22,
        NA = 23 
    };
    
    enum Color {
        red = 0,
        blue = 1,
        none = 2,
    };

    Color oppositeColor(Color c);
    
    class Stopwatch {
        private:
            int start;
        public:
            Stopwatch();
            void reset();
            int elapsed();
    };

    class Timer {
        private: 
            int startTime;
            int timeout;
            bool live = false;
        public:
            Timer(int timeout);
            void reset();
            void start();
            void stop();
            void set(int timeout);
            bool done();
    };
    
    class EMA {
       private:
        double ka, last;
       public:
        EMA(double ka);
        double out(double val);
        double curr();
    };
    
    struct Pt {
        double x = 0;
        double y = 0;
        
        double dist(Pt a);
    };
    
    enum AngleType {
        RAD,
        DEG,
        HEADING
    };
    class Angle {
        double angle_s;
        public:
            Angle();
            Angle(double angle, AngleType type);
            
            Angle operator+(Angle& other);
            void operator+=(Angle& other);
            Angle operator-(Angle& other);
            Angle operator/(double b);
            bool operator==(double b);
            
            Angle reverseDir();
            
            double rad();
            double deg();
            double heading();
            double error(Angle other);
            
    };
    
    struct Pose {
        Pt pos;
        keejLib::Angle heading;
        // Pose() : pos({0, 0}), heading(keejLib::Angle(0, HEADING)) {}
        // Pose(Pt pos, Angle angle) : pos(pos), heading(angle) {}
        // Pose(Pt pos, double heading) : pos(pos), heading(Angle(heading, HEADING)) {}
    };
    
    struct ChassVelocities {
        double left;
        double right;
    };
    
    enum CompState {
        autonomous,
        teleop,
        initialize
    };
    
    template <typename T>
    int sign(T x) {
        return(x > 0 ? 1 : -1);
    }
    
    int dirToSpin(double target, double current);
    double angError(double target, double current);
    double toRad(double deg);
    double toDeg(double rad);
    double toStandard(double deg);
    double fromStandard(double rad);
    double reverseDir(double heading);
    Angle absoluteAngleToPoint(const Pt& pos, const Pt& point);
    double curvature(Pose pose, Pose other);
    double calculateMaxSlipSpeed(const Pose& pose, const Pt& target, double drift);
    double mtpAngleError(const Pose& pose, const Pt& target, int dir);
    int computeSide(const Pt& curr, const Pt& target, Angle heading);

    template <typename T>
    bool inRange(T val, std::pair<T, T> range) {
        return (range.first <= val && val <= range.second);
    }
    Pt triangulate(Pose a, Pose b); 
    
    Pt translate(Pt a);
}