#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Bomber.h"
#include "Move.h"
#include "mapCreation.h"
#ifndef GAME_H
#define GAME_H
class game{
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text level;
        sf::Text readyText;
        sf::Texture startMenuTexture;
        sf::Texture winTexture;
        sf::Texture loseTexture;
        sf::Sprite startMenu;
        sf::Sprite win;
        sf::Sprite lose;
        bool drawStart;
        bool ready;
        bool winGame;
        bool loseGame;
        mapCreation *level1;


    public:
        game();
        void run();
        void draw();
        void processEvents();
        ~game();
    };
#endif
