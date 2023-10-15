#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "mapCreation.h"
#include "game.h"
#include "Bomber.h"
#include "Animal.h"
#include "Move.h"

/// HANDLE THE FRAME RATE.
///
int main(){
sf::RenderWindow window(sf::VideoMode(800, 480), "a");
game a;
mapCreation b;
b.createMap();
// Sprite *c = new Sprite(0, 3, 0, 0);
//game::block.push_back(c);
//game a;
//mapCreation b;
//b.createMap();
//Entity c(0, 3, 32, 32);
Bomber *player= new Bomber(1, 0, 1, 1);
game::block.push_back(player);
//game::block.push_back(c);
sf::Time timePerFrame = sf::seconds(1.f/60.f);
//sf::Event event;
sf::Clock clock;
sf::Time timeSinceLastUpdate = sf::Time::Zero;
window.draw(*player->getSprite());
while(window.isOpen()){
timeSinceLastUpdate += clock.restart();
while (timeSinceLastUpdate>timePerFrame){
timeSinceLastUpdate -= timePerFrame;
sf::Event event;
while (window.pollEvent(event)) {
if (event.type == sf::Event::Closed) {
window.close();
}
if (event.type == sf::Event::KeyPressed){
if(event.key.code == sf::Keyboard::W){
Move::up(player);
// std::cout<< player->getPoy()<< std::endl;
// std::cout<< player->getPox()<< std::endl;
// std::cout << std::endl;
}
if(event.key.code == sf::Keyboard::S){
Move::down(player);
// std::cout<< player->getPoy()<< std::endl;
// std::cout<< player->getPox()<< std::endl;
// std::cout << std::endl;
//std::cout<<player->getPoy() << std::endl;
}
if(event.key.code == sf::Keyboard::A){
Move::left(player);
}
if(event.key.code == sf::Keyboard::D){
Move::right(player);
// std::cout<< player->getPoy()<< std::endl;
// std::cout<< player->getPox()<< std::endl;
// std::cout << std::endl;
// std::cout << std::floor(player->getPox()/32) << std::endl;
// std::cout << std::floor(player->getPoy()/32) << std::endl;
// std::cout << std::endl;
}
std::cout<< player->getPoy()<< std::endl;
std::cout<< player->getPox()<< std::endl;
std::cout << std::endl;
}
}
}
window.clear();
for (Sprite* var: game::block){
window.draw(*var->getSprite());
}
// for (int i = 0; i < 376; i++){
// window.draw(*game::block[i]->getSprite());
// }
//window.draw(*player->getSprite());
window.display();
// std::cout<< player->getPoy()<< std::endl;
// std::cout<< player->getPox()<< std::endl;
}
delete player;
game::id_objects.clear();
game::list_kills.clear();
game::id_objects.shrink_to_fit();
game::list_kills.shrink_to_fit();
}


