#include "game.h"
// constructor


game::game(){
    window.create(sf::VideoMode(800, 480), "Bomberman");
    font.loadFromFile("Arial.ttf");
    level.setFont(font);
    readyText.setFont(font);
// win.setFont(font);
// lose.setFont(font);


level.setString("Level: 1");
readyText.setString("Press Y if you are ready to play");



level.setCharacterSize(14);
readyText.setCharacterSize(20);


level.setFillColor(sf::Color::Black);
readyText.setFillColor(sf::Color::Black);


level.setStyle(sf::Text::Bold);
readyText.setStyle(sf::Text::Bold);


level.setPosition(416, 10);
readyText.setPosition(200, 200);


startMenuTexture.loadFromFile("start_menu.png");
winTexture.loadFromFile("win.png");
loseTexture.loadFromFile("lose.png");


startMenu.setTexture(startMenuTexture);
win.setTexture(winTexture);
lose.setTexture(loseTexture);
startMenu.setPosition(0, 0);
win.setPosition(0, 0);
lose.setPosition(0, 0);


drawStart = false;
winGame = false;
loseGame = false;
ready = false;
level1 = new mapCreation;


}


void game::run(){
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    window.draw(startMenu);
    while (window.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            sf::Event event;
            processEvents();
            if (level1->player->getPox() == 24*32 && level1->player->getPoy() == 6*32){
                winGame = true;
            }
            if ((level1->player->getPox() == level1->enemy1->getPox() && level1->player->getPoy() == level1->enemy1->getPoy()) ||
            (level1->player->getPox() == level1->enemy2->getPox() && level1->player->getPoy() == level1->enemy2->getPoy()) ||
            (level1->player->getPox() == level1->enemy3->getPox() && level1->player->getPoy() == level1->enemy3->getPoy()) ||
            (level1->player->getPox() == level1->enemy4->getPox() && level1->player->getPoy() == level1->enemy4->getPoy()) ||
            (level1->player->getPox() == level1->enemy4->getPox() && level1->player->getPoy() == level1->enemy4->getPoy()) ||
            (level1->player->getPox() == level1->enemy5->getPox() && level1->player->getPoy() == level1->enemy5->getPoy()) ||
            (level1->player->getPox() == level1->enemy6->getPox() && level1->player->getPoy() == level1->enemy6->getPoy()) )
            {
                loseGame = true;
            }
        draw();
        }
    }
}






void game::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space){
                drawStart = true;
            }
            if (event.key.code == sf::Keyboard::Y){
                ready = true;
            }
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up ) {
                if(ready){
                    Move::up(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                if(ready){
                    Move::down(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                if(ready){
                    Move::left(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                if(ready){
                    Move::right(level1->player);
                }
            }
        }
    }
    if (ready && !loseGame && drawStart){
        level1->enemy1->update();
        level1->enemy2->update();
        level1->enemy3->update();
        level1->enemy4->update();
        level1->enemy5->update();
        level1->enemy6->update();
    }
}


void game::draw(){
    window.clear();
    if(!drawStart){
        window.draw(startMenu);
    }
if (!ready && drawStart){
    for (Sprite *var: level1->block) {
        window.draw( *var -> getSprite());  
    }
    window.draw(level);
    window.draw(readyText);
}
if (ready && drawStart){
    for (Sprite *var: level1->block) {
        window.draw( *var -> getSprite());
    }
    window.draw(level);
}
if (ready && winGame){
    window.draw(win);
    //std::cout << winGame << std::endl;
}
if (ready && loseGame){
    window.draw(lose);
    //std::cout << loseGame << std::endl;
}
window.display();
}


game::~game(){
    delete level1;
}


