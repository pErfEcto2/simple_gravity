#include "System.h"

sf::Vector2f operator+(sf::Vector2f const &v1, int const &n) {
    return sf::Vector2f(v1.x + n, v1.y + n);
}
sf::Vector2f operator-(sf::Vector2f const &v1, int const &n) {
    return sf::Vector2f(v1.x - n, v1.y - n);
}
sf::Vector2f operator*(sf::Vector2f const &v1, int const &n) {
    return sf::Vector2f(v1.x * n, v1.y * n);
}
sf::Vector2f operator/(sf::Vector2f const &v1, int const &n) {
    return sf::Vector2f(v1.x / n, v1.y / n);
}

bool intersects(Star s1, Star s2, float d) {
    return s1.getRadius() + s2.getRadius() >= d;
}

System::System(int n) {
    num = n;
    for (int i = 0; i < num; i++) {
        int randomMass = 200 + std::rand() % 401;
        Star star(randomMass);
        star.setPos(sf::Vector2f(star.getRadius() + rand() % 1001, star.getRadius() + rand() % 601));
        stars.push_back(star);
    }
};

void System::update() {
    std::vector<sf::Vector2f> additions = {};
    for (int i = 0; i < stars.size(); i++) {
        sf::Vector2f accelerVec = {0, 0};
        stars[i].setLastPos(stars[i].getPos());
        for (int j = 0; j < stars.size(); j++) {
            if (i != j) {
                sf::Vector2f posI = stars[i].getPos();
                sf::Vector2f posJ = stars[j].getPos();
                float dist = std::sqrt(std::pow(posJ.x - posI.x, 2) + std::pow(posJ.y - posI.y, 2));
                float acceler = std::fmod(50 * stars[j].getMass() / std::pow(dist, 2), MAXSPEED);
                float k = acceler / dist;
                float dX = stars[j].getPos().x - stars[i].getPos().x;
                float dY = stars[j].getPos().y - stars[i].getPos().y;
                accelerVec = {std::fmod(accelerVec.x + dX * k, MAXSPEED), std::fmod(accelerVec.y + dY * k, MAXSPEED)};

                if (stars[i].getRadius() + stars[j].getRadius() < dist) {
                    stars[i].setLastPos(posI);
                }
                else if (stars[i].getRadius() + stars[j].getRadius() >= dist) {
                    accelerVec = accelerVec * (-1);
                    stars[i].setPos(stars[i].getLastPos());
                }
            }
        }
        additions.push_back(accelerVec);
    }
    for (int i = 0;  i < stars.size(); i++) {
        stars[i].incVel(additions[i]);
        stars[i].update();
    }
};

void System::draw(sf::RenderTarget &w) {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw(w);
    }
};