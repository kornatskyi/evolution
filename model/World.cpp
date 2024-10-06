#include "World.h"

void World::update(float deltaTime)
{
  for (auto entity : entities)
  {
    entity->update(deltaTime);
  }
}

void World::checkCollisions()
{
  // Detect and handle collisions/interactions
}