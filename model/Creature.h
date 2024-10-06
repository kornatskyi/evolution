#pragma once

#include "Position.h";
#include "Direction.h";

const int GENOME_SIZE = 10;

class Creature{
  public:
    unsigned FoodEaten;
    Position Position;
    Direction Facing;
    Gene Genome[GENOME_SIZE];
    Brain Brain;
    

};