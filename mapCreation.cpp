#include "mapCreation.h"

std::vector<Sprite*> mapCreation::block;
Bomber* mapCreation::player;
Animal* mapCreation::enemy1;
Animal* mapCreation::enemy2;
Animal* mapCreation::enemy3;
Animal* mapCreation::enemy4;
Animal* mapCreation::enemy5;
Animal* mapCreation::enemy6;
std::vector<std::vector<int> > mapCreation::id_objects(15, std::vector<int>(25));

mapCreation::mapCreation() {
  try {
    // Open Level1.txt file
    std::ifstream file("Level1.txt");
    // Check if the file is opened successfully
    if (!file.is_open()){
      throw std::runtime_error("Failed to open Level1.txt");
    }
    std::string line;
    std::getline(file, line);
    std::string token;
    std::istringstream iss(line);

    // Parse the file content to initialize level, height, and width
    iss >> token;
    level = std::stoi(token);
    iss >> token;
    height = std::stoi(token);
    iss >> token;
    width = std::stoi(token);

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
            block.push_back(portal);
            break;
          }
          case 2: {
            Sprite * wall = new Sprite(5, 0, j, i);
            block.push_back(wall);
            break;
          }
          case 3: {
            Sprite * brick = new Sprite(7, 0, j, i);
            block.push_back(brick);
            break;
          }
          case 6: {
            Sprite * brick = new Sprite(7, 0, j, i);
            block.push_back(brick);
            break;
          }
          case 7: {
            Sprite * brick = new Sprite(7, 0, j, i);
            block.push_back(brick);
            break;
          }
          default: {
            Sprite * grass = new Sprite(6, 0, j, i);
            block.push_back(grass);
            break;
          }
        }
        id_objects[i][j] = b;
      }
    }
  } catch (const std::exception& e) {
    // Handle exceptions with an error message
    std::cerr << "An exception occurred: " << e.what() << std::endl;
  }

    // Create Bomber and enemy objects
    player = new Bomber(1, 0, 1, 1, "Level1");
    enemy1 = new Ballom(9, 0, 3, 3);
    enemy2 = new Oneal(11, 0, 5, 5);
    enemy3 = new Ballom(9, 0, 7, 7);
    enemy4 = new Oneal(11, 0, 9, 9);
    enemy5 = new Ballom(11, 0, 11, 9);
    enemy6 = new Ballom(11, 0, 15, 9);

    // Add objects to the block vector
    block.push_back(player);
    block.push_back(enemy1);
    block.push_back(enemy2);
    block.push_back(enemy3);
    block.push_back(enemy4);
    block.push_back(enemy5);
    block.push_back(enemy6);

}


int mapCreation::getHeight() {
  return this -> height;
}


int mapCreation::getWidth() {
  return this -> width;
}


mapCreation::~mapCreation(){
  // Delete dynamically allocated objects
  delete this->player;
  delete this->enemy1;
  delete this->enemy2;
  delete this->enemy3;
  delete this->enemy4;
  delete this->enemy5;
  delete this->enemy6;
}
