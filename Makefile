# Default
all: main

# main
main: main.o Animal.o Ballom.o Blocked.o Bomber.o game.o mapCreation.o Move.o Oneal.o Sprite.o
	g++ -o a main.o Animal.o Ballom.o Blocked.o Bomber.o game.o mapCreation.o Move.o Oneal.o Sprite.o -std=c++11  -I/opt/homebrew/Cellar/sfml/2.6.0/include -o a -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Classes for main
# Sprite
Sprite.o: Sprite.cpp Sprite.h
	g++ -c Sprite.cpp -std=c++11 -o Sprite.o

# Animal
Animal.o: Sprite.h Animal.cpp Animal.h
	g++ -c Animal.cpp -std=c++11 -o Animal.o

# Bomber
Bomber.o: Animal.h Bomber.cpp Bomber.h
	g++ -c Bomber.cpp -std=c++11 -o Bomber.o

# Ballom
Ballom.o: Animal.h Ballom.cpp Ballom.h
	g++ -c Ballom.cpp -std=c++11 -o Ballom.o

# Oneal
Oneal.o: Animal.h Oneal.cpp Oneal.h
	g++ -c Oneal.cpp -std=c++11 -o Oneal.o

# Blocked
Blocked.o: Blocked.cpp Blocked.h
	g++ -c Blocked.cpp -o Blocked.o

# Game
game.o: game.cpp game.h
	g++ -c game.cpp -o game.o

# MapCreation
mapCreation.o: mapCreation.cpp mapCreation.h
	g++ -c mapCreation.cpp -o mapCreation.o

# Move
Move.o: Move.cpp Move.h
	g++ -c Move.cpp -o Move.o

# Run
run: all 
	./a




# Clean
clean:
	rm -f *.o


