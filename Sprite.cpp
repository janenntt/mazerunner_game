#include "Sprite.h"
int Sprite::size = 1;
int Sprite::scale = 16;
//spriteSheet Sprite::Tiles("classic.png");
Sprite::Sprite(){};
Sprite::Sprite(int Px, int Py, int Pox, int Poy):Px(Px*16), Py(Py*16), Pox(Pox*32), Poy(Poy*32){
// this->Px = Px*16;
// this->Py = Py*16;
// this->Pox = Pox*scale*2;
// this->Poy = Poy*scale*2;
this->sprite = new sf::Sprite;
}

// :Px(Px * 16), Py(Py * 16), Pox(Pox*scale*2), Poy(Poy*scale*2)
void Sprite::loadSprite(){}

sf::Sprite* Sprite::getSprite() {
    texture.loadFromFile("classic3.png");
    this->sprite->setTexture(texture);
    this->sprite->setTextureRect(sf::IntRect(this->Px, this->Py, scale, scale));
    this->sprite->setScale(2, 2);
    this->sprite->setPosition(this->Pox, this->Poy);
    return this->sprite;
}

void Sprite::setPx(int Px){
    this->Px = Px*scale;
}

void Sprite::setPy(int Py){
    this->Py = Py*scale;
}

void Sprite::setPox(int Pox){
    this->Pox = Pox;
}

void Sprite::setPoy(int Poy){
    this->Poy = Poy;
}

int Sprite::getPx(){
    return this->Px;
}

int Sprite::getPy(){
    return this->Py;
}

int Sprite::getPox(){
    return this->Pox;
}

int Sprite::getPoy(){
    return this->Poy;
}

void Sprite::update(){}

Sprite::~Sprite(){
    delete this->sprite;
}
