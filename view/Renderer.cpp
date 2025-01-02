#include "Renderer.h"
#include "Environment.h"
#include "UI.h"
#include "DrawableEnvironment.h"

class FPSMessurer
{
public:
  // Clock for measuring FPS
  sf::Clock clock;
  float lastTime = 0;
  float currentFps = 0;
  std::string fpsToDraw = std::to_string(currentFps);
  float fpsRenderPeriod = 0;
  std::string calculateNewFPS()
  {
    currentFps = 1.f / clock.getElapsedTime().asSeconds();
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << currentFps;
    fpsToDraw = oss.str();
    fpsRenderPeriod = 0; // reset renderer period
    return fpsToDraw;
  }
};

void render(Environment environement)
{
  // Create a window
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}),
                          "Evolution 🧬", sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // sync with graphics card refresh rate
  window.setPosition(sf::Vector2i(100, 0));

  // Utils
  FPSMessurer fpsMessurer;

  // Init UI class
  UI ui;
  auto fpsText = ui.createText("FPS: " + fpsMessurer.fpsToDraw, sf::Vector2f(WIDTH - 200, 10));

  // World
  DrawableEnvironment drawableEnvironment(environement);

  // run the main loop
  while (window.isOpen())
  {
    fpsMessurer.clock.restart();
    // handle events
    while (const auto event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
      {
        window.close();
      }
    }

    window.clear(sf::Color(31, 31, 31));

    /////////////////////////////////////////////////
    // All updates should be happening in this block.
    /////////////////////////////////////////////////
    window.draw(ui);
    window.draw(drawableEnvironment);

    if (fpsMessurer.fpsRenderPeriod > 1)
    {
      // Update FPS string value
      fpsText->setString("FPS: " + fpsMessurer.calculateNewFPS());
    }

    window.draw(*fpsText);
    window.display();

    fpsMessurer.fpsRenderPeriod += fpsMessurer.clock.getElapsedTime().asSeconds();
  }
}