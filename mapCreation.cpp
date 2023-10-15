#include "mapCreation.h"

mapCreation::mapCreation() {}

void mapCreation::createMap() {
  std::ifstream file("Level1.txt");
  std::string line;
  std::getline(file, line);
  //std::cout << line << std::endl;
  std::string token;
  std::istringstream iss(line);
  iss >> token;
  // Process each token (e.g., print it)
  level = std::stoi(token);
  iss >> token;
  height = std::stoi(token);
  iss >> token;
  width = std::stoi(token);
  // std::cout << level << std::endl;
  // std::cout << height << std::endl;
  // std::cout << width << std::endl;
  int i = 0;
  int j = 0;
  for (int i = 0; i < height; i++) {
    std::getline(file, line);
    std::istringstream stream(line);
    for (int j = 0; j < width; j++) {
      std::string a;
      stream >> a;
      int b = std::stoi(a);
      switch (b) {
      case 1: {
        Sprite * portal = new Sprite(4, 0, j, i);
        //portal.loadSprite();
        // Sprite portal(0, 0);
        // portal.setPox(32*j);
        // portal.setPoy(32 * i);
        game::block.push_back(portal);
        break;
      }
      case 2: {
        Sprite * wall = new Sprite(5, 0, j, i);
        //wall.loadSprite();
        // Sprite wall(5, 0) ;
        // wall.setPox(32*j);
        // wall.setPoy(32 * i);
        game::block.push_back(wall);
        break;
      }
      case 3: {
        Sprite * brick = new Sprite(7, 0, j, i);
        // Sprite brick(0, 4);
        // brick.setPox(32*j);
        // brick.setPoy(32 * i);
        //brick.loadSprite();
        game::block.push_back(brick);
        break;
      }
      case 6: {
        Sprite * brick = new Sprite(7, 0, j, i);
        // Sprite brick(4, 0);
        // brick.setPox(32*j);
        // brick.setPoy(32 * i);
        //brick.loadSprite();
        game::block.push_back(brick);
        break;
      }
      case 7: {
        Sprite * brick = new Sprite(7, 0, j, i);
        // Sprite brick(4, 0);
        // brick.setPox(32*j);
        // brick.setPoy(32 * i);
        //brick.loadSprite();
        game::block.push_back(brick);
        break;
      }
      default: {
        Sprite * grass = new Sprite(6, 0, j, i);
        // Sprite grass(6, 0);
        // grass.setPox(32*j);
        // grass.setPoy(32 * i);
        //grass.loadSprite();
        game::block.push_back(grass);
        break;
      }
      }
      game::id_objects[i][j] = b;
    }
  }
  // for (int i = 0; i < 15; i++){
  // for (int j = 0; j < 25; j++){
  // std::cout << game::id_objects[i][j] << " ";
  // }
  // std::cout << std::endl;
  // }
}

int mapCreation::getHeight() {
  return this -> height;
}

int mapCreation::getWidth() {
  return this -> width;
}