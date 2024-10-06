#pragma once
#include <World.h>

class SimulationController
{

  void start();
  void stop();
  void update();

private:
  World *world;
};