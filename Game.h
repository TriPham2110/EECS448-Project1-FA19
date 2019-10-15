#ifndef GAME_H
#define GAME_H

#include <iostream>
#inlcude "GameBoard.h"
#include "Ship.h"

class Game {
    public: 
    
    Game();
    
    private:
    
    placeShips(GameBoard player, int numShips);
    playGame(GameBoard Player1, GameBoard Player2);
    getColumn();
    getRow();
    
    
    
    
};


#endif