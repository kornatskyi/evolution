#pragma once

#include "Creatures/Creature.h"
#include "Food.h"
#include <vector>
#include "ModelConfig.h"
class Environment
{

public:
  Environment();
  static const int POPULATION_CAP = 100;
  static const int FOOD_QUANTITY = 10;

  std::vector<Creature> population;
};