#include "constants.hpp"
#include "keejLib/control.h"
#include "keejLib/lib.h"
#include "../robot.hpp"
#include "keejLib/util.h"
#include "neg/relims.hpp"
#include "pros/rtos.hpp"
#include "skills.hpp"
#include "neg/rawp.hpp"
#include "neg/bawp.hpp"
#include "neg/belims.hpp"
#include "neg/rwall.hpp"
#include "neg/bwall.hpp"
#include "pos/rctr.hpp"
#include "pos/rctrwall.hpp"
#include "pos/bctr.hpp"
#include "pos/bctrwall.hpp"


using namespace robot;
using namespace exit;

void test() {
    chass.setTurn(_90);
    chass.setAng(_ang);
    chass.setMTP(_chassLin, _chassAng);
chass.setMTPose(_mposeLin, _mposeAng);
    chass.setLin(_lin);
    chass.setMTPose(_mposeLin, _mposeAngMogo);
    
        chass.setLin(_lin);
        // chass.mtpose({{-16, 10}, h(neg(90))}, 0.8, {});
        // chass.holdPos(0, 0, 15000 , {.exit = new Range(1, 15000)});
        intake.move(127);
        intake.stopOnColor(blue, 0);
        pros::delay(30000);
    // auto x =chass.measureOffsets(20);
    // std::cout << x.first << x.second << std::endl;
    
    // chass.swingTo({10,10}, 5, {});   
    // chass.mtpose({{15,15}, h(90)}, 0.5, {.timeout = 10000, .settleRange = 8, .drift = 4, .debug = true}, 0.8, 10);
    // DistanceSensor ds(&rushDistance, 100, 10);
    // while (!ds.exited({})) {
    //     intake.move(127);
    //     pros::delay(50);
    // }
    // intake.stopOnColor(keejLib::blue, 10000);
    // pros::delay(3000);
    // chass.mtpoint({15,15}, {.drift = 2, .debug = true});
    // for (int i = 10; i < 20; i++) {
    //     dt.spinAll(i);
    //     std::cout << i << std::endl;
    //     pros::delay(900);
    //     dt.spinAll(0);
    //     pros::delay(300);
        
    // }

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

// keejLib::Autons redAutons = {{test, skills, relimsNeg, rwallNeg, rAwp, rwallNeg, rctrPos}, {"test", "skills", "elims neg", "wall neg", "awp", "wall pos", "rings pos"}};
// keejLib::Autons blueAutons = {{belimsNeg, bwallNeg, bAwp, bwallNeg, bctrPos, bctrwallPos}, {"blue elims neg", "blue wall neg", "blue awp", "blue pos", "blue rings"}};
keejLib::Autons redAutons = {{test, skills, relimsNeg, rAwp, rctrPos, rctrwallPos}, {"test", "skills", "6 ring neg", "awp", "rings pos", "wall pos"}};
keejLib::Autons blueAutons = {{belimsNeg, bAwp, bctrPos, bctrwallPos}, {"blue elims neg", "blue awp", "rings pos", "wall pos"}};