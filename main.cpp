#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>
#include "Renderer.h"
#include "Environment.h"


int main() {

  Environment environement;

  render(environement);
  return 0;
}