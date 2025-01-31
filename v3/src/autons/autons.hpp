#include "constants.hpp"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "pos/qred.hpp"
#include "pos/qblue.hpp"
#include "neg/qred.hpp"
#include "skills.hpp"
#include "neg/rawp.hpp"
#include "neg/bawp.hpp"


using namespace robot;
using namespace exit;

void test() {
    // Pt wallStake = {38, -65};

    // chass.turnTo(wallPrime1, {.timeout = 600, .exit = new Range(2, 30)});
    // chass.measureOffsets(5);
    // chass.setLin(_lin);
    // chass.setAng(_ang);
    // chass.driveAngle(9, 0, {.timeout = 1500, .vMin=0, .exit = new Range(1, 100), .reverse=false});
    // lb.setAutoControl(false);

pros::delay(700);
    // intake.setSorting(false);
pros::delay(700);
intake.move(0); 
pros::delay(700);
intake.move(127);
lb.next();
// intake.setSorting(false);
pros::delay(700);
intake.move(127);

}

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

keejLib::Autons autons = {{skills, bAwp, rAwp, qbPos, qrPos, test}, {"skills", "blue awp", "red awp", "bPos", "rPos", "test"}};