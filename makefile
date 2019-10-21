battleship: main.o Game.o Point.o Ship.o GameBoard.o StringColor.o Score.o
	g++ -std=c++11 -g -Wall main.o Game.o GameBoard.o Point.o Ship.o StringColor.o Score.o -o battleship

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Game.o: Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp

Point.o: Point.cpp
	g++ -std=c++11 -g -Wall -c Point.cpp

GameBoard.o: GameBoard.cpp
	g++ -std=c++11 -g -Wall -c GameBoard.cpp

Ship.o: Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

StringColor.o: StringColor.cpp
	g++ -std=c++11 -g -Wall -c StringColor.cpp

Score.o: Score.cpp
	g++ -std=c++11 -g -Wall -c Score.cpp


clean:
	rm *.o battleship

run:
	./battleship
