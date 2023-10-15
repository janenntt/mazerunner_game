#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#ifndef SPRITE_H
#define SPRITE_H
class Sprite{
private:
//static spriteSheet Tiles;
// Position in the map
static int size;
int Pox;
int Poy;
// Position in the spritesheet.
int Px;
int Py;
static int scale;
sf::Texture texture;
sf::Image image;
sf::Sprite *sprite;
public:
Sprite();
Sprite(int Px, int Py, int Pox, int Poy); // Px and Py are positions of the sprite on the spritesheet.
//~Sprite();
sf::Sprite* getSprite();
sf::Texture getTexture();
void setPox(int Pox);
void setPoy(int Poy);
void setPx(int Px);
void setPy(int Py);
int getPx();
int getPy();
int getPox();
int getPoy();
void loadSprite();
virtual void update();
~Sprite();
};
#endif
