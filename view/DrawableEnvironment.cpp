
#include "DrawableEnvironment.h"
#include "Environment.h"
#include "ViewConfig.h"

DrawableEnvironment::DrawableEnvironment(Environment &environment) : environment(environment)
{
}

void DrawableEnvironment::draw(sf::RenderTarget &target,
                               sf::RenderStates states) const
{

  // Create creature shape
  sf::ConvexShape creatureShape;
  creatureShape.setPointCount(3);
  creatureShape.setPoint(0, sf::Vector2f(0, -5));
  creatureShape.setPoint(1, sf::Vector2f(-4, 5));
  creatureShape.setPoint(2, sf::Vector2f(4, 5));
  creatureShape.setFillColor(sf::Color::Green);

  // Draw each creature
  for (const Creature &creature : environment.population)
  {
    auto creatureRenderingPosition = sf::Vector2f(
        static_cast<float>(creature.position.x),
        static_cast<float>(creature.position.y));

    // Set position (using Vector2f for SFML 3.0)
    creatureShape.setPosition(creatureRenderingPosition);

    // Set rotation based on direction
    float rotation = 0;
    switch (creature.facing)
    {
    case Direction::North:
      rotation = 0;
      break;
    case Direction::East:
      rotation = 90;
      break;
    case Direction::South:
      rotation = 180;
      break;
    case Direction::West:
      rotation = 270;
      break;
    }
    // Use degrees() for SFML 3.0
    creatureShape.setRotation(sf::degrees(rotation));

    target.draw(creatureShape, states);
  }
}