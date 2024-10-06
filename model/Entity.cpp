#include "Entity.h"

Position::Position()
{
  this->x = 0;
  this->y = 0;
}


Position::Position(float x, float y)
{
  this->x = x;
  this->y = y;
}

Entity::Entity(Position initPosition)
{
  this->position = initPosition;
}