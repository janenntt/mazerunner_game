#include "game.h"

std::vector<Sprite*> game::block;
// std::vector<Animal> game::enemy;
std::vector<std::vector<int> > game::id_objects(15, std::vector<int>(25));
std::vector<std::vector<int> > game::list_kills(15, std::vector<int>(25));
std::vector<Animal*> game::enemy;
//Bomber game::player;
Bomber* game::player = new Bomber(1, 0, 1, 1);

game::game(){}
void game::startGame(){
    window.create(sf::VideoMode(800, 480), "Bomberman");
    timeEachLevel = 120;

    font.loadFromFile("Arial.ttf");
    level.setFont(font);
    bomb.setFont(font);
    time.setFont(font);
    Start.setFont(font);

    level.setString("Level: 1");
    bomb.setString("Bombs: 20");
    time.setString("Time: 120");
    Start.setString("Press Space to start the game");

    level.setCharacterSize(14);
    bomb.setCharacterSize(14);
    time.setCharacterSize(14);
    Start.setCharacterSize(20);

    level.setFillColor(sf::Color::White);
    bomb.setFillColor(sf::Color::White);
    time.setFillColor(sf::Color::White);
    Start.setFillColor(sf::Color::White);

    level.setStyle(sf::Text::Bold);
    bomb.setStyle(sf::Text::Bold);
    time.setStyle(sf::Text::Bold);
    Start.setStyle(sf::Text::Bold);
    

    level.setPosition(416, 20);
    bomb.setPosition(512, 20);
    time.setPosition(608, 20);
    Start.setPosition(200, 200);
    
    sf::Texture pauseGameTexture;
    sf::Texture playGameTexture;
    sf::Texture newGameTexture;

    pauseGameTexture.loadFromFile("pauseButton.png");
    playGameTexture.loadFromFile("resumeButton.png");
    newGameTexture.loadFromFile("startButton.png");
    

    sf::Sprite pauseGame;
    sf::Sprite playGame;
    sf::Sprite newGame;

    pauseGame.setTexture(pauseGameTexture);
    playGame.setTexture(playGameTexture);
    newGame.setTexture(newGameTexture);

    pauseGame.setScale(0.5, 0.5);
    playGame.setScale(0.5, 0.5);
    newGame.setScale(0.5, 0.5);

    newGame.setPosition(20, 20);
    playGame.setPosition(20, 20);
    pauseGame.setPosition(20, 20);

    drawStart = false;
    getTimeLimit = false;
}

void game::run(){
    float timeLimit;
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time now = clock.getElapsedTime();
        if (drawStart == false && getTimeLimit == false){
            timeLimit = now.asSeconds() + 1.0;
            std::cout << timeLimit << std::endl;
            this->getTimeLimit = true;
        }
        if (now.asSeconds() > timeLimit && drawStart == true){
            timeEachLevel --;
            std::stringstream a;
            a << timeEachLevel;
            std::string b = a.str();
            std::string c = "Time ";
            std::string d  = c+b;
            time.setString(d);
            timeLimit ++;
        }
        
        processEvents();
        draw();
    }
}

void game::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space){
                drawStart = true;
            }
        }
    }
}

void game::draw(){
    window.clear();
    window.draw(bomb);
    window.draw(level);
    window.draw(time);
    if (!drawStart) {
        window.draw(Start);
    }
    window.display();
}
