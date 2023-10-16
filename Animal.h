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
        Animal();
        Animal(int Px, int Py, int Pox, int Poy);
        //Animal(int swap, std::string direction, int count);
        void setSwap(int swap);
        int getSwap();
        void setDirection(std::string direction);
        std::string getDirection();
        void setCount(int count);
        int getCount();
        void setLife(bool life);
        bool getLife();
        void kill();
        void update() override;
};


#endif
