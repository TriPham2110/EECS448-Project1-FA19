#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(){
  boardSize = 8;
  board = new int[boardSize][boardSize];
  oppBoard = new int[boardSize][boardSize];
}

GameBoard::~GameBoard(){
  for(int i = 0; i < 8; i++){
    delete board[i];
    delete oppBoard[i];
  }
  delete board;
  delete oppBoard;
}

void GameBoard::addShip(Ship newShip){
  vector<Ship> shipCords = newShip.getShipCoordinates();

  for(int i = 0; i < shipCords.size(); i++){
    int x = (int)shipCords.at(i).getX();
    int y = (int)shipCords.at(i).getY();
    board[x][y] = 1;
  }
  ships.insert(newShip);
}

string GameBoard::fire(int x, int y){
  if((x >= boardSize) || (y >= boardSize) || (x < 0) || (y < 0)){
    return "Error Bounds";
  }

  if(board[x][y] == 0){
    return "Miss";
  }

  else if(board[x][y] == 1){
    for(int i = 1; i <= ships.size(); i++){
      if(ship.containsCoordinate(x,y)){
        ship.hit(x,y);
        if(ship.isDestroyed()){
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

bool GameBoard::gameOver(){
  for(int i = 1; i <= ships.size(); i++){
    if(!ship.isDestroyed()){
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

void GameBoard::printBoard(){
  cout << " A B C D E F G H\n";
  for(int i = 0; i < boardSize; i++){
    cout << (i + 1) << " \n";
    for(int j = 0; j < boardSize; j++){
      cout << board[i][j] << " \n";
    }
    cout << " ";
  }
}

void GameBoard::printOppBoard(){
  cout << " A B C D E F G H\n";
  for(int i = 0; i < boardSize; i++){
    cout << (i + 1) << " \n";
    for(int j = 0; j < boardSize; j++){
      cout << oppBoard[i][j] << " \n";
    }
    cout << " ";
  }
}
