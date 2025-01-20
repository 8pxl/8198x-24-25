#pragma once
#include "locolib/particleFilter.h"
#include "main.h"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.hpp"
#include "util.h"
#include "control.h"

namespace keejLib {
    struct ChassConstants {
        double horizWidth;
        double vertWidth;
        double trackDia;
        double vertDia;
        double horizDia;
        double gearRatio;
    };
    
    class DriveTrain {
        private:
            pros::MotorGroup *leftMotors;
            pros::MotorGroup *rightMotors;
        public:
            DriveTrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors) : leftMotors(leftMotors), rightMotors(rightMotors){}
            
            void spinVolts(ChassVelocities velocities);
            // void spinVolts(int left, int right);
            // void spinVolts(std::pair<double, double> volts);
            void spinAll(int volts);
            void spinLeft(int volts);
            void spinRight(int volts);
            void tare_position();

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
        int timeout = 3000;
        double vMin = 0;
        double settleRange;
        double settleTime;
        Exit* exit;
        double mtpRotBias;
        double vStart;
        double rotationCut;
        double drift = 0;
        bool reverse = false;
        double within = 0;
        double slew = 0;
    };

    class Chassis {
        private: 
            DriveTrain *dt;
            pros::Imu *imu;
            pros::Rotation *vertEnc;
            pros::Rotation *horizEnc;
            pros::Distance *vertDist;
            pros::Distance *horizDist;
            
            ChassConstants chassConsts;
            PIDConstants linConsts;
            PIDConstants angConsts;
            
            PIDConstants turnConsts;
            
            PIDConstants mtpLin;
            PIDConstants mtpAng;
            Pose pose;
            EMA velEMA = EMA(0.5);
            pros::Task* odomTask = nullptr;
            PrevOdom prev = {0,0};
            bool moving = false;
            Color clr = red;
            pros::Mutex encMutex = pros::Mutex();
            std::pair<double, double> alternateOffsets;
            
            pros::Mutex alternateMutex;
            bool useAltOffsets = false;
            
            void updatePosition();
            void updateOdom();
        public:
          Chassis(const Chassis &) = delete;
          Chassis(Chassis &&) = delete;
          Chassis &operator=(const Chassis &) = delete;
          Chassis &operator=(Chassis &&) = delete;
          Chassis(DriveTrain *dt, ChassConstants constants, pros::Imu *imu,
                  pros::Rotation *vertEnc, pros::Rotation *horizEnc);
          Chassis(DriveTrain *dt, ChassConstants constants,
                  std::pair<double, double> alternateOffsets, pros::Imu *imu,
                  pros::Rotation *vertEnc, pros::Rotation *horizEnc);

          // loco::ParticleFilter<50> mcl;
          // units::Angle getHeading();

          void startTracking();
          void setConstants(PIDConstants linear, PIDConstants angular);
          void setLin(PIDConstants linear);
          void setAng(PIDConstants angular);
          void setMTP(PIDConstants lin, PIDConstants ang);
          void setTurn(PIDConstants turn);
          void setColor(Color c);
          void waitUntilSettled();
          void setPose(Pose p);
          void setAlternateOffsets(std::pair<double, double> offsets);
          void useAlternateOffsets(bool yes);

          Pose getPose();
          bool isSettled();
          std::pair<double, double> measureOffsets(int iterations);
          double getTheta();
          std::pair<double, double> pidMTPVel(Pt target, MotionParams params,
                                              PID *lCont, PID *rCont,
                                              double absDist);
          void turn(double angle, MotionParams params);
          void turnTo(Pt target, MotionParams params);
          void driveAngle(double dist, double angle, MotionParams params,
                          bool absolute = false);
          void mtpose(Pose target, double dLead, MotionParams params);
          void mtpoint(Pt target, MotionParams params);
          void moveWithin(Pt targ, double dist, MotionParams params,
                          double angle = -1);
          void linTo(Pt targ, MotionParams params);
          void wallReset(int wall, int numReadings, bool createTask = true);
    };
}