#include <SFML/Graphics.hpp>
#include <iostream>

int windowWidth = 1280;
int windowHeight = 720;
int windowHalfWidth = windowWidth / 2;
int windowHalfHeight = windowHeight / 2;

using namespace sf;
using namespace std;

class platformClass {
    public:
        float xPos;
        float yPos;

        float xVel;
        float yVel;

        platformClass(float xPos, float yPos) {
            xPos = xPos;
            yPos = yPos;
        }
};

class playerClass {
    public:
        bool PlayerFaceRight;
        bool onGround;

        float playerSpeed;

        float xPos;
        float yPos;

        float xVel;
        float yVel;

        playerClass() {
            PlayerFaceRight = true;

            playerSpeed = 5;

            xPos = 0;
            yPos = 0;

            xVel = 0;
            yVel = 0;

            onGround = false;
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

            if(onGround) {
                yVel = 0;
            }

            xPos += xVel;
            yPos += yVel;

            collide();
        }

        void collide() {
            if(yPos > 400) {
                onGround = true;
            }
        }
};

int main() {
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

    bool playerUp, playerDown, playerLeft, playerRight;

    Font consola;
    consola.loadFromFile("assets/fonts/consola.ttf");

    Texture playerTexture;
    playerTexture.loadFromFile("assets/images/player.png");
    Sprite playerSprite(playerTexture);
    playerSprite.setScale(2.5, 2.5);

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

        window.clear(Color(135, 206, 235));
        window.setFramerateLimit(60);

        window.draw(playerSprite);
        playerSprite.setPosition(Vector2f(playerObj.xPos, playerObj.yPos));

        window.display();
    }

    return EXIT_SUCCESS;
}
