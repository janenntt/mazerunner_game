#include <SFML/Graphics.hpp>
#include "Animal.h"
#include <string>
class mapCreation;
#include "Move.h"
using namespace std;

#ifndef ONEAL_H
#define ONEAL_H

class Oneal: public Animal{
    private:
    public:
        Oneal(); // Default constructor
        Oneal(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        void update() override; // Override of the update method from Sprite class
};
#endif
