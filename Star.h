#pragma once
#include "SFML/Graphics.hpp"

class Star {
private:
    int mass;
    sf::CircleShape sprite;
    sf::Vector2i pos;
    sf::Vector2i vel;
    sf::VideoMode screenSize;
    int size;
public:
    Star(int m);
    int getMass();
    sf::Vector2i getPos();
    void setPos(sf::Vector2i p);
    void incMass(int m);
    int getRadius();
    void update();
    void draw(sf::RenderTarget &w);
};