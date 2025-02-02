#include "keejLib/lib.h"
#include "keejLib/util.h"
#include "locolib/distance.h"
#include <cstdio>
#include <ostream>

namespace keejLib {
    
void Chassis::startTracking() {
    if (odomTask == nullptr) {
        vertEnc -> reset_position();
        horizEnc -> reset_position();
        odomTask = new pros::Task{[=] {
            while (true) {
                // updateOdom();
                mcl.update([this](){
                    return updateOdom();
                });
                auto p = mcl.getPrediction();
                auto particles = mcl.getParticles();
                // std::printf("[");
                for (auto q: particles) {
                    // std::printf("(%.3f, %.3f), ", q.x(), q.y());
                }
                // std::printf("],\n");
                pose = {p.x() * 39.3701, p.y() * 39.3701, Angle(p.z(), keejLib::HEADING)};
                std::cout << "x: " << pose.pos.x << " y: " << pose.pos.y << " theta: " << pose.heading.deg() << std::endl;
                // std::printf("(%.3f, %.3f, %.3f),", pose.pos.x, pose.pos.y, pose.heading.heading());
                pros::delay(10);
            }
        }};
    }
}

Eigen::Vector2f Chassis::updateOdom() {
    // chassMutex.take();
    double rot = imu -> get_rotation();
    Angle currTheta;
    if (rot == PROS_ERR_F) {
        currTheta= prev.theta;
        // std::cout << "imu disconnected!" << std::endl;
    }
    else currTheta = Angle(imu -> get_rotation(), AngleType::HEADING);
    // std::cout << "heading: " << currTheta.heading() << std::endl;
    // encMutex.take();
    double currVert = (vertEnc -> get_position() / 100.0);
    double currHoriz = (horizEnc -> get_position() / 100.0);
    // encMutex.give();
    // std::cout << "currVert: " << currVert << " currHoriz: " << currHoriz << std::endl;
    double dTheta = toRad(currTheta.error(prev.theta));
    // std::cout << toDeg(dTheta) << std::endl;
    
    alternateMutex.take();
    double dVert;
    double dHoriz;
    if (useAltOffsets) {
        dVert = (angError(currVert, prev.vert) * M_PI * alternateOffsets.first) / 360.0;
        dHoriz = (angError(currHoriz, prev.horiz) * M_PI * alternateOffsets.second) / 360.0;
    }
    else {
        dVert = (angError(currVert, prev.vert) * M_PI * chassConsts.vertDia) / 360.0;
        dHoriz = (angError(currHoriz, prev.horiz) * M_PI * chassConsts.horizDia) / 360.0;   
    }
    alternateMutex.give();
    // std::cout << "dVert: " << dVert << " dHoriz: " << dHoriz << std::endl;
    // std::cout << "dTheta: " << dTheta*10 << std::endl;
    prev.theta = currTheta;
    prev.vert = currVert;
    prev.horiz = currHoriz;
    
    double avgHeading = (toRad(prev.theta.heading()) + dTheta / 2);
    // std::cout << "avgHeading: " << avgHeading << std::endl;
    double dx = dHoriz;
    double dy = dVert;
    
    
    // std::cout << "dx: " << dx << " dy: " << dy << std::endl;
    double locX = 0;
    double locY = 0;
    
    if (dTheta == 0) {
        locX = dx;
        locY = dy;
    } else {
        locX = 2 * sin(dTheta / 2) * (dx / dTheta + chassConsts.horizWidth);
        locY = 2 * sin(dTheta / 2) * (dy / dTheta + chassConsts.vertWidth);
    }
    
    // std::cout << "x: " << dHoriz << " y: " << locY << std::endl;
    // update globals
    // pose.pos.x += locY * sin(avgHeading) - (locX * cos(avgHeading));
    // pose.pos.y += locY * cos(avgHeading) + (locX * sin(avgHeading));
    return { 39.3701 * locY * sin(avgHeading) - (locX * cos(avgHeading)), 39.3701 * locY * cos(avgHeading) + (locX * sin(avgHeading))};
    // chassMutex.give()
}

}