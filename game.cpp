#include "game.h"

// Default constructor
game::game(){
    // Create game window
    window.create(sf::VideoMode(800, 480), "Bomberman");

    // Handle exceptions when loading font file
    try {
        // Check if the font file is loaded successfully
        if (!font.loadFromFile("Arial.ttf")) {
            throw std::runtime_error("Failed to load font file: Arial.ttf");
        }
        // Set the fonts for level and readyText
        level.setFont(font);
        readyText.setFont(font);

    } catch (const std::exception& e) {
        // Handle exceptions with an error message
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    // Display text
    level.setString("Level: 1");
    readyText.setString("Press Y if you are ready to play");

    // Set character size for level and readyText
    level.setCharacterSize(14);
    readyText.setCharacterSize(20);

    // Set text color
    level.setFillColor(sf::Color::Black);
    readyText.setFillColor(sf::Color::Black);

    // Set text style
    level.setStyle(sf::Text::Bold);
    readyText.setStyle(sf::Text::Bold);

    // Set text position
    level.setPosition(416, 10);
    readyText.setPosition(200, 200);

    // Handle exceptions when loading files for starting game, win and lose
    try {
        // Check if the files are loaded successfully
        if (!startMenuTexture.loadFromFile("start_menu.png")) {
            throw std::runtime_error("Failed to load start_menu.png");
        }
        if (!winTexture.loadFromFile("win.png")) {
            throw std::runtime_error("Failed to load win.png");
        }
        if (!loseTexture.loadFromFile("lose.png")) {
            throw std::runtime_error("Failed to load lose.png");
        }

    } catch (const std::exception& e) {
        // Handle exceptions with an error message
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    // Set texture for startMenu, win, and lose
    startMenu.setTexture(startMenuTexture);
    win.setTexture(winTexture);
    lose.setTexture(loseTexture);

    // Set the positions for startMenu, win, and lose
    startMenu.setPosition(0, 0);
    win.setPosition(0, 0);
    lose.setPosition(0, 0);

    // Initialise the game
    drawStart = false;
    winGame = false;
    loseGame = false;
    ready = false;
    out = false;
    level1 = new mapCreation;
}

// Method to run the game loop
void game::run(){
    std::ofstream outputFile("output.txt"); // Open a file for writing

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        exit(1);
    }
    std::streambuf* consoleStreamBuf = std::cout.rdbuf(); // Save the original streambuf
    std::cout.rdbuf(outputFile.rdbuf()); // Redirect cout to the file

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
   
    // Print to the redirected cout
    std::cout << "This will be saved in output.txt." << std::endl;

    // Restore the original streambuf
    std::cout.rdbuf(consoleStreamBuf);

    outputFile.close(); // Close the output file

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
    if (level1->enemy1->getPoy() == 0 && level1->enemy1->getPox() == 1){
        out = true;
    }
    if (ready && !loseGame && drawStart){
        if (!out){
            level1->enemy1->update();
        }
        level1->enemy2->update();
        level1->enemy3->update();
        level1->enemy4->update();
        level1->enemy5->update();
        level1->enemy6->update();
    }
     if (level1->player->getPox() == 24*32 && level1->player->getPoy() == 6*32){
        level1->player->reachedGoal("Level 1");
        winGame = true;
    }
    if (*level1->player == "Level 1") {
        std::cout << "Congratulations! player has reached Level 1." << std::endl;
    } 

    std::cout << "Position of main player" << std::endl;
    std::cout << level1->player->getPox() << std::endl;
    std::cout << level1->player->getPoy() << std::endl;
    std::cout<< std::endl;
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



// Destructor
game::~game(){
    delete level1;
}


