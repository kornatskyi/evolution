#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>


class UI : public sf::Drawable {
public:
	UI() {
		// Load font
		if (!font.loadFromFile("assets\\fonts\\3270MediumNerdFontCompleteMono.ttf")) {
			throw std::runtime_error("Failed to load font");
		}

		// Initialize UI elements
		justSomeText = createText("Just some text!", sf::Vector2f(10, 10));
	}

	std::unique_ptr<sf::Text> createText(std::string text, sf::Vector2f p) {
		auto t = this->initText();
		t->setString(text);
		t->setPosition(p);
		return t;
	}

protected:
	virtual void draw(sf::RenderTarget& target,
		sf::RenderStates states) const override {
		target.draw(*justSomeText, states);
	}

private:
	std::unique_ptr<sf::Text> initText() {
		auto text = std::make_unique<sf::Text>();
		text->setFont(font);
		text->setCharacterSize(16);
		text->setFillColor(sf::Color::Red);
		text->setStyle(sf::Text::Bold | sf::Text::Underlined);
		return text;
	}
	sf::Font font;
	mutable std::unique_ptr<sf::Text> justSomeText;
};

constexpr int WIDTH = 1600;
constexpr int HEIGHT = 900;

int main() {
	// Create a window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),
		"Evolution 🧬", sf::Style::Titlebar);
	window.setVerticalSyncEnabled(true); // sync with graphics card refresh rate
	window.setPosition(sf::Vector2i(100, 400));

	// Clock for messuring FPS
	sf::Clock clock;
	float lastTime = 0;
	float currentFps = 0;
	std::string fpsToDraw = std::to_string(currentFps);
	float fpsRenderPeriod = 0;

	// Init UI class
	UI ui;
	auto fpsText = ui.createText("FPS: " + fpsToDraw, sf::Vector2f(WIDTH - 200, 10));

	// run the main loop
	while (window.isOpen()) {
		clock.restart();
		// handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/////////////////////////////////////////////////
		// All updates should be happening in this block.
		/////////////////////////////////////////////////

		// draw it
		window.clear();
		window.draw(ui);

		if (fpsRenderPeriod > 1) {
			currentFps = 1.f / clock.getElapsedTime().asSeconds();
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << currentFps;
			fpsToDraw = oss.str();
			fpsRenderPeriod = 0; // reset renderer period
			// Update FPS string value
			fpsText->setString("FPS: " + fpsToDraw);
		}

		window.draw(*fpsText);
		window.display();

		fpsRenderPeriod += clock.getElapsedTime().asSeconds();
	}

	return 0;
}