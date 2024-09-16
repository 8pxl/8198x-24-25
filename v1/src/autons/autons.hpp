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
    Pt allianceStake = {14.4, -10.0531};
    // Pt firstGoal = {-4, 23};
    Pt firstGoal = {-3, 23};
    Pt firstRing = {-30, 34};
    // Pt secondGoal = {32, 23};
    Pt secondGoal = {35, 33};
    Pt secondRing = {63, 36};
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    // prosController.print(0, 0, "%f", imu.get_rotation());
    
    intake.move(127);
    chass.driveAngle(600, 55, {.async = true, .timeout = 2000, .vMin = 0, .exit = new Range(20, 200)});
    // chass.mtpoint({4,8}, {
    //     .async = false,
    //     .timeout = 6000,
    //     .settleRange = 4,
    //     .exit = new exit::Range(3, 400),
    // });
    pros::delay(450);
    robot::intake.move(127);
    robot::tsukasa.setState(false);
    redirect.toggle();
    chass.driveAngle(-200, 55, {.async = false, .timeout = 2000, .exit = new Range(20, 100)});
    lift.setState(Lift::mid);
    pros::delay(180);
    intake.move(-127);
    chass.waitUntilSettled();
    chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(2.2, 100)});
    chass.driveAngle(340, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 50)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    chass.driveAngle(-300, imu.get_heading(), {.timeout = 2000, .exit = new Range(20, 50)});
    chass.turnTo(firstGoal, {.timeout=3000, .exit = new Range(2, 30), .reverse = true});
    
    // chass.mtpoint(firstGoal, {.timeout = 4000, .vMin = 20, .settleRange = 3, .exit = new exit::Range(3, 400)});
    chass.setLin(_lin);
    chass.driveAngle(-1000, imu.get_heading(), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    chass.driveAngle(-440, 150, {.async = true, .timeout = 2000, .exit = new Range(50, 100)});
    pros::delay(400);
    clamp::tilt();
    chass.waitUntilSettled();
    redirect.toggle();
    intake.move(127);
    chass.turnTo(firstRing, {.timeout=3000, .exit = new Range(10, 30)});
    chass.mtpoint(firstRing, {.timeout = 700, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    // chass.mtpoint({-10, 20}, {.timeout = 8000, .vMin = 30, .settleRange = 8, .exit = new exit::Range(3, 400), .drift = 15});
    chass.setLin(_lin);
    // chass.turn(neg(60), {.timeout = 100, .exit = new Range(5, 20)});
    chass.setAng(_angBig);
    chass.driveAngle(-2400, neg(65), {.timeout = 3000, .vMin = 60, .exit = new Range(20, 10)});
    chass.setAng(_ang);
    chass.driveAngle(-800, neg(50), {.async = true, .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(200);
    clamp::clamp();
    chass.driveAngle(500, neg(50), {.timeout = 3000, .vMin = 0, .exit = new Range(30, 20)});
    // chass.driveAngle(-1000, neg(90), {.timeout = 3000, .vMin = 30, .exit = new Range(20, 40)});
    chass.turnTo(secondGoal, {.timeout=3000, .exit = new Range(3, 10), .reverse = true});
    chass.driveAngle(-1100, neg(150), {.async = true, .timeout = 2000, .exit = new Range(23, 40)});
    pros::delay(700);
    clamp::tilt();
    
    intake.move(127);
    chass.turnTo(secondRing, {.timeout=3000, .exit = new Range(3, 10)});
    chass.mtpoint(secondRing, {.timeout = 700, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    lift.setState(Lift::mid);
    chass.turn(neg(65), {.timeout=3000, .exit = new Range(5, 10)});
    chass.driveAngle(1600, neg(70), {.timeout = 2000, .exit = new Range(30, 20)});
    lift.toggleControl();
    
}

void skills() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_linSmall);
    chass.setMTP(_chassLin, _chassAng);
    
    Pt allianceStake = {18, -11.0531};
    robot::intake.move(127);
    lift.setState(Lift::mid);
    dt.move(-40);
    pros::delay(300);
    clamp::tilt();
    pros::delay(100);
    dt.move(0);
    
    chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(2, 100)});
    chass.mtpoint(allianceStake, {.timeout = 2000, .vMin = 0, .settleRange = 20, .exit = new exit::Range(20, 100), .drift = 5, .within = 14.5});
    // chass.driveAngle(770, imu.get_heading(), {.timeout = 2000, .exit = new Range(10, 50)});
    lift.setState(Lift::resting);
    pros::delay(300);
    
    Pt ring1 = {-9,34};
    chass.driveAngle(-300, imu.get_heading(), {.timeout = 2000, .exit = new Range(20, 50)});
    lift.setState(Lift::raised);
    chass.turnTo(ring1, {.timeout=3000, .exit = new Range(3, 30)});
    chass.setLin(_lin);
    chass.driveAngle(1400, imu.get_heading(), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    chass.driveAngle(1300, neg(94), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    
    Pt ring3 = {-45, 10};
    chass.mtpoint(ring3, {.timeout = 1400, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 5});
    chass.driveAngle(-700, imu.get_heading(), {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    chass.turnTo({-37, 0}, {.timeout=3000, .exit = new Range(5, 10)});
    chass.driveAngle(600, 170, {.timeout = 2000, .vMin = 10, .exit = new Range(10, 30)});
    // dt.move(-60);
    // pros::delay(100);
    chass.driveAngle(600, 180, {.timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(190);
    chass.turn(60, {.timeout=3000, .exit = new Range(1, 90)});
    chass.driveAngle(-700, 60, {.async = true, .timeout = 2000, .exit = new Range(20, 100)});
    pros::delay(200);
    clamp::clamp();
    chass.waitUntilSettled();
    robot::intake.move(-127);
    
    Pt ring4 = {-47, 55};
    lift.toggle();
    chass.mtpoint(ring4, {.async = true, .timeout = 1800, .vMin = 20, .settleRange = 9, .exit = new exit::Range(9, 20), .drift = 14});
    robot::intake.move(127);
    pros::delay(500);
    redirect.toggle();
    chass.mtpoint({-34, 82}, {.timeout = 1500, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17});
    chass.turn(0, {.timeout=3000, .exit = new Range(5, 20)});
    chass.driveAngle(-1000, neg(3), {.timeout = 2000, .exit = new Range(20, 100)});
    lift.toggle();
    chass.turnTo({-59, 60.5}, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.mtpoint({-59, 60.5}, {.timeout = 2300, .vMin = 0, .settleRange = 30, .exit = new exit::Range(9, 100), .drift = 7, .within =9.6});
    lift.toggle();
    pros::delay(400);
    chass.setLin(_linSmall);
    chass.driveAngle(-700, imu.get_heading(), {.timeout = 2000, .exit = new Range(20, 100)});
    chass.setLin(_lin);
    
    
    Pt ring5 = {-9, 86};
    chass.turnTo(ring5, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.driveAngle(2000, imu.get_heading(), {.timeout = 2000, .vMin = 40, .exit = new Range(100, 10)});
    clamp::clamp();
    chass.driveAngle(600, 90, {.timeout = 2000, .exit = new Range(20, 50)});
    chass.driveAngle(-1400, 150, {.timeout = 2000, .vMin = 28, .exit = new Range(50, 10)});
    lift.switchState();
    chass.driveAngle(-1400, 90, {.timeout = 2000, .vMin = 0, .exit = new Range(20, 80)});
    clamp::clamp();
    
    Pt goal2 = {-10, 120};
    chass.mtpoint(goal2, {.timeout = 1500, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17});
    chass.turn(neg(90), {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.driveAngle(-800, neg(90), {.async = true, .timeout = 3000, .vMin = 20, .exit = new Range(20, 40)});
    pros::delay(400);
    clamp::clamp();
    // chass.driveAngle(500, neg(50), {.timeout = 3000, .vMin = 0, .exit = new Range(30, 20)});
    
    Pt blueStake = {15, 130};
    chass.turnTo(blueStake, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.mtpoint(blueStake, {.timeout = 2000, .vMin = 0, .settleRange = 9, .exit = new exit::Range(9, 100), .drift = 17, .within = 14.5});
    lift.toggle();


    
}
void test() {
    Pt firstRing = {-29, 35};
    Pt allianceStake = {13.6, -10.0531};
    chass.setMTP(_chassLin, _chassAng);
    
    chass.turnTo({-59, 60}, {.timeout=3000, .exit = new Range(0.8, 30)});
    chass.mtpoint({-59, 60}, {.timeout = 2300, .vMin = 0, .settleRange = 20, .exit = new exit::Range(5, 100), .drift = 7, .within =7});
    lift.toggle();
    // chass.mtpoint({30, 30}, {.timeout = 8000, .vMin = 0, .settleRange = 3, .exit = new exit::Range(3, 400), .drift = 6,});
    // chass.mtpoint({15,15}, {.timeout = 4000, .vMin = 0, .settleRange = 3, .exit = new exit::Range(3, 400), .reverse = false});
}
//     chass.setTurn(_90);
//     chass.turnTo(allianceStake, {.timeout=3000, .exit = new Range(0.5, 300)});
// }
keejLib::Autons autons = {{skills, awp2, test},
                    {"skills", "solo awp", "test"}};
