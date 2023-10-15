#include <SFML/Graphics.hpp>
#include "Animal.h"

#ifndef BALLOM_H
#define BALLOM_H
class Ballom: public Animal{
private:
static int swap_kill;
static int count_kill;
public:
//Ballom(int swap, std::string direction, int count);
Ballom(int Px, int Py, int Pox, int Poy);
void killBallom(Animal *animal);
void kill();
void update() override;


};


#endif
