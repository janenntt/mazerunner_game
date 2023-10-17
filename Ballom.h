#include <SFML/Graphics.hpp>
#include "Animal.h"
#include <stdlib.h>
class Move;
#ifndef BALLOM_H
#define BALLOM_H

class Ballom: public Animal {
    private:
    public:
        Ballom(); // Default constructor
        Ballom(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        void update() override; // Override of the update method from Sprite class
};

#endif
