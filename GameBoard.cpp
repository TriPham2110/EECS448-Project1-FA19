#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(){
    boardSize = 8;
    board = new int*[8];
    for(int rep = 0; rep<8; rep++){
        board[rep] = new int[8];
    }

    oppBoard = new int*[8];
    for(int rep = 0; rep<8; rep++){
        oppBoard[rep] = new int[8];
    }

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
        board[i][j] = 0;
        oppBoard[i][j] = 0;
        }
    }
}

GameBoard::~GameBoard(){
  for(int i = 0; i < 8; i++){
    delete board[i];
    delete oppBoard[i];
  }
  delete board;
  delete oppBoard;
}

void GameBoard::addShip(Ship *newShip){
  vector<Point*> shipCords = newShip->getShipCoordinates();

  for(int i = 0; i < shipCords.size(); i++){
    int x = (int)shipCords.at(i)->getX();
    int y = (int)shipCords.at(i)->getY();
    board[x][y] = 1;
  }
  ships.push_back(newShip);
}

string GameBoard::fire(int x, int y){
  if((x >= boardSize) || (y >= boardSize) || (x < 0) || (y < 0)){
    return "Error Bounds";
  }

  if(board[x][y] == 0){
    return "Miss";
  }

  else if(board[x][y] == 1){
    for(int i = 0; i < ships.size(); i++){
      if(ships.at(i)->containsCoordinate(x,y)){
        ships.at(i)->hit(x,y);
        if(ships.at(i)->isDestroyed()){
          return "Sunk";
        }
        return "Hit";
      }
    }
  }
  return "Error";
}

int** GameBoard::getBoard(){
  return board;
}

int** GameBoard::getOppBoard(){
  return oppBoard;
}

bool GameBoard::gameOver(){
  for(int i = 0; i < ships.size(); i++){
    if(!ships.at(i)->isDestroyed()){
      return false;
    }
  }
  return true;
}

bool GameBoard::isOccupied(int x, int y){
  if(board[x][y] == 0){
    return false;
  }
  else{
    return true;
  }
}

void GameBoard::updateOppBoard(int x, int y, string outcome){
  if(outcome == "Miss"){
    oppBoard[x][y] = 1;
  }
  else{
    oppBoard[x][y] = 2;
  }
}

void GameBoard::updateMyBoard(int x, int y, string outcome)
{
  if(outcome == "Miss"){
    board[x][y] = 1;
  }
  else{
    board[x][y] = 2;
  }
}

void GameBoard::printBoard(){
  cout << "A B C D E F G H\n";
  for(int i = 0; i < boardSize; i++){

    for(int j = 0; j < boardSize; j++){
      cout << board[i][j] << " ";
    }
      cout << (i + 1) << " \n";
    cout << "";
  }
}

void GameBoard::printOppBoard(){
  cout << "A B C D E F G H\n";
  for(int i = 0; i < boardSize; i++){

    for(int j = 0; j < boardSize; j++){
      cout << oppBoard[i][j] << " ";
    }
      cout << (i + 1) << " \n";
    cout << "";
  }
}

GameBoard& GameBoard::operator=(const GameBoard &a)
{
    boardSize = a.boardSize; board = a.board; oppBoard = a.oppBoard, ships = a.ships;

    return *this;  // Return a reference to myself.
}
