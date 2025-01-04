#include "Position.h"
#include "ModelConfig.h"

Position::Position(unsigned short x, unsigned short y) : x(x), y(y)
{
}

Position Position::getRandomPosition(unsigned short xBoundary, unsigned short yBoundary)
{
  // srand(42);

  return Position(
      static_cast<unsigned short>(((static_cast<double>(rand()) / RAND_MAX) * xBoundary) / ModelConfig::CELL_SIZE) * ModelConfig::CELL_SIZE,
      static_cast<unsigned short>(((static_cast<double>(rand()) / RAND_MAX) * yBoundary) / ModelConfig::CELL_SIZE) *
          ModelConfig::CELL_SIZE);
}