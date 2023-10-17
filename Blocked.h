#ifndef BLOCKED_H
#define BLOCKED_H
#include "game.h"
#include "Animal.h"
#include <cmath>

class Blocked{
public:
    static bool blockDown(Animal *animal); // check if the mob can move down
    static bool blockUp(Animal *animal); // check if the mob can move up
    static bool blockRight(Animal *animal); // check if the mob can move to the right
    static bool blockLeft(Animal *animal); // check if the mob can move the the left
};
#endif
