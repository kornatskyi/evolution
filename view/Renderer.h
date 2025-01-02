#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>
#include <memory>
#include "UI.h"
#include "Environment.h"

constexpr int WIDTH = 1600;
constexpr int HEIGHT = 900;

void render(Environment environement);