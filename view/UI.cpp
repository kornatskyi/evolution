#include "UI.h"

UI::UI()
{
  // Load font
  if (!font.openFromFile(std::filesystem::absolute("assets/fonts/3270MediumNerdFontCompleteMono.ttf").string()))
  {
    throw std::runtime_error("Failed to load font");
  }

  // Initialize UI elements
  justSomeText = createText("Just some text!", sf::Vector2f(10, 10));
}


std::unique_ptr<sf::Text> UI::createText(std::string text, sf::Vector2f p)
{
  auto t = this->initText();
  t->setString(text);
  t->setPosition(p);
  return t;
}

void UI::draw(sf::RenderTarget &target,
              sf::RenderStates states) const
{

  // sf::RectangleShape line({});



  target.draw(*justSomeText, states);
}

std::unique_ptr<sf::Text> UI::initText()
{
  auto text = std::make_unique<sf::Text>(font);
  text->setFont(font);
  text->setCharacterSize(16);
  text->setFillColor(sf::Color::Red);
  text->setStyle(sf::Text::Bold | sf::Text::Underlined);
  return text;
}
