#include "Renderer.h"
#include "UI.h"

void render()
{
  // Create a window
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),
                          "Evolution 🧬", sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true); // sync with graphics card refresh rate
  window.setPosition(sf::Vector2i(100, 400));

  // Clock for measuring FPS
  sf::Clock clock;
  float lastTime = 0;
  float currentFps = 0;
  std::string fpsToDraw = std::to_string(currentFps);
  float fpsRenderPeriod = 0;

  // Init UI class
  UI ui;
  auto fpsText = ui.createText("FPS: " + fpsToDraw, sf::Vector2f(WIDTH - 200, 10));

  // run the main loop
  while (window.isOpen())
  {
    clock.restart();
    // handle events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

    /////////////////////////////////////////////////
    // All updates should be happening in this block.
    /////////////////////////////////////////////////

    window.draw(ui);

    if (fpsRenderPeriod > 1)
    {
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
}