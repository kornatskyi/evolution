#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>

#include "UI.h"

class DrawableEntity : public sf::Drawable
{
public:
  DrawableEntity();

protected:
  void draw(sf::RenderTarget &target,
            sf::RenderStates states) const override;

private:
};
