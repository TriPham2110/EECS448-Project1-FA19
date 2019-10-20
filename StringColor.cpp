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

std::string StringColor::WATER      = " ░";
std::string StringColor::SHIP       = " ±";
std::string StringColor::BORDER     = "\033[1m\033[33m";
std::string StringColor::TEXT       = "\033[1m\033[33m";
std::string StringColor::HIT        = " #";
std::string StringColor::MISS       = " Ω";
std::string StringColor::SUNK       = " ≠";
std::string StringColor::BACKGROUND = "\033[44m";


void StringColor::changeTheme(std::string themeName){
    if(themeName == "default"){
        BACKGROUND = "\033[44m";
        BORDER = "\033[1m\033[33m";
        TEXT = "\033[1m\033[33m\033[40m";
        WATER = BACKGROUND + BOLDWHITE + WATER;
        SHIP = "\033[40m" + GREEN + SHIP;
        HIT = RED + HIT;
        MISS = CYAN + MISS;
        SUNK = MAGENTA + SUNK;
    }
    
    else if(themeName == "meet"){
        WATER = BOLDBLACK + WATER;
        SHIP = GREEN + SHIP;
        HIT = RED + HIT;
        MISS = CYAN + MISS;
        SUNK = MAGENTA + SUNK;
    }
    else if(themeName == "tri"){
    }
    else if(themeName == "apurva"){
    }
    else if(themeName == "jace"){
    }
    else if(themeName == "max"){
    }
     
}

void StringColor::reset(){
    std::cout << RESET << std::endl;
}