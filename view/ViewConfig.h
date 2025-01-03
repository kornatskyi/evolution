#pragma once

namespace ViewConfig
{

  // General
  constexpr unsigned WIDTH = 1600;
  constexpr unsigned HEIGHT = 900;
  constexpr char TITLE[] = "Predator/pray simulation.";

  // Seeds
  constexpr int defaultSeed = 42;

  // Drawing
  bool drawBoundary = true;
  bool drawPhysics = false;
} // namespace Config