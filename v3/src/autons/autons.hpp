#include "constants.hpp"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "pos/qred.hpp"
#include "pos/qblue.hpp"
#include "neg/relims.hpp"
#include "skills.hpp"
#include "neg/rawp.hpp"
#include "neg/bawp.hpp"
#include "neg/belims.hpp"


using namespace robot;
using namespace exit;

void test() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);
    Pt blueAS = {-27.2415365831112, -138.53376928669638};
    // Pt blueAS = {-29, -135};
    chass.turnTo(blueAS, {.timeout  = 600, .exit = new Range(2, 100)});
    Pose pose = chass.getPose();
    std::cout << "x: " << pose.pos.x << " y: " << pose.pos.y << " heading: " << pose.heading.heading() << std::endl;
    //11.9 < x
    // chass.moveWithin(blueAS, 12.7, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
    // chass.moveWithin(blueAS, 17.537751502925833, {.timeout = 1500, .vMin=0, .exit = new Range(5, 10)});
      chass.mtpoint( blueAS, {.drift = 8, .within = 14.7});
    pose = chass.getPose();
std::cout << "x: " << pose.pos.x << " y: " << pose.pos.y << " heading: " << pose.heading.heading() << std::endl;

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

keejLib::Autons autons = {{skills,  belimsNeg, relimsNeg, bAwp, rAwp, qbPos, qrPos, test}, {"skills", "blue elims neg", "red elims neg", "blue awp", "red awp", "bPos", "rPos", "test"}};