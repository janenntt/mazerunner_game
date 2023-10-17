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
        sf::RenderWindow window; // game window
        sf::Font font;
        // text displaying for the level, game start/win/lose messages
        sf::Text level;
        sf::Text Start;
        sf::Text win;
        sf::Text lose;

        // Flag indicating if the game has started, win/lose conditions
        bool drawStart;
        bool winGame;
        bool loseGame;
        mapCreation *level1;

    public:
        game(); // constructor
        void run(); // method to run the game loop
        void draw(); // method to draw game elements
        void processEvents(); // method to process user input events
        ~game(); // destructor
};
#endif
