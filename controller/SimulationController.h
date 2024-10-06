#pragma once
#include <Environment.h>

class SimulationController
{

  void start();
  void stop();
  void update();

private:
  Environment *world;
};