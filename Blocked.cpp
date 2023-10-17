#include "Blocked.h"

bool Blocked::blockDown(Animal *animal){
    int i = animal->getPoy()/32;
    int j = animal->getPox()/32;
    if (mapCreation::id_objects[i+1][j] == 0){
        return true;
    }
    return false;
}

bool Blocked::blockUp(Animal *animal){
    int i = animal->getPoy()/32;
    int j = animal->getPox()/32;
    if (mapCreation::id_objects[i-1][j] == 0){
        return true;
    }
    return false;
}


bool Blocked::blockRight(Animal *animal){
    int i = animal->getPoy()/32;
    int j = animal->getPox()/32;
    if (mapCreation::id_objects[i][j+1] == 0) {
        return true;
    }
    return false;
}


bool Blocked::blockLeft(Animal *animal){
    int i = animal->getPoy()/32;
    int j = animal->getPox()/32;
    if (mapCreation::id_objects[i][j-1] == 0){
        return true;
    }
    return false;
};
