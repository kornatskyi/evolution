
#include "DrawableEnvironment.h"
#include "Environment.h"

DrawableEnvironment::DrawableEnvironment(Environment &environment) : environment(environment)
{
}

/// @brief Modifies vectorToShift by shifting it along X and Y axes by the values in shiftingVector.
/// @param vectorToShift - vector to be modified.
/// @param shiftingVector - vector indicating how much to shift (default is {100, 0}).
/// @return - new shifted vector.
sf::Vector2f shift(sf::Vector2f vectorToShift, sf::Vector2f shiftingVector = sf::Vector2f(200, 0))
{
  vectorToShift.x += shiftingVector.x;
  vectorToShift.y += shiftingVector.y;
  return vectorToShift;
}

void DrawableEnvironment::draw(sf::RenderTarget &target,
                               sf::RenderStates states) const
{
  const int LINE_THICKNESS = 1;

  // Draw bounding box
  sf::RectangleShape topLine({ModelConfig::WIDTH, LINE_THICKNESS});
  topLine.setPosition(shift(sf::Vector2f({0, 0})));
  target.draw(topLine, states);

  sf::RectangleShape bottomLine({ModelConfig::WIDTH, LINE_THICKNESS});
  bottomLine.setPosition(shift(sf::Vector2f({0.f, ModelConfig::HEIGHT})));
  target.draw(bottomLine, states);

  sf::RectangleShape leftLine({LINE_THICKNESS, ModelConfig::HEIGHT});
  leftLine.setPosition(shift(sf::Vector2f({0.f, 0.f})));
  target.draw(leftLine, states);

  sf::RectangleShape rightLine({LINE_THICKNESS, ModelConfig::HEIGHT});
  rightLine.setPosition(shift(sf::Vector2f({ModelConfig::WIDTH - LINE_THICKNESS, 0.f})));
  target.draw(rightLine, states);

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
    creatureShape.setPosition(shift(sf::Vector2f(creatureRenderingPosition)));

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