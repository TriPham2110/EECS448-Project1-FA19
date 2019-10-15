battleship: main.o
	g++ -std=c++11 -g -Wall main.o game.o -o battleship

main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

Game.o: Game.cpp 
	g++ -std=c++11 -g -Wall -c Game.cpp
 
clean: 
	rm *.o battleship

run:
	./battleship
    