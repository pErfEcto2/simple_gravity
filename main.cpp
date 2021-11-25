#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "unistd.h"
#include "iostream"
using namespace sf;
using namespace std;
// this fun returns "true" if rect2 crosses rect1
bool intersects(RectangleShape &rect1, RectangleShape &rect2) {
    FloatRect r1 = rect1.getGlobalBounds();
    FloatRect r2 = rect2.getGlobalBounds();
    return r1.intersects(r2);
}

int main() {
    int delay = 10000;
    RenderWindow window(VideoMode(100, 100), "jumps", Style::Fullscreen);
    Event event;

    bool canJump = false;
    int speedY = 0;
    int speedX = 0;
    int g = 10;

    RectangleShape rect(Vector2f(100, 100));
    rect.setPosition(Vector2f(300, VideoMode::getDesktopMode().height - 130));

    RectangleShape floor(Vector2f(2000, 30));
    floor.setFillColor(Color::Green);
    floor.setPosition(Vector2f(0, VideoMode::getDesktopMode().height - 30));

    RectangleShape rightWall(Vector2f(30, 2000));
    rightWall.setPosition(Vector2f(VideoMode::getDesktopMode().width - 30, 0));
    rightWall.setFillColor(Color::Green);

    RectangleShape leftWall(Vector2f(30, 2000));
    leftWall.setPosition(Vector2f(0, 0));
    leftWall.setFillColor(Color::Green);

    RectangleShape topWall(Vector2f(2000, 30));
    topWall.setPosition(Vector2f(0, 0));
    topWall.setFillColor(Color::Green);

    while (window.isOpen()) {
        while (window.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed) {
                window.close();
                return 0;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::W) && canJump) {
            rect.setPosition(Vector2f(rect.getPosition().x, rect.getPosition().y - 1));
            speedY = -99;
            canJump = false;
        }

        if (rect.getPosition().y + speedY + 50 <= floor.getPosition().y) {
            rect.setPosition(Vector2f(rect.getPosition().x + speedX, rect.getPosition().y + speedY));
            speedY += g;
        }

        if (intersects(rect, floor)) {
            rect.setPosition(Vector2f(rect.getPosition().x, floor.getPosition().y - 100));
            speedY = 0;
            speedX = 0;
            canJump = true;
        }

        if (Keyboard::isKeyPressed(Keyboard::D)) {
            speedX = 40;
        }

        if (Keyboard::isKeyPressed(Keyboard::A)) {
            speedX = -40;
        }
        
        if (rect.getPosition().x + speedX <= leftWall.getPosition().x + 30) {
            rect.setPosition(Vector2f(leftWall.getPosition().x + 30, rect.getPosition().y));
            speedX *= -1;
        }

        if (rect.getPosition().x + speedX + 100 >= rightWall.getPosition().x) {
            rect.setPosition(Vector2f(rightWall.getPosition().x - 100, rect.getPosition().y));
            speedX *= -1;
        }

        if (rect.getPosition().y + speedY <= topWall.getPosition().y + 30) {
            rect.setPosition(Vector2f(rect.getPosition().x, topWall.getPosition().y + 30));
            speedY *= -1;
        }

        window.clear();
        window.draw(rect);
        window.draw(rightWall);
        window.draw(leftWall);
        window.draw(topWall);
        window.draw(floor);
        window.display();

        usleep(delay);
    }
}