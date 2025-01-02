#pragma once
#include "Environment.h"
#include <SFML/Graphics.hpp>

class DrawableEnvironment : public sf::Drawable
{

public:
  DrawableEnvironment(Environment &environemnt);

  void draw(sf::RenderTarget &target,
            sf::RenderStates states) const override;

  Environment &environment;
};