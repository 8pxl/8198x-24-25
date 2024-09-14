#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../clamp.hpp"
#define neg(a) 360-a

using namespace robot;
using namespace exit;

void triangulatePoint() {
    std::vector<Pose> poses;
    while (poses.size() < 2) {
        if (prosController.get_digital_new_press(DIGITAL_A)) {
            poses.push_back(chass.getPose());
        }
    }
    Pt point = triangulate(poses[0], poses[1]);
    prosController.print(0, 0, "%f, %f", point.x, point.y);
}
// void test() {
    
//     // chass.mtpose({15, 15, Angle(90, keejLib::HEADING)}, 0.7, {
//     //     .timeout = 6000,
//     //     .settleRange = 0.5,
//     //     .exit = new exit::Range(0.1, 6000),
//     //     .mtpRotBias = 0,
//     // });
//     chass.setLin(chassLin);
//     chass.setAng(chassAng);
//     chass.mtpoint({-15,-15}, {
//         .async = true,
//         .timeout = 6000,
//         .settleRange = 4,
//         .exit = new exit::Range(1.6, 400),
//         .mtpRotBias = 0,
//         .reverse = false
//     });
//     // chass.setLin(mposeLin);
//     // chass.setAng(mposeAng);
//     // chass.mtpose({15,15, Angle(90, keejLib::HEADING)}, 0.6, {
//     //     .async = true,
//     //     .timeout = 6000,
//     //     .settleRange = 1.5,
//     //     .exit = new exit::Range(1.6, 4000),
//     //     .mtpRotBias = 0,
//     //     .drift = 2.5,
//     //     .reverse = false
//     // });
//     // 
//     while (!chass.isSettled()) {
//         Pose pose = chass.getPose();
        // prosController.print(0, 0, "%f, %f", pose.pos.x, pose.pos.y);
//     }
//     // 
//     // 
//     // 
//     // std::cout << absoluteAngleToPoint({0,0}, {10,10}).heading() << std::endl;
//     // chass.turn(absoluteAngleToPoint({0,0}, {10,10}).heading(), {.async = false, .timeout = 2000, .vMin = 0, .exit = new exit::Range(0.01, 500)});
// }

// void awp() {
    
//     chass.setAng(_90);
    
//     prosController.print(0, 0, "%f", imu.get_rotation());
//     chass.setLin(_linSmall);
//     chass.setAng(_ang);
    
//     intake.move(127);
//     chass.driveAngle(250, 57, { .timeout = 2000, .exit = new Range(20, 100)});
//     robot::tsukasa.setState(false);
//     pros::delay(100);
//     chass.driveAngle(-500, 57, {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
//     pros::delay(180);
//     lift.setState(Lift::raised);
//     pros::delay(100);
//     lift.setState(Lift::resting);
//     redirect.toggle();
//     chass.waitUntilSettled();
    
//     chass.setAng(_90);
//     pros::delay(900);
//     lift.setState(Lift::mid);
//     chass.turn(132, {.timeout=1000, .exit = new Range(0.5, 100)});
//     redirect.toggle();
    
//     chass.setAng(_ang);
//     chass.driveAngle(300, 132, { .timeout = 2000, .exit = new Range(20, 100)});
//     lift.setState(Lift::resting);
//     pros::delay(400);
//     chass.setLin(_lin);
//     chass.driveAngle(-1730, 130.8, {.timeout = 2000, .exit = new Range(20, 100)});
//     lift.setState(Lift::raised);
//     chass.setAng(_90);
//     chass.turn(neg(148), {.timeout=1000, .exit = new Range(1, 80)});
//     chass.setAng(_ang);
//     chass.setLin(_lin);
    
//     chass.driveAngle(-700, neg(148), {.async = true,.timeout = 2000, .exit = new Range(20, 70)});   
//     pros::delay(340);
//     clamp::clamp();
//     chass.waitUntilSettled();
//     clamp::tilt();
    
//     chass.setAng(_90);
//     chass.turn(neg(76), {.timeout=1000, .exit = new Range(0.8, 40)});
//     chass.setAng(_ang);
//     chass.setLin(_lin);
//     chass.driveAngle(900, neg(76), {.timeout = 2000, .exit = new Range(20, 100)});
//     chass.driveAngle(-4000, neg(70), {.timeout = 2000, .exit = new Range(20, 100)});
// }

void awp2() {
    Pt allianceStake = {15.4, -10.0531};
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    Pt firstGoal = {-2.7, 25};
    // prosController.print(0, 0, "%f", imu.get_rotation());
    
    intake.move(127);
    chass.driveAngle(400, 55, {.async = true, .timeout = 2000, .vMin = 10, .exit = new Range(10, 30)});
    lift.setState(Lift::raised);
    pros::delay(100);
    lift.setState(Lift::resting);
    chass.waitUntilSettled();
    // chass.mtpoint({4,8}, {
    //     .async = false,
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(3, 400),
    // });
    robot::tsukasa.setState(false);
    chass.driveAngle(400, 55, {.async = false, .timeout = 2000, .exit = new Range(10, 300),});
    chass.driveAngle(-300, 55, {.async = false, .timeout = 2000, .exit = new Range(20, 100)});
    redirect.toggle();
    lift.setState(Lift::mid);
    pros::delay(180);
    chass.waitUntilSettled();
    chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(0.5, 300)});
    chass.driveAngle(290, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 300)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    chass.driveAngle(-300, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 300)});
    chass.turnTo(firstGoal, {.timeout=3000, .exit = new Range(0.5, 300), .reverse = true});
    
    chass.mtpoint(firstGoal, {.timeout = 4000, .vMin = 20, .settleRange = 3, .exit = new exit::Range(3, 400)});
    chass.setLin(_lin);
    chass.driveAngle(-440, 150, {.async = true, .timeout = 3000, .exit = new Range(10, 300)});
    
    chass.waitUntilSettled();
}

keejLib::Autons autons = {{awp2},
                    {"solo awp",}};
