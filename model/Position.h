#pragma once
#include <iostream>

class Position
{
public:
  Position(unsigned x, unsigned y);
  unsigned x;
  unsigned y;

  static Position getRandomPosition(unsigned xBoundary, unsigned yBoundary);
};