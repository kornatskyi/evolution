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

class UI : public sf::Drawable
{
public:
  UI();

  std::unique_ptr<sf::Text> createText(std::string text, sf::Vector2f p);

protected:
  void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;

private:
  std::unique_ptr<sf::Text> initText();
  sf::Font font;
  mutable std::unique_ptr<sf::Text> justSomeText;
};
