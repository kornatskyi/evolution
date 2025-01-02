#pragma once

#include "Creatures/Creature.h"
#include "Food.h"
#include <vector>

class Environment
{

public:
  Environment();
  static const int POPULATION_CAP = 100;
  static const int FOOD_QUANTITY = 10;
  static const unsigned X_BOUNDARY = 100;
  static const unsigned Y_BOUNDARY = 100;

  std::vector<Creature> population;
};