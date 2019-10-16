#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameBoard.h"
#include "AIOpponent.h"
#include <cstdlib>
#include <time.h>


class Game {
    public:

    Game();
    ~Game();

    private:

    GameBoard Player1;
    GameBoard Player2;
    GameBoard AI;

    void placeShips(GameBoard& player, int numShips);
    void playGame(GameBoard& Player1, GameBoard& Player2);
    void placeShipsAI(GameBoard& AI, int numShips);
    void playAI(GameBoard& Player1, GameBoard& AI, int difficulty);
    int getColumn();
    int getRow();




};


#endif
