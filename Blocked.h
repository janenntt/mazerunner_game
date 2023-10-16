#ifndef BLOCKED_H
#define BLOCKED_H
#include "game.h"
#include "Animal.h"
#include <cmath>

class Blocked{
    public:
        static bool blockDown(Animal *animal);
        static bool blockUp(Animal *animal);
        static bool blockRight(Animal *animal);
        static bool blockLeft(Animal *animal);
        // static bool blockDownBomb(Animal *animal);
        // static bool blockUpBomb(Animal *animal);
        // static bool blockRightBomb(Animal *animal);
        // static bool blockLeftBomb(Animal *animal);
};
#endif
