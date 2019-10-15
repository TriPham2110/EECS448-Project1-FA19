#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include <string>
#include <vector>

#include "Ship.h"

using namespace std;

class GameBoard{
  private:
    int boardSize;
    int** board = nullptr;
    int** oppBoard = nullptr;
    vector<Ship*> ships;
    int hard_code = 0;
  public:
    GameBoard();
    ~GameBoard();
    void addShip(Ship *newShip);
    string fire(int x, int y);
    int** getBoard();
    int** getOppBoard();
    bool gameOver();
    bool canFindPath(int x, int y, int shipLength);
    bool isOccupied(int x, int y);
    void updateOppBoard(int x, int y, string outcome);
    void updateMyBoard(int x, int y, string outcome);
    void printBoard();
    void printOppBoard();
    GameBoard& operator=(const GameBoard &a);
};

#endif
