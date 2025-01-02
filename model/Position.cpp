#include "Position.h"

Position::Position(unsigned x, unsigned y) : x(x), y(y)
{
}

Position Position::getRandomPosition(unsigned xBoundary, unsigned yBoundary)
{
  // srand(42);

  return Position(
      static_cast<unsigned>((static_cast<double>(rand()) / RAND_MAX) * xBoundary),
      static_cast<unsigned>((static_cast<double>(rand()) / RAND_MAX) * yBoundary));
}