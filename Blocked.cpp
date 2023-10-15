#include "Blocked.h"
bool Blocked::blockDown(Animal *animal){
int i = std::floor(animal->getPoy()/32);
int j = std::floor(animal->getPox()/32);
// std::cout << i << std::endl;
//std::cout << j << std::endl;
// if (game::id_objects[animal->getPoy()/32+1][animal->getPox()/32] == 0){
// return true;
// }
// else
// return false;
if (game::id_objects[i+1][j] == 0){
return true;
}
else
return false;
};
bool Blocked::blockUp(Animal *animal){
int i = std::floor(animal->getPoy()/32);
int j = std::floor(animal->getPox()/32);
if (game::id_objects[i-1][j] == 0)
{
return true;
}
return false;
};
bool Blocked::blockRight(Animal *animal){
int i = std::floor(animal->getPoy()/32);
int j = std::floor(animal->getPox()/32);
//
if (game::id_objects[i][j+1] == 0) {
return true;


}
return false;
};
bool Blocked::blockLeft(Animal *animal){
int i = std::floor(animal->getPoy()/32);
int j = std::floor(animal->getPox()/32);
if (game::id_objects[i][j-1] == 0){
return true;
}
return false;
};
// bool Blocked::blockDownBomb(Animal *animal){};
// bool Blocked::blockUpBomb(Animal *animal){};
// bool Blocked::blockRightBomb(Animal *animal){};
// bool Blocked::blockLeftBomb(Animal *animal){};
