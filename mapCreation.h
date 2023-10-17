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
        static Ballom *enemy1;
        static Oneal *enemy2;
        static Ballom *enemy3;
        static Oneal *enemy4;
        static Ballom *enemy5;
        static Ballom *enemy6;

        mapCreation(); // constructor
        int getHeight(); // method to get the height of the map
        int getWidth(); // method to get the width of the map
        ~mapCreation(); // destructor
};
#endif
