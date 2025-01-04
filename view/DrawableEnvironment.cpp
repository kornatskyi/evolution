#include "DrawableEnvironment.h"
#include "Environment.h"

DrawableEnvironment::DrawableEnvironment(Environment &environment) : environment(environment)
{
}

void drawGrid(sf::RenderTarget &target,
              sf::RenderStates states)
{
  const float LINE_THICKNESS = 1;
  const unsigned NUM_OF_CELLS_IN_A_ROW = ModelConfig::WIDTH / ModelConfig::CELL_SIZE;

  sf::VertexArray vertices(sf::PrimitiveType::Triangles);

  for (size_t i = 0; i < NUM_OF_CELLS_IN_A_ROW; i++)
  {

    float point = i * (ModelConfig::WIDTH / NUM_OF_CELLS_IN_A_ROW);
    sf::Vertex topLeft, bottomLeft, topRight, bottmRight;

    topLeft.color = sf::Color(255, 255, 255, 128);
    topRight.color = sf::Color(255, 255, 255, 128);
    bottomLeft.color = sf::Color(255, 255, 255, 128);
    bottmRight.color = sf::Color(255, 255, 255, 128);

    // Vertical lines
    topLeft.position = sf::Vector2f(point, 0);
    topRight.position = sf::Vector2f(point + LINE_THICKNESS, 0);
    bottomLeft.position = sf::Vector2f(point, ModelConfig::HEIGHT);
    bottmRight.position = sf::Vector2f(point + LINE_THICKNESS, ModelConfig::HEIGHT);

    vertices.append(topLeft);
    vertices.append(bottomLeft);
    vertices.append(topRight);
    vertices.append(topRight);
    vertices.append(bottomLeft);
    vertices.append(bottmRight);

    point = i * (ModelConfig::HEIGHT / NUM_OF_CELLS_IN_A_ROW);

    // Horisontal lines
    topLeft.position = sf::Vector2f(0, point);
    topRight.position = sf::Vector2f(ModelConfig::WIDTH, point);
    bottomLeft.position = sf::Vector2f(0, point - LINE_THICKNESS);
    bottmRight.position = sf::Vector2f(ModelConfig::WIDTH + LINE_THICKNESS, point - LINE_THICKNESS);

    vertices.append(topLeft);
    vertices.append(bottomLeft);
    vertices.append(topRight);
    vertices.append(topRight);
    vertices.append(bottomLeft);
    vertices.append(bottmRight);
  }

  target.draw(vertices, states);

  // Draw bounding box
  sf::RectangleShape topLine({ModelConfig::WIDTH, LINE_THICKNESS});
  topLine.setPosition((sf::Vector2f({0, 0})));
  target.draw(topLine, states);

  sf::RectangleShape bottomLine({ModelConfig::WIDTH, LINE_THICKNESS});
  bottomLine.setPosition((sf::Vector2f({0.f, ModelConfig::HEIGHT})));
  target.draw(bottomLine, states);

  sf::RectangleShape leftLine({LINE_THICKNESS, ModelConfig::HEIGHT});
  leftLine.setPosition((sf::Vector2f({0.f, 0.f})));
  target.draw(leftLine, states);

  sf::RectangleShape rightLine({LINE_THICKNESS, ModelConfig::HEIGHT});
  rightLine.setPosition((sf::Vector2f({ModelConfig::WIDTH - LINE_THICKNESS, 0.f})));
  target.draw(rightLine, states);
}

void DrawableEnvironment::draw(sf::RenderTarget &target,
                               sf::RenderStates states) const
{

  // Apply the origin shift to RenderStates
  sf::Transform transform;
  transform.translate(sf::Vector2f(300, 0));
  states.transform *= transform;

  // Draw grid
  drawGrid(target, states);

  // Create creature shape

  sf::VertexArray creaturesToRender(sf::PrimitiveType::Triangles);

  // Draw each creature
  for (const Creature &creature : environment.population)
  {
    sf::Vertex topLeft, bottomLeft, topRight, bottmRight;

    // Create square shape for each creature
    topLeft.position = sf::Vector2f({static_cast<float>(creature.position.x), static_cast<float>(creature.position.y)});
    topRight.position = sf::Vector2f({static_cast<float>(creature.position.x) + ModelConfig::CELL_SIZE, static_cast<float>(creature.position.y)});
    bottomLeft.position = sf::Vector2f({static_cast<float>(creature.position.x), static_cast<float>(creature.position.y) - ModelConfig::CELL_SIZE});
    bottmRight.position = sf::Vector2f({static_cast<float>(creature.position.x) + ModelConfig::CELL_SIZE, static_cast<float>(creature.position.y) - ModelConfig::CELL_SIZE});

    creaturesToRender.append(topLeft);
    creaturesToRender.append(bottomLeft);
    creaturesToRender.append(topRight);
    creaturesToRender.append(topRight);
    creaturesToRender.append(bottomLeft);
    creaturesToRender.append(bottmRight);

    target.draw(creaturesToRender, states);
  }
}