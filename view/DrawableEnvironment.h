#pragma once
#include <SFML/Graphics.hpp>

#include "Environment.h"

class DrawableEnvironment : public sf::Drawable {
 public:
  DrawableEnvironment(Environment& environemnt);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  void NewFunction(sf::Vertex& topLeft, const Creature& creature,
                   sf::Vertex& topRight, sf::Vertex& bottomLeft,
                   sf::Vertex& bottmRight) const;

  Environment& environment;
};