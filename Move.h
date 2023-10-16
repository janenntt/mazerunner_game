#include "Animal.h"
#include "Bomber.h"
#include "Blocked.h"
#ifndef MOVE_H
#define MOVE_H

class Move{
    public:
        // this case: Player first and then for the rest of the mobs.
        static void checkRun(Animal *a); // Count the steps of the mob to fulfull a grid.
        static void setDirection(std::string direction, Animal *b, int step); //Step in pixel
        static void down(Animal *a);
        static void downAndSwap(Animal *a);
        static void up(Animal *a);
        static void upAndSwap(Animal *a);
        static void left(Animal *a);
        static void leftAndSwap(Animal *a);
        static void right(Animal *a);
        static void rightAndSwap(Animal *a);

};
#endif