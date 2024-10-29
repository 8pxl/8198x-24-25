#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../clamp.hpp"
#include "funcs.hpp"

#include "rawp.hpp"
#include "rneg.hpp"
#include "rpos.hpp"
#include "bPos.hpp"
#include "skills.hpp"

using namespace robot;
using namespace exit;


void printPoint() {
    Pt point = chass.getPose().pos;
    prosController.print(0, 0, "%f, %f", point.x, point.y);
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

void test() {
    
    // chass.drive(12);
    // chass.mtpoint({20,70});
    // chass.drive(-12);
    
    // robot::intake.move(127);
    // stopOnColor();
    // chass.driveAngle(-1200, 30, {.async = true, .timeout = 1000, .vMin = 0, .exit = new Range(80, 10),.slew =0.01});
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setLin(_lin);
    chass.setMTP(_chassLin, _chassAng);
    chass.mtpoint({-8, -40}, {.timeout = 700, .vMin = 0, .settleRange = 10, .exit = new Range(5, 100)});
    chass.turn(neg(3), {.timeout = 700, .exit = new Range(5, 100)});
    
    pros::delay(300);
    robot::intake.move(0);
    chass.waitUntilSettled();
}

void match() {}
// keejLib::Autons autons = {{match, soloBlue, soloAwp, posAwpBlue, posAwpRed, skills, test, negRed, negBlue, posRedElims, posBlueElims, posBlueNoStake, posRedSafe},
//                     {"match", "solo blue", "solo awp", "posAwpBlue", "posAwpRed", "skills", "test", "neg red elims", "neg blue elims", "pos red elims", "pos blue elims", "posBlueNoStake", "posRedSafe"}};
keejLib::Autons autons = {{rposNew, bposNew, rsoloAwp, test, skills}, {"pos awp red", "pos awp blue", "rsolo awp", "test", "skills"}};
//                     {"match", "solo blue", "solo awp", "posAwpBlue", "posAwpRed", "skills", "test", "neg red elims", "neg blue elims", "pos red elims", "pos blue elims", "posBlueNoStake", "posRedSafe"}};
