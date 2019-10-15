#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameBoard.h"


class Game {
    public:

    Game();
    ~Game();

    private:

    GameBoard Player1;
    GameBoard Player2;

    void placeShips(GameBoard& player, int numShips);
    void playGame(GameBoard& Player1, GameBoard& Player2);
    int getColumn();
    int getRow();




};


#endif
