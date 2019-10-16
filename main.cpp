#include <iostream>
#include "Game.h"
#include <string>

#include "StringColor.h"




int main(){

    std::string heath = StringColor::YELLOW;

    /*for(int rep = 0; rep<200; rep++){
        std::cout << StringColor::YELLOW << " POOR YORICK ";
       // if(rep%10 == 0)
          //  std::cout << std::endl;

    }*/

	// ASCII conversion influenced from http://patorjk.com/software/taag/
    std::cout << StringColor::RED << " _____      ____       ____     ______       __      __    ____     ______      _____     ____    __   ___ " << std::endl;
    std::cout << StringColor::YELLOW << "(  __ \\\    / __ \\\     / __ \\\   (   __ \\\      ) \\\    / (   / __ \\\   (   __ \\\    (_   _)   / ___)  () ) / __)" << std::endl;
    std::cout << StringColor::GREEN << " ) )_) )  / /  \\\ \\\   / /  \\\ \\\   ) (__) )      \\\ \\\  / /   / /  \\\ \\\   ) (__) )     | |    / /      ( (_/ /" << std::endl;
    std::cout << StringColor::CYAN << "(  ___/  ( ()  () ) ( ()  () ) (    __/        \\\ \\\/ /   ( ()  () ) (    __/      | |   ( (       ()   (" << std::endl;
    std::cout << StringColor::BLUE << " ) )     ( ()  () ) ( ()  () )  ) \\\ \\\  _        \\\  /    ( ()  () )  ) \\\ \\\  _     | |   ( (       () /\\\ \\\ " << std::endl;
    std::cout << StringColor::BOLDBLUE << "( (       \\\ \\\__/ /   \\\ \\\__/ /  ( ( \\\ \\\_))        )(      \\\ \\\__/ /  ( ( \\\ \\\_))   _| |__  \\\ \\\___   ( (  \\\ \\\ " << std::endl;
    std::cout << StringColor::MAGENTA << "/__\\\       \\\____/     \\\____/    )_) \\\__/        /__\\\      \\\____/    )_) \\\__/   /_____(   \\\____)  ()_)  \\\_\\\ " << std::endl;
    std::cout << std::endl;



    Game g;
}
