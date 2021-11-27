#include "System.h"

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
    for (int i = 0; i < stars.size(); i++) {
        sf::Vector2f accelerVec = {0, 0};
        for (int j = 0; j < stars.size(); j++) {
            if (i != j) {
                sf::Vector2f posI = stars[i].getPos();
                sf::Vector2f posJ = stars[j].getPos();
                float dist = std::sqrt(std::pow(posJ.x - posI.x, 2) + std::pow(posJ.y - posI.y, 2));
                float acceler = std::fmod((ADD / std::pow(num, 1.005)) * stars[j].getMass() / std::pow(dist, 2), MAXSPEED);
                float k = acceler / dist;
                float dX = stars[j].getPos().x - stars[i].getPos().x;
                float dY = stars[j].getPos().y - stars[i].getPos().y;
                accelerVec = {std::fmod(accelerVec.x + dX * k, MAXSPEED), std::fmod(accelerVec.y + dY * k, MAXSPEED)};

                //if (intersects(stars[i], stars[j], dist)) {
                //    stars[i].setColor(sf::Color(255, 255, 255));
                //    stars[j].setColor(sf::Color(255, 255, 255));
                //}
                //else {
                //    stars[i].setColor(sf::Color(std::fmod(stars[i].getMass(), MAXMASS), std::fmod(stars[i].getMass() * 2, MAXMASS), std::fmod(stars[i].getMass() / 2, MAXMASS)));
                //    stars[i].setColor(sf::Color(std::fmod(stars[j].getMass(), MAXMASS), std::fmod(stars[j].getMass() * 2, MAXMASS), std::fmod(stars[j].getMass() / 2, MAXMASS)));
                //}
            }
        }
        stars[i].incVel(accelerVec);
        stars[i].update();
    }
};

void System::draw(sf::RenderTarget &w) {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw(w);
    }
};