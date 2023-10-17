#include "Ballom.h"
#include "Move.h"

Ballom::Ballom(int Px, int Py, int Pox, int Poy): Animal(Px, Py, Pox, Poy) {};
void Ballom::update() {
    // Check if the Ballom's position is aligned with the grid
    if (this->getPoy() % 16 == 0 && this->getPox() % 16 == 0) {
        // Generate a random number between 0 and 3 to determine Ballom's next move
        int random = rand()%4;
        switch (random) {
            // move down if the random number is 0
            case 0:
                Move::down(this);
                break;
            // move up if the random number is 1
            case 1:
                Move::up(this);
                break;
            // move to the left  if the random number is 2
            case 2:
                Move::left(this);
                break;
            // move to the right if the random number is 3
            case 3:
                Move::right(this);
                break;
        }
    }
}
