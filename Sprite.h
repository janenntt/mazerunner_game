#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#ifndef SPRITE_H
#define SPRITE_H
class Sprite{
    private:
        // Position in the map
        int Pox;
        int Poy;
        // Position in the Spritesheet.
        int Px;
        int Py;

        static int size;
        static int scale;
        sf::Texture texture;
        sf::Image image;
        sf::Sprite *sprite;
            
    public:
        Sprite(); // Default constructor
        Sprite(int Px, int Py, int Pox, int Poy); // Px and Py are positions of the sprite
        sf::Sprite* getSprite();
        sf::Texture getTexture();

        // Methods to set the position coordinates
        void setPox(int Pox);
        void setPoy(int Poy);
        void setPx(int Px);
        void setPy(int Py);

        // Methods to get the position coordinates
        int getPx();
        int getPy();
        int getPox();
        int getPoy();

        void loadSprite();

        // Virtual method for updating the sprite
        virtual void update();
        ~Sprite(); // Destructor
};
#endif
