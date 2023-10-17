#include "Animal.h"
#ifndef BOMBER_H
#define BOMBER_H

class Bomber: public Animal{
    private:
    public:
        bool hasReachedGoal;
        std::string name;
        Bomber(); // Default constructor
        Bomber(int Px, int Py, int Pox, int Poy, std::string _name); // Constructor with position parameters
        void reachedGoal(const std::string& goalName);
        bool operator==(const std::string& goalName);
        bool operator!=(const std::string& goalName);

        void update() override; // Override of the update method from Sprite class
};
#endif
