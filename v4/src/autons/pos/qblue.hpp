#include "../constants.hpp"
#include "../../robot.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../../lift/lift.h"
#include "../funcs.hpp"
#include "pros/screen.h"


using namespace robot;
void qbPos(){
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
chass.setMTPose(_mposeLin, _mposeAng);
chass.setMTPose(_mposeLin, _mposeAngMogo);

    chass.setLin(_lin);
    // chass.mtpose({{-16, 10}, h(neg(90))}, 0.8, {});
    // pros::delay(100000);
    
    // imu.set_heading(342.24);
    
    Pt goal = {-12.3, 52.57};
    double distFromGoal = 17.9;
    double scoreDelay = 10.3;
    double overDrive = -5;
    // chass.turn(0, {});
    
    lb.setState(keejLib::LiftState::lower);
    intake.stopOnColor(blue, 0);
    chass.setMTP(_chassLin, _chassAngBig);
    // ldoink.toggle();
    ldoink.toggle();
    // chass.driveAngle(1000, 0, {.timeout = 400, .vMin = 110,});
    chass.mtpoint(goal, {
        .async = true,
        // .vMax = 40,
        .exit = new exit::DistanceSensor(&rushDistance, 355, 600, 44)
    });
    pros::delay(300);
    intake.move(127);
    chass.waitUntilSettled();
    ldoink.toggle();
    lb.setState(keejLib::LiftState::lowest);
    // chass.driveAngle(-500, neg(15), {.vMin = 80});
    // chass.mtpoint(goal, {
    //     // .vMax = 40,
    //     .exit = new Range(distFromGoal - overDrive, 5),
    // });
    chass.setAng(_angBig);
    // chass.driveAngle(-200, neg(20), {.vMin = 110, .exit = new Range(80, 10), });
    chass.driveAngle(-500, neg(48), {.vMin = 110});
    // chass.turn(neg(90), {.exit = new Range(10, 10)});
    lb.setState(LiftState::idle);
    // chass.mtpose({{10, 29}, h(315)}, 0.4, {.settleRange = 3, .drift = 1.5});
    chass.driveAngle(-600, neg(30), {.vMin = 40});

    clamp.toggle();
    // ldoink.toggle();
    pros::delay(100);
    
    Pt centerSetup = {26.8, 43.23};
    chass.turnTo(centerSetup, {.exit = new Range(5, 10)});
    intake.move(0);
    tsukasa.toggle();
    // chass.mtpose({centerSetup, h(10)}, 0.5, {.settleRange = 2});
    chass.mtpoint(centerSetup, {});
    chass.turn(40, {});
    ldoink.toggle();
    pros::delay(300);
    chass.setTurn(_5);
    chass.turn(22, {});
    chass.setTurn(_90);
    rdoink.toggle();
    pros::delay(300);

    // chass.mtpose({{-5, 30}, h(40)}, 0.5, {.settleRange = 5, .drift = 0.5}, 0.8, 5);
        chass.setMTPose(_mposeLin, _mposeAngMogo);

    chass.mtpose({{-8,5}, h(0)}, 0.5, {.settleRange = 1});
    // chass.turn(neg(145), {});
    rdoink.toggle();
    ldoink.toggle();
    
    chass.turn(0, {});
    pros::delay(500);
    intake.move(127);
    // chass.setMTPose(_mposeLin, _mposeAngMogo);
    chass.driveAngle(900, 20, {.vMin = 100});
    chass.driveAngle(500, neg(80), {.vMin = 50});
    chass.mtpoint({-20, 10}, {});
    
// 342.24
    // intake.move(0);
}