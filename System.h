#pragma once
#include "Star.h"

class System {
private:
    std::vector<Star> stars;
    int num;
public:
    System(int n);
    void draw(sf::RenderTarget &w);
    void update();
};