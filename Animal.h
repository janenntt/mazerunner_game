#include <iostream>
#include <string>
#include "Sprite.h"
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal: public Sprite{
    private:
        static int swap;
        static std::string direction;
        static int count;
        bool life;

    public:
        Animal(); // Default constructor
        Animal(int Px, int Py, int Pox, int Poy); // Constructor with position parameters
        //Animal(int swap, std::string direction, int count);
        void setSwap(int swap);
        int getSwap();
        // Setter and getter for the movement direction
        void setDirection(std::string direction);
        std::string getDirection();
        void setCount(int count);
        int getCount();
        // Setter and getter for the life status
        void setLife(bool life);
        bool getLife();
        void update() override; // Override of the update method from Sprite class
};

#endif
