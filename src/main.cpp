#include <SFML/Graphics.hpp>
#include <iostream>

int windowWidth = 1280;
int windowHeight = 720;

using namespace sf;
using namespace std;

class playerClass {
    public:
        bool PlayerFaceRight;

        float playerSpeed;

        float xPos;
        float yPos;

        float xVel;
        float yVel;

        playerClass() {
            PlayerFaceRight = true;

            playerSpeed = 2.5;

            xPos = 0;
            yPos = 0;

            xVel = 0;
            yVel = 0;
        }

        void Update(bool playerUp, bool playerDown, bool playerLeft, bool playerRight) {
            if(playerUp) {
                yVel = -playerSpeed;
            }

            if(playerDown) {
                yVel = playerSpeed;
            }

            if(playerLeft) {
                PlayerFaceRight = false;
                xVel = -playerSpeed;
            }

            if(playerRight) {
                PlayerFaceRight = true;
                xVel = playerSpeed;
            }

            if(!(playerUp || playerDown)) {
                yVel = 0;
            }

            if(!(playerLeft || playerRight)) {
                xVel = 0;
            }

            xPos += xVel;
            yPos += yVel;
        }
};

int main() {
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

    bool playerUp, playerDown, playerLeft, playerRight;

    playerClass playerObj;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Up)) playerUp = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Up))) playerUp = false;

        if(Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;

        if(Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;

        if(Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
        if(!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight = false;

        playerObj.Update(playerUp, playerDown, playerLeft, playerRight);

        window.clear(Color(50, 50, 50));
        window.setFramerateLimit(30);
        window.display();
    }

    return EXIT_SUCCESS;
}
