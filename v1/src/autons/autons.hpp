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
    robot::intake.move(127);
    stopOnColor();
}

keejLib::Autons autons = {{soloAwp, posAwp, skills, test},
                    {"solo awp", "posAwp", "skills", "test"}};
