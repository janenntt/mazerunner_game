#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Bomber.h"
#include "Move.h"
#ifndef GAME_H
#define GAME_H
class game{
    private:
        sf::RenderWindow window;
        
        //Define the text
        sf::Font font;
        sf::Text level;
        sf::Text bomb;
        sf::Text time;
        sf::Text Start;
        
        sf::Sprite pauseGame;
        sf::Sprite playGame;
        sf::Sprite newGame;

        int timeEachLevel;
        int limitTime;
        bool drawStart;
        bool getTimeLimit;
        //TO DO: Handle the time for each level.
        
    public:
        // Adding all the sprite of each blocks and the bomb.
        static std::vector<Sprite*> block;
        // // Update the sprite of the main player and the mob.
        // static std::vector<Animal> enemy;
        // // vector to determine the position of Bomber
        static std::vector<std::vector<int> >id_objects;
        // // vector to determine the position of the bomb.
        static std::vector<std::vector<int> >list_kills;
        static std::vector<Animal*> enemy;

        static Bomber *player;
      

        game();
        void startGame();
        void run();
        void draw();
        void processEvents();
};
#endif