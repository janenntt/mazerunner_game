#include "SFML/Graphics.hpp"

#include "mapCreation.h"

#include <iostream>


int main() {
  bool ready = false;
  bool loseGame = false;
  bool winGame = false;
  sf::Font font;
  font.loadFromFile("Arial.ttf");
  sf::Text youWin;
  sf::Text youLose;
  youWin.setFont(font);
  youWin.setString("You win!");
  youWin.setCharacterSize(20);
  youWin.setFillColor(sf::Color::Black);
  youWin.setStyle(sf::Text::Bold);
  youWin.setPosition(300, 200);

  youLose.setFont(font);
  youLose.setString("You lose!");
  youLose.setCharacterSize(20);
  youLose.setFillColor(sf::Color::Black);
  youLose.setStyle(sf::Text::Bold);
  youLose.setPosition(300, 200);
  sf::RenderWindow window(sf::VideoMode(800, 480), "a");
  mapCreation a;
  sf::Time timePerFrame = sf::seconds(1.f / 60.f);
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
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
          if (event.key.code == sf::Keyboard::Space) {
            ready = true;
          }
          if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            if (ready) {
              Move::up(a.player);
            }
          }
          if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            if (ready) {
              Move::down(a.player);
            }
          }
          if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            if (ready) {
              Move::left(a.player);
            }
          }
          if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            if (ready) {
              Move::right(a.player);
            }
          }
        }
        if (ready && !loseGame) {
          a.enemy1 -> update();
          a.enemy2 -> update();
          a.enemy3 -> update();
          a.enemy4 -> update();
          a.enemy5 -> update();
          a.enemy6 -> update();
        }
      }
    }
    if ((a.player -> getPox() == a.enemy1 -> getPox() && a.player -> getPoy() == a.enemy1 -> getPoy()) ||
      (a.player -> getPox() == a.enemy2 -> getPox() && a.player -> getPoy() == a.enemy2 -> getPoy()) ||
      (a.player -> getPox() == a.enemy3 -> getPox() && a.player -> getPoy() == a.enemy3 -> getPoy()) ||
      (a.player -> getPox() == a.enemy4 -> getPox() && a.player -> getPoy() == a.enemy4 -> getPoy()) ||
      (a.player -> getPox() == a.enemy4 -> getPox() && a.player -> getPoy() == a.enemy4 -> getPoy()) ||
      (a.player -> getPox() == a.enemy5 -> getPox() && a.player -> getPoy() == a.enemy4 -> getPoy()) ||
      (a.player -> getPox() == a.enemy6 -> getPox() && a.player -> getPoy() == a.enemy4 -> getPoy())) {
      loseGame = true;
    }
    if (a.player -> getPox() == 24 * 32 && a.player -> getPoy() == 6 * 32) {
      winGame = true;
    }
    window.clear();
    for (Sprite *
      var: a.block) {
      window.draw( *
        var -> getSprite());
    }
    if (ready && winGame) {
      window.draw(youWin);
    }
    if (ready && loseGame) {
      window.draw(youLose);
    }
    std::cout << loseGame << std::endl;
    window.display();
  }
}