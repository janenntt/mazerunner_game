#include "SFML/Graphics.hpp"

#include "mapCreation.h"

#include <iostream>


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 480), "a");
  mapCreation a;
  sf::Time timePerFrame = sf::seconds(1.f / 60.f);
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  window.draw( * a.player -> getSprite());
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
          if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            Move::up(a.player);
          }
          if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            Move::down(a.player);
          }
          if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            Move::left(a.player);
          }
          if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            Move::right(a.player);
          }
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