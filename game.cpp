#include "game.h"
// constructor
game::game(){
    window.create(sf::VideoMode(800, 480), "Bomberman");
    try {
        // Attempt to load the "Arial.ttf" font
        if (!font.loadFromFile("Arial.ttf")) {
            // If loading the font fails, explicitly throw a runtime_error exception
            throw std::runtime_error("Font file 'Arial.ttf' not found or couldn't be loaded.");
        }
        // If font is successfully loaded, set the font for text objects
        level.setFont(font);
        Start.setFont(font);
        win.setFont(font);
        lose.setFont(font);
    } catch (const std::exception& e) {
        // Handle the font loading exception.
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
    
    level.setString("Level: 1"); // set the text displayed for level
    Start.setString("Press Space to start the game"); // set start game message
    win.setString("You win!"); // set winning message
    lose.setString("You lose!"); // set losing message

    // set the text's character size
    level.setCharacterSize(14);
    Start.setCharacterSize(20);
    win.setCharacterSize(20);
    lose.setCharacterSize(20);

    // set the text color
    level.setFillColor(sf::Color::Black);
    Start.setFillColor(sf::Color::Black);
    win.setFillColor(sf::Color::Black);
    lose.setFillColor(sf::Color::Black);

    // set the text style
    level.setStyle(sf::Text::Bold);
    Start.setStyle(sf::Text::Bold);
    win.setStyle(sf::Text::Bold);
    lose.setStyle(sf::Text::Bold);

    // set the positions for the messages
    level.setPosition(416, 10);
    Start.setPosition(200, 200);
    win.setPosition(300, 200);
    lose.setPosition(300, 200);

    // initialise the game
    drawStart = false;
    winGame = false;
    loseGame = false;
    level1 = new mapCreation;
}
// run the game loop
void game::run(){
    sf::Time timePerFrame = sf::seconds(1.f / 60.f); // Define the time per frame
    sf::Clock clock; // measure time for controlling the game loop
    sf::Time timeSinceLastUpdate = sf::Time::Zero; // Initialize the time since the last game update
    window.draw(*level1->player->getSprite()); // render the player character's sprite
    window.draw(level); // render 'level' text
    window.draw(Start); // render 'Start' text

    while (window.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            sf::Event event;
            processEvents();
            if (level1->player->getPox() == 24*32 && level1->player->getPoy() == 6*32){
                winGame = true;
            }
            if (level1->player->getPox() == level1->enemy1->getPox() && level1->player->getPoy() == level1->enemy1->getPoy() ||
                level1->player->getPox() == level1->enemy2->getPox() && level1->player->getPoy() == level1->enemy2->getPoy() ||
                level1->player->getPox() == level1->enemy3->getPox() && level1->player->getPoy() == level1->enemy3->getPoy() ||
                level1->player->getPox() == level1->enemy4->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy4->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy5->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy6->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy7->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy8->getPox() && level1->player->getPoy() == level1->enemy4->getPoy() ||
                level1->player->getPox() == level1->enemy9->getPox() && level1->player->getPoy() == level1->enemy4->getPoy()){
                    loseGame = true;
            }
            draw();
        }
    }
}
// Process user input events
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
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up ) {
                if(drawStart){
                    Move::up(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                if(drawStart){
                    Move::down(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                if(drawStart){
                    Move::left(level1->player);
                }
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                if(drawStart){
                    Move::right(level1->player);
                }
            }
        }
    }

    if (drawStart && !loseGame){
        level1->enemy1->update();
        level1->enemy2->update();
        level1->enemy3->update();
        level1->enemy4->update();
        level1->enemy5->update();
        level1->enemy6->update();
        level1->enemy7->update();
        level1->enemy8->update();
        level1->enemy9->update();
    }
}

// Draw game elements
void game::draw(){
    window.clear();
    for (Sprite *var: level1->block) {
        window.draw( *var -> getSprite());
    }
    window.draw(level);
    if(drawStart == false){
        window.draw(Start);
    }
    if (drawStart && winGame){
        window.draw(win);
    }
    if (drawStart && loseGame){
        window.draw(lose);
    }
    window.display();
}
// Destructor
game::~game(){
    delete level1;
}
