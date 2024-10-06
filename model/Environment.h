#pragma once
#include "Creature.h";
#include "Food.h";

const int POPULATION_CAP = 100;
const int FOOD_QUANTITY = 10;

class Environment{
  public:
    Creature Population[POPULATION_CAP];
    Food Food[FOOD_QUANTITY];
};