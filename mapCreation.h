#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Bomber.h"
#include <vector>
#include "Ballom.h"
#include "Oneal.h"
#ifndef MAPCREATION_H
#define MAPCREATION_H

class mapCreation{
    private:
        int level;
        int height;
        int width;
        
    public:
        static std::vector<Sprite*> block; // Vector of Sprite objects
        static std::vector<std::vector<int> >id_objects; // 2D vector of id_objects
        static Bomber *player;
        static Animal *enemy1;
        static Animal *enemy2;
        static Animal *enemy3;
        static Animal *enemy4;
        static Animal *enemy5;
        static Animal *enemy6;

        mapCreation(); // constructor
        int getHeight(); // method to get the height of the map
        int getWidth(); // method to get the width of the map
        ~mapCreation(); // destructor
};
#endif
