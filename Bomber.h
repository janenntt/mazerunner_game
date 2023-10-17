#include "Animal.h"
#ifndef BOMBER_H
#define BOMBER_H

class Bomber: public Animal{
    private:
    public:
        Bomber(); // Default constructor
        Bomber(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        void update() override; // Override of the update method from Sprite class
};
#endif
