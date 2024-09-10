#pragma once
#include "main.h"
#include "pros/rotation.hpp"
#include "util.h"
#include "control.h"

namespace keejLib {
    struct ChassConstants {
        double horizWidth;
        double vertWidth;
        double trackDia;
        double wheelDia;
        double gearRatio;
    };
    
    class DriveTrain : public pros::MotorGroup {
        private:
            std::vector<std::int8_t> concat(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports);
        public:
            DriveTrain(const std::vector<std::int8_t>& left_ports, const std::vector<std::int8_t>& right_ports);
            
            void spinVolts(int left, int right);
            void spinVolts(std::pair<double, double> volts);
            void spinLeft(int volts);
            void spinRight(int volts);

            double getAvgVelocity();
            double getAvgPosition();
    };
    
    struct PrevOdom {
        double vert = 0;
        double horiz = 0;
        Angle theta = Angle(0, DEG);
    };
    
    struct MotionParams {
        bool async;
        int timeout;
        double vMin;
        double settleRange;
        double settleTime;
        Exit* exit;
        double mtpRotBias;
        double vStart;
        double rotationCut;
        bool reverse;
    };

    class Chassis {
        private: 
            DriveTrain *dt;
            pros::Imu *imu;
            pros::Rotation *vertEnc;
            pros::Rotation *horizEnc;
            ChassConstants chassConsts;
            PIDConstants linConsts;
            PIDConstants angConsts;
            Pose pose;
            pros::Task* odomTask = nullptr;
            PrevOdom prev;
            bool moving = false;
        public:
            Chassis(DriveTrain *dt, ChassConstants constants, pros::Imu *imu, pros::Rotation *vertEnc, pros::Rotation *horizEnc);
            void update();
            void startTracking();
            void setConstants(PIDConstants linear, PIDConstants angular);
            void setLin(PIDConstants linear);
            void setAng(PIDConstants angular);
            void waitUntilSettled();
            
            Pose getPose();
            bool isSettled();
            std::pair<double, double> measureOffsets(int iterations);
            double getTheta();
            std::pair<double, double> pidMTPVel(Pt target, MotionParams params, PID* lCont, PID* rCont, double absDist);
            void turn(double angle, MotionParams params);
            void driveAngle(double dist, double angle, MotionParams params);
            void mtpose(Pose target, double dLead, MotionParams params);
            void mtpoint(Pt target, MotionParams params);
            
    };
}