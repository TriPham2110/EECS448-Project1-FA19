#include <iostream>
#include "Game.h"
#include <string>
#include "StringColor.h"

int main(){

    StringColor::reset();
    
    

	// ASCII conversion influenced from Patorjk's text to ASCII art generator http://patorjk.com/software/taag/
	std::cout << StringColor::RED <<    " _______  _______  _______  ______      __   __  _______  ______    ___   _______  ___   _ " << std::endl;
	std::cout << StringColor::YELLOW << "|       ||       ||       ||    _ |    |  | |  ||       ||    _ |  |   | |       ||   | | |" << std::endl;
	std::cout << StringColor::GREEN <<  "|    _  ||   _   ||   _   ||   | ||    |  |_|  ||   _   ||   | ||  |   | |       ||   |_| |" << std::endl;
	std::cout << StringColor::CYAN <<   "|   |_| ||  | |  ||  | |  ||   |_||_   |       ||  | |  ||   |_||_ |   | |       ||      _|" << std::endl;
	std::cout << StringColor::BLUE <<   "|    ___||  |_|  ||  |_|  ||    __  |  |_     _||  |_|  ||    __  ||   | |      _||     |_ " << std::endl;
	std::cout << StringColor::BOLDBLUE<<"|   |    |       ||       ||   |  | |    |   |  |       ||   |  | ||   | |     |_ |    _  |" << std::endl;
	std::cout << StringColor::MAGENTA <<"|___|    |_______||_______||___|  |_|    |___|  |_______||___|  |_||___| |_______||___| |_|" << std::endl;
	
	std::cout << std::endl;
    std::cout << StringColor::YELLOW;

	Game g;
    
    StringColor::reset();
    system("clear");
    system("clear");

    system("clear");



}
