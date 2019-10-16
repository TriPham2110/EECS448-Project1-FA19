battleship: main.o Game.o Point.o Ship.o GameBoard.o AIOpponent.o StringColor.o
	g++ -std=c++11 -g -Wall main.o Game.o GameBoard.o Point.o Ship.o AIOpponent.o StringColor.o -o battleship

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Game.o: Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp

Point.o: Point.cpp
	g++ -std=c++11 -g -Wall -c Point.cpp

AIOpponent.o: AIOpponent.cpp
	g++ -std=c++11 -g -Wall -c AIOpponent.cpp

GameBoard.o: GameBoard.cpp
	g++ -std=c++11 -g -Wall -c GameBoard.cpp

Ship.o: Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

StringColor.o: StringColor.cpp
	g++ -std=c++11 -g -Wall -c StringColor.cpp

clean:
	rm *.o battleship

run:
	./battleship
