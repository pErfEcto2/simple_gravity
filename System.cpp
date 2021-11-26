#include "System.h"
#include "iostream"

System::System(int num) {
    for (int i = 0; i < num; i++) {
        int randomMass = 10 + std::rand() % 21;
        Star star(randomMass);
        star.setPos(sf::Vector2i(star.getRadius() + rand() % 1001, star.getRadius() + rand() % 601));
        stars.push_back(star);
    }
};

void System::update() {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].update();
    }
};

void System::draw(sf::RenderTarget &w) {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw(w);
    }
};