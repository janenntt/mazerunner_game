#include "Blocked.h"
#ifndef MOVE_H
#define MOVE_H
class Animal;
class Bomber;
class Ballom;
class Oneal;

class Move{
public:
    static void checkRun(Animal *a); // Count the steps of the mob to fulfull a grid.
    // Method to set the movement direction and step for a mob
    static void setDirection(std::string direction, Animal *b, int step); //Step in pixel

    static void down(Animal *a); // method to move the mobs downwards
    static void downAndSwap(Animal *a); // method to swap moving images
    static void up(Animal *a); // method to move the mobs upwards
    static void upAndSwap(Animal *a); // method to swap moving images
    static void left(Animal *a); // method to move the mobs to the left
    static void leftAndSwap(Animal *a); // method to swap moving images
    static void right(Animal *a); // method to move the mobs to the right
    static void rightAndSwap(Animal *a); // method to swap moving images
};
#endif
