#include "SFML/Graphics.hpp"

#include "mapCreation.h"

#include <iostream>


int main() {
  sf::RenderWindow window(sf::VideoMode(800, 480), "a");
  mapCreation a;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {}
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