#include "Star.h"

Star::Star(float m) {
    mass = m;
    size = mass / 4;
    sprite = sf::CircleShape(size);
    sprite.setFillColor(sf::Color(std::fmod(mass, MAXMASS), std::fmod(mass * 2, MAXMASS), std::fmod(mass / 2, MAXMASS)));
    sprite.setOrigin(sf::Vector2f(size, size));
    vel = sf::Vector2f(10 - rand() % 21, 10 - rand() % 21);
    screenSize = sf::VideoMode::getDesktopMode();
};

float Star::getMass() {
    return mass;
};

sf::Vector2f Star::getPos() {
    return pos;
};

void Star::setPos(sf::Vector2f p) {
    pos = p;
    sprite.setPosition(sf::Vector2f(pos));
};

void Star::incMass(float m) {
    mass = mass + m;
    sprite.setRadius((int)sprite.getRadius() + m);
    sprite.setFillColor(sf::Color(mass, mass * 2, mass / 2));
};

float Star::getRadius() {
    return sprite.getRadius();
};

void Star::update() {
    vel = {std::fmod(vel.x, MAXSPEED) / DECCELERATION, std::fmod(vel.y, MAXSPEED) / DECCELERATION};
    pos = pos + vel;
    if (pos.x - size <= 0) {
        pos = sf::Vector2f(size, pos.y);
        vel = sf::Vector2f(vel.x * -1, vel.y);
    }
    if (pos.x + size >= screenSize.width) {
        pos = sf::Vector2f(screenSize.width - size, pos.y);
        vel = sf::Vector2f(vel.x * -1, vel.y);
    }
    if (pos.y - size <= 0) {
        pos = sf::Vector2f(pos.x, size);
        vel = sf::Vector2f(vel.x, vel.y * -1);
    }
    if (pos.y + size >= screenSize.height) {
        pos = sf::Vector2f(pos.x, screenSize.height - size);
        vel = sf::Vector2f(vel.x, vel.y * -1);
    }
    sprite.setPosition(sf::Vector2f(pos));
};

sf::Vector2f Star::getVel() {
    return vel;
};

void Star::incVel(sf::Vector2f v) {
    vel = vel + v;
};

void Star::setColor(sf::Color c) {
    sprite.setFillColor(c);
};

void Star::draw(sf::RenderTarget &w) {
    w.draw(sprite);
};