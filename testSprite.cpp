#include "SFML/Graphics.hpp"

#include "Sprite.h"

#include <iostream>


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 480), "a");
  Sprite c(3, 2, 0, 0);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        c.setPx(1);
        c.setPoy(3);
      }
    }
    window.clear();
    window.draw( * c.getSprite());
    window.display();
  }
}