#include "Environment.h"
#include "Creatures/Creature.h"
#include "Position.h"

Environment::Environment()
{
  // Generate creatures
  for (int i = 0; i < 10; i++)
  {
    population.push_back(Creature(Position::getRandomPosition(ModelConfig::WIDTH, ModelConfig::HEIGHT)));
  }

  // Generate food
  for (int i = 0; i < 10; i++)
  {
    foods.push_back(Food(Position::getRandomPosition(ModelConfig::WIDTH, ModelConfig::HEIGHT)));
  }
}
