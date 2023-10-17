#include "SFML/Graphics.hpp"

#include "mapCreation.h"

#include <iostream>

int main() {
  bool ready = false;
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
        if (ready) {
          a.enemy1 -> update();
          a.enemy2 -> update();
          a.enemy3 -> update();
          a.enemy4 -> update();
          a.enemy5 -> update();
          a.enemy6 -> update();
        }
      }
    }
    window.clear();
    for (Sprite *
      var: a.block) {
      window.draw( *
        var -> getSprite());
    }
    window.display();
  }
}