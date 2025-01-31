#pragma once

#include "keejLib/lib.h"
#include "keejLib/piston.h"
#include "keejLib/util.h"
#include "main.h"

namespace keejLib {
class Intake {
public:
  Intake(pros::Motor *intake, pros::Optical *optical, Color sort);
  void startControl();
  void setColor(Color c);
  void move(double velocity);
  Color getDetected();
  void setJamProtection(bool val);
  Color getColor();

private:
  pros::Motor *motor;
  pros::Optical *optical;
  pros::Task *task = nullptr;
  Pis *piston;

  std::unordered_map<Color, std::pair<double, double>> colorHues{
      {red, {1, 11}}, {blue, {210, 223}}};
  double velocity = 0;
  bool taskBlocked = false;
  Color colorDetected = none;
  Color colorToSort = none;
  keejLib::EMA velocityEma;
  keejLib::EMA colorEma;
  Stopwatch jamTimer;
  double sortDist = 370;
  bool jamProtection = true;

  Color detectColor();
  void control();
};
} // namespace keejLib