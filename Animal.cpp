#include "Animal.h"
int Animal::swap = 1;
std::string Animal::direction = "up";
int Animal::count = 0;
Animal::Animal(){};
Animal::Animal(int Px, int Py, int Pox, int Poy): Sprite(Px, Py, Pox, Poy){};
// Animal::Animal(int swap, std::string direction, int count){
// this->swap = swap;
// this->direction = direction;
// this->count = count;
// }


void Animal::setSwap(int swap){
this->swap = swap;
}


int Animal::getSwap(){
return this->swap;
}


void Animal::setDirection(std::string direction){
this->direction = direction;
}


std::string Animal::getDirection(){
return this->direction;
}


void Animal::setCount(int count){
this->count = count;
}


int Animal::getCount(){
return this->count;
}


void Animal::setLife(bool life){
this->life = life;
}


bool Animal::getLife(){
return this->life;
}






//TO DO: Implement kill function.
void Animal::kill(){


}




void Animal::update(){}