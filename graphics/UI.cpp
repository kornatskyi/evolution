#include "UI.h"


UI::UI()
{
	// Load font
	if (!font.loadFromFile("assets\\fonts\\3270MediumNerdFontCompleteMono.ttf"))
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

void UI::draw(sf::RenderTarget& target,
	sf::RenderStates states) const
{
	target.draw(*justSomeText, states);
}

std::unique_ptr<sf::Text> UI::initText()
{
	auto text = std::make_unique<sf::Text>();
	text->setFont(font);
	text->setCharacterSize(16);
	text->setFillColor(sf::Color::Red);
	text->setStyle(sf::Text::Bold | sf::Text::Underlined);
	return text;
}
