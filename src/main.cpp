#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");

    bool up, down, left, right;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) up = true;
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) up = false;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) down = true;
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) down = false;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) left = true;
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) left = false;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) right = true;
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) right = false;

        std::cout << "up: " << up << " down: " << down << " left: " << left << " right: " << right << std::endl;

        window.clear(sf::Color(50, 50, 50));
        window.setFramerateLimit(30);
        window.display();
    }

    return EXIT_SUCCESS;
}
