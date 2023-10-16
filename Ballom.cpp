#include "Ballom.h"

int Ballom::swap_kill = 1;
int Ballom::count_kill = 0;
//Ballom::Ballom(int swap, std::string direction, int count){
// TO DO: Implement the kill Ballom, kill and update functions.

Ballom::Ballom(int Px, int Py, int Pox, int Poy): Animal(Px*16, Py*16, Pox*32, Poy*32){
// this->setPx(Px);
// this->setPy(Py);
// this->setPox(Pox);
// this->setPoy(Poy) ;


};
void Ballom::killBallom(Animal *animal){
if (count_kill%16 ==0){
if(swap_kill == 1 ){
animal->setPx(15);
animal->setPy(0);
swap_kill = 2 ;
}
else if(swap_kill == 2 ){
animal->setPx(15);
animal->setPy(0);
swap_kill = 3 ;
}


else if(swap_kill == 3 ){
animal->setPx(15);
animal->setPy(0);
swap_kill = 4;
}


else{
animal->setLife(false);
//TO DO: create enemy in class level 1.
swap_kill = 1;
}
}
}
void Ballom::kill(){};
void Ballom::update(){};