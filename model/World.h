#pragma once
#include <vector>
#include "Entity.h"

class World
{
private:
  std::vector<Entity *> entities;

public:
  void update(float deltaTime);

  void checkCollisions();
};