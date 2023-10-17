#include "Sprite.h"
int Sprite::size = 1;
int Sprite::scale = 16;
Sprite::Sprite(){};
Sprite::Sprite(int Px, int Py, int Pox, int Poy):Px(Px*16), Py(Py*16), Pox(Pox*32), Poy(Poy*32){
    this->sprite = new sf::Sprite;
}

void Sprite::loadSprite(){};

sf::Sprite* Sprite::getSprite() {
    // Handle exceptions when loading spritesheet
    try {
        // Check if the file is loaded successfully
        if (!texture.loadFromFile("classic3.png")){
            throw std::runtime_error ("Failed to load file classic3.png");
        }
        this->sprite->setTexture(texture);
        this->sprite->setTextureRect(sf::IntRect(this->Px, this->Py, scale, scale));
        this->sprite->setScale(2, 2);
        this->sprite->setPosition(this->Pox, this->Poy);
        
    } catch (const std::exception& e){
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
    return this->sprite;
}

void Sprite::setPx(int Px){
    this->Px = Px*scale;
};
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
// delete this->sprite;
}


