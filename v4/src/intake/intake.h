#pragma once

#include "keejLib/lib.h"
#include "keejLib/piston.h"
#include "keejLib/util.h"
#include "main.h"
#include "../robotState/robotState.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include <unordered_map>

namespace keejLib {
class Intake {
public:
  Intake(pros::Motor *intake, pros::Optical *optical, pros::Distance *distance, Color sort);
  void startControl();
  void setColor(Color c);
  void move(double velocity);
  Color getDetected();
  void setJamProtection(bool val);
  Color getColor();
  void setAutoLift(bool val);
  void stopOnColor(Color col, int timeout);

private:
  pros::Motor *motor;
  pros::Optical *optical;
  pros::Distance *distance;
  pros::adi::DigitalIn *limit;
  pros::Task *task = nullptr;
  Pis *piston;

  bool autoLift = true;
  std::unordered_map<Color, std::pair<double, double>> colorHues{
      {red, {350, 9}}, {blue, {210, 227}}};
  std::unordered_map<Color, int> colorCount{
      {red, 0}, {blue, 0}
  };
  double velocity = 0;
  bool taskBlocked = false;
  Color colorDetected = none;
  Color colorToSort = none;
  keejLib::EMA velocityEma;
  keejLib::EMA colorEma;
  Stopwatch jamTimer;
  double sortDist = 300;
  bool jamProtection = true;
  bool ringSeen = false;

  Color colorToStop = none;

  Color detectColor();
  void control();

  Timer autoStopTimer= Timer(1000);
  bool ringSensed();
  void handleAutoStop(Color colorDetected);
  void handleColorSort(Color col, bool liftClear);
  void handleJamProtection(bool liftClear, RobotState* s);
  bool isJammed(double actual, int tolerance);
};
} // namespace keejLib