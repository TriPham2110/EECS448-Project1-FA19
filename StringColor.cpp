#include "StringColor.h"
#include <iostream>

const std::string StringColor::RESET       = "\033[0m";
const std::string StringColor::BLACK       = "\033[30m";
const std::string StringColor::RED         = "\033[31m";
const std::string StringColor::GREEN       = "\033[32m";
const std::string StringColor::YELLOW      = "\033[33m";
const std::string StringColor::BLUE        = "\033[34m";
const std::string StringColor::MAGENTA     = "\033[35m";
const std::string StringColor::CYAN        = "\033[36m";
const std::string StringColor::WHITE       = "\033[37m";
const std::string StringColor::BOLDBLACK   = "\033[1m\033[30m";
const std::string StringColor::BOLDRED     = "\033[1m\033[31m";
const std::string StringColor::BOLDGREEN   = "\033[1m\033[32m";
const std::string StringColor::BOLDYELLOW  = "\033[1m\033[33m";
const std::string StringColor::BOLDBLUE    = "\033[1m\033[34m";
const std::string StringColor::BOLDMAGENTA = "\033[1m\033[35m";
const std::string StringColor::BOLDCYAN    = "\033[1m\033[36m";
const std::string StringColor::BOLDWHITE   = "\033[1m\033[37m";

std::string StringColor::WATER      = "░▒░";
std::string StringColor::SHIP       = "═╩═";
std::string StringColor::BORDER     = "\033[1m\033[33m";
std::string StringColor::TEXT       = "\033[1m\033[33m";
std::string StringColor::HIT        = " # ";
std::string StringColor::MISS       = " Ω ";
std::string StringColor::SUNK       = " ≠ ";
std::string StringColor::BACKGROUND = "\033[44m";


void StringColor::changeTheme(std::string themeName){
    if(themeName == "default"){
        BACKGROUND = "\033[44m";
        BORDER = "\033[1m\033[33m";
        TEXT = "\033[1m\033[33m\033[40m";
        WATER = BACKGROUND + BOLDWHITE + "░▒░";
        SHIP = "\033[40m" + GREEN + "═╩═";
        HIT = RED +" # ";
        MISS = CYAN + " Ω ";
        SUNK = MAGENTA + " ≠ ";
    }

    else if(themeName == "meet"){
        
        BACKGROUND = "\033[45m";
        BORDER = "\033[1m\033[33m";
        TEXT = "\033[1m\033[33m";
        WATER = "\033[45m" + BOLDYELLOW + "░▒░";
        SHIP = "\033[40m" + YELLOW + "═╩═";
        HIT = BOLDYELLOW  + " # ";
        MISS = BOLDYELLOW + " Ω ";
        SUNK = BOLDYELLOW + " ≠ ";
    }
    else if(themeName == "tri"){
    }
    else if(themeName == "apurva"){
        BACKGROUND = "\033[1m\033[32m";
        BORDER = "\033[1m\033[31m";
        TEXT = "\033[1m\033[36m";
        WATER = "\033[1m\033[32m" + BOLDBLACK + "░▒░";
        SHIP = "\033[40m" + RED + "═╩═";
        HIT = WHITE + " # ";
        MISS = BLUE + " Ω ";
        SUNK = CYAN + " ≠ ";
    }
    else if(themeName == "jace"){
    }
    else if(themeName == "max"){
    }

    else if(themeName == "lightMode"){
        BACKGROUND = "\033[47m";
        BORDER = "\033[1m\033[30m";
        TEXT = "\033[1m\033[30m";
        WATER = "\033[47m" + BOLDBLACK + "░▒░";
        SHIP = "\033[47m" + BLACK + "═╩═";
        HIT = BLACK + " # ";
        MISS = BLACK + " Ω ";
        SUNK = BLACK + " ≠ ";

    }
    else if(themeName == "darkMode"){
        BACKGROUND = "\033[40m";
        BORDER = "\033[1m\033[37m";
        TEXT = "\033[1m\033[37m";
        WATER = BACKGROUND + BOLDWHITE + "░▒░";
        SHIP = "\033[40m" + WHITE + "═╩═";
        HIT = WHITE + " # ";
        MISS = WHITE + " Ω ";
        SUNK = WHITE + " ≠ ";
    }
    
    else if (themeName == "chaos"){
        BACKGROUND = "\033[" + std::to_string(RandInt(40, 7)) + "m";
        BORDER = "\033[1m\033[3"+std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7)) + "m";
        TEXT = "\033[1m\033[3"+std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7)) + "m";
        WATER = BACKGROUND + "\033[1m\033[3"+ std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7)) + "m" + (char)RandInt(33,22) + (char)RandInt(33,22) + (char)RandInt(33,22);
        SHIP = "\033[1m\033[3"+ std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7)) + "m" + (char)RandInt(33,22) + (char)RandInt(33,22) + (char)RandInt(33,22);
        HIT = "\033[1m\033[3"+std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7))+"m"+ (char)RandInt(33,22) + (char)RandInt(33,22) + (char)RandInt(33,22);
        MISS = "\033[1m\033[3"+std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7))+"m"+ (char)RandInt(33,22) + (char)RandInt(33,22) + (char)RandInt(33,22);
        SUNK = "\033[1m\033[3"+std::to_string(RandInt(40, 7))+"m\033[" + std::to_string(RandInt(30, 7))+"m" + (char)RandInt(33,22) + (char)RandInt(33,22) + (char)RandInt(33,22);
    }

}

void StringColor::reset(){
    std::cout << RESET << std::endl;
}

int StringColor::RandInt(int a, int b){
    return (rand()%b+a);
}
