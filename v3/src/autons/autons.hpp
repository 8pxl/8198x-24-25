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
#include "neg/rwall.hpp"
#include "neg/bwall.hpp"


using namespace robot;
using namespace exit;

void test() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
    chass.setLin(_lin);
    
    chass.swingTo({10,10}, 5, {});

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

// keejLib::Autons autons = {{skills,  belimsNeg, relimsNeg, rwallNeg, bwallNeg,  bAwp, rAwp, qbPos, qrPos, test}, {"skills", "blue elims neg", "red elims neg", "red wall neg", "blue wall neg", "blue awp", "red awp", "bPos", "rPos", "test"}};

keejLib::Autons redAutons = {{skills, relimsNeg, rwallNeg, rAwp, qrPos}, {"skills", "red elims neg", "red wall neg", "red awp", "red pos"}};
keejLib::Autons blueAutons = {{belimsNeg, bwallNeg, bAwp, qbPos}, {"blue elims neg", "blue wall neg", "blue awp", "blue pos"}};