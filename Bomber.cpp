#include "Bomber.h"
Bomber::Bomber(){}
Bomber::Bomber(int Px, int Py, int Pox, int Poy): Animal(Px, Py, Pox, Poy) {
    // this->setPx(Px);
    // this->Py = Py;
    // this->setPox(Pox);
    // this->setPoy(Poy);
}
int Bomber::bombNumber = 20;
int Bomber::swapKill = 1;
int Bomber::countKill = 0;
void Bomber::killBomber(Animal *animal){};
void Bomber::update(){}