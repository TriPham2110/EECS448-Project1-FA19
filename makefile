battleship: main.o Game.o Point.o Ship.o 
	g++ -std=c++11 -g -Wall main.o Game.o Point.o Ship.o -o battleship

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Game.o: Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp

Point.o: Point.cpp
	g++ -std=c++11 -g -Wall -c Point.cpp
    
Ship.o: Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

clean:
	rm *.o battleship

run:
	./battleship
