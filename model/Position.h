#pragma once
#include <iostream>

class Position
{
public:
  Position(unsigned short x, unsigned short y);
  unsigned short x;
  unsigned short y;

  static Position getRandomPosition(unsigned short xBoundary, unsigned short yBoundary);
};