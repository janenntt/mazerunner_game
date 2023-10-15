#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "game.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#ifndef MAPCREATION_H
#define MAPCREATION_H
class mapCreation{
private:
int level;
int height;
int width;
public:
mapCreation();
void createMap();
int getHeight();
int getWidth();
};
#endif
