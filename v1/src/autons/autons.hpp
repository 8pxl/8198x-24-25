#include "../robot.hpp"
#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/util.h"
#include "pros/rtos.hpp"
#include "../clamp.hpp"
#include "funcs.hpp"

#include "awp.hpp"
#include "neg.hpp"
#include "pos.hpp"
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
    // robot::intake.move(127);
    // stopOnColor();
    spitColor();
    pros::delay(10000);
}

void match() {}
keejLib::Autons autons = {{match, soloBlue, soloAwp, posAwpBlue, posAwpRed, skills, test},
                    {"match", "solo blue", "solo awp", "posAwpBlue", "posAwpRed", "skills", "test"}};
