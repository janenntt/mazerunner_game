#include "Bomber.h"

Bomber::Bomber(){} // Default constructor
Bomber::Bomber(int Px, int Py, int Pox, int Poy, std::string _name): Animal(Px, Py, Pox, Poy), hasReachedGoal(false), name(_name) {} // Constructor with the mob's positions
void Bomber::update(){}
void Bomber::reachedGoal(const std::string& goalName){
    this->hasReachedGoal = true;
    std::cout <<  " The player has reached the goal: " << goalName <<  std::endl;
}
bool Bomber::operator==(const std::string& goalName){
    return this->hasReachedGoal && goalName == name;
}
bool Bomber:: operator!=(const std::string& goalName){
    return !(*this == goalName);
}