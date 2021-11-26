#include "Star.h"
#include "iostream"

Star::Star(int m) {
    mass = m;
    size = mass * 2;
    sprite = sf::CircleShape(size);
    sprite.setFillColor(sf::Color(mass, mass * 2, mass / 2));
    sprite.setOrigin(sf::Vector2f(mass, mass));
    vel = sf::Vector2i(10 - rand() % 21, 10 - rand() % 21);
    screenSize = sf::VideoMode::getDesktopMode();
};

int Star::getMass() {
    return mass;
};

sf::Vector2i Star::getPos() {
    return pos;
};

void Star::setPos(sf::Vector2i p) {
    pos = p;
    sprite.setPosition(sf::Vector2f(pos));
};

void Star::incMass(int m) {
    mass = mass + m;
    sprite.setRadius((int)sprite.getRadius() + m);
    sprite.setFillColor(sf::Color(mass, mass * 2, mass / 2));
};

int Star::getRadius() {
    return sprite.getRadius();
};

void Star::update() {
    pos = pos + vel;
    if (pos.x - size <= 0) {
        pos = sf::Vector2i(size, pos.y);
        vel = sf::Vector2i(vel.x * -1, vel.y);
    }
    if (pos.x + size >= screenSize.width) {
        pos = sf::Vector2i(screenSize.width - size, pos.y);
        vel = sf::Vector2i(vel.x * -1, vel.y);
    }
    if (pos.y - size <= 0) {
        pos = sf::Vector2i(pos.x, size);
        vel = sf::Vector2i(vel.x, vel.y * -1);
    }
    if (pos.y + size >= screenSize.height) {
        pos = sf::Vector2i(pos.x, screenSize.height - size);
        vel = sf::Vector2i(vel.x, vel.y * -1);
    }
    sprite.setPosition(sf::Vector2f(pos));
};

void Star::draw(sf::RenderTarget &w) {
    w.draw(sprite);
};