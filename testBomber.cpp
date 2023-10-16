#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "mapCreation.h"
#include "game.h"
#include "Bomber.h"
#include "Animal.h"
#include "Move.h"

/// HANDLE THE FRAME RATE ///

int main() {
    sf::Font font;
    sf::Text level;
    sf::Text Start;
    sf::Text win;

    int limitTime;
    bool drawStart = false;
    bool winGame = false;

    font.loadFromFile("Arial.ttf");
    level.setFont(font);
    Start.setFont(font);
    win.setFont(font);

    level.setString("Level: 1");
    Start.setString("Press Space to start the game");
    win.setString("You have won the game");

    level.setCharacterSize(14);
    Start.setCharacterSize(20);
    win.setCharacterSize(20);

    level.setFillColor(sf::Color::Black);
    Start.setFillColor(sf::Color::Black);
    win.setFillColor(sf::Color::Black);

    level.setStyle(sf::Text::Bold);
    Start.setStyle(sf::Text::Bold);
    win.setStyle(sf::Text::Bold);

    level.setPosition(390, 10);
    Start.setPosition(200, 200);
    win.setPosition(300, 200);

    sf::RenderWindow window(sf::VideoMode(800, 480), "a");
    game a;
    mapCreation b;
    b.createMap();
    Bomber * player = new Bomber(1, 0, 1, 1);
    game::block.push_back(player);
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    window.draw( * player -> getSprite());
    window.draw(level);
    window.draw(Start);

    while (window.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space){
                        drawStart = true;
                    }
                    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up ) {
                        if(drawStart){
                            Move::up(player);
                        }
                    }
                    if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                        if(drawStart){
                            Move::down(player);
                        }
                    }
                    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                        if(drawStart){
                            Move::left(player);
                        }
                    }
                    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                        if(drawStart){
                            Move::right(player);
                        }
                    }
                }
            }
            if (player->getPox() == 24*32 && player->getPoy() == 6*32){
                winGame = true;
            }
        }
        window.clear();
        for (Sprite *var: game::block) {
            window.draw( *var -> getSprite());
        }
        window.draw(level);
        if(drawStart == false){
            window.draw(Start);
        }
        if (drawStart && winGame){
            window.draw(win);
        }
        window.display();
    }
    delete player;
    game::id_objects.clear();
    game::list_kills.clear();
    game::id_objects.shrink_to_fit();
    game::list_kills.shrink_to_fit();
}

