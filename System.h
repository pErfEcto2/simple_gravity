#pragma once
#include "SFML/Graphics.hpp"
#include "vector"
#include "Star.h"
#include "random"

class System {
private:
    std::vector<Star> stars;   
public:
    System(int num);
    void draw(sf::RenderTarget &w);
    void update();
};