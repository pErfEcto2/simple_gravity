#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "iostream"
#include "System.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(100, 100), "gravity", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    sf::Event event;

    std::srand(time(0));
    int n = 10;
    System sys(n);
    std::vector<System> systems;
    systems.push_back(sys);

    while (window.isOpen()) {
        while (window.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
                return 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                systems.pop_back();
                System sys(n);
                systems.push_back(sys);
            }

        }
        systems[0].update();

        window.clear();
        systems[0].draw(window);
        window.display();
    }
}