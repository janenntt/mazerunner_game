#include "Oneal.h"

Oneal::Oneal(int Px, int Py, int Pox, int Poy): Animal(Px, Py, Pox, Poy){};

void Oneal::update(){
    // Check if the Oneal's position is aligned with the grid
    if (this->getPoy() % 16 == 0 && this->getPox() % 16 == 0 ){
        // Directions to move based on the player's position
        if (mapCreation::player->getPox() < this->getPox()){
            Move::left(this); // Move the Oneal to the left
        }
        if (mapCreation::player->getPox() > this->getPox()){
            Move::right(this); // Move the Oneal to the right
        }
        if (mapCreation::player->getPoy() < this->getPoy()){
            Move::up(this); // Move the Oneal upwards
        }
        if (mapCreation::player->getPoy() > this->getPoy()){
            Move::down(this); // Move the Oneal downwards
        }
    }
}
