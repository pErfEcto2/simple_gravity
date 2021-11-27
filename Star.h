#pragma once
#include "SFML/Graphics.hpp"
#include "math.h"
#include "random"
#include "vector"
#include "SFML/Graphics.hpp"
#include "iostream"

#define MAXSPEED 100
#define DECCELERATION 1.1
#define ADD 100
#define MAXMASS 100

class Star {
private:
    float mass;
    sf::CircleShape sprite;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::VideoMode screenSize;
    float size;
public:
    Star(float m);
    float getMass();
    sf::Vector2f getPos();
    void setPos(sf::Vector2f p);
    void incMass(float m);
    float getRadius();
    void update();
    sf::Vector2f getVel();
    void incVel(sf::Vector2f v);
    void setColor(sf::Color c);
    void draw(sf::RenderTarget &w);
};