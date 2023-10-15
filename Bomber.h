#include "Animal.h"
#ifndef BOMBER_H
#define BOMBER_H


class Bomber: public Animal{
private:
static int bombNumber;
static int swapKill;
static int countKill;
public:
//Ballom(int swap, std::string direction, int count);
Bomber();
Bomber(int Px, int Py, int Pox, int Poy);
void killBomber(Animal *animal);
void update() override;


};


#endif
