#include "GameBoard.h"

#include "StringColor.h"

using namespace std;

GameBoard::GameBoard(){
	boardSize = 8;

	board =  new int*[8];
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
		delete[] board[i];
		delete[] oppBoard[i];
	}

	delete[] board;
	delete[] oppBoard;

	while(!ships.empty()){
		delete ships.back();
		ships.back() = nullptr;
		ships.pop_back();
	}
}

void GameBoard::addShip(Ship *newShip){
	std::vector<Point*> shipCords = newShip->getShipCoordinates();

	for(int i = 0; i < (int)shipCords.size(); i++){
		int x = (int)shipCords.at(i)->getX();
		int y = (int)shipCords.at(i)->getY();
		board[x][y] = 1;
	}
	ships.push_back(newShip);
}

std::string GameBoard::fire(int x, int y){
	if((x >= 8) || (y >= 8) || (x < 0) || (y < 0)){
		return "Error Bounds";
	}

	if(board[x][y] == 0){
		return "Miss";
	}

	else if(board[x][y] == 1){
		for(int i = 0; i < (int)ships.size(); i++){
			if(ships.at(i)->containsCoordinate(x,y)){
				ships.at(i)->hit(x,y);
				if(ships.at(i)->isDestroyed()){
                    for(Point* coordinate : ships.at(i)->getShipCoordinates()){
                        board[coordinate->getX()][coordinate->getY()] = 3;
                    }
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
	for(int i = 0; i < (int)ships.size(); i++){
		if(!ships.at(i)->isDestroyed()){
			return false;
		}
	}
	return true;
}

int GameBoard::canFindPath(int x, int y, int shipLength){
	//recursively try to find 1 straight path of shipLength
	//3 = both horizontal and vertical have paths
	//2 = only vertical has path(s)
	//1 = only horizontal has path(s)
	//0 = no paths
	bool vert = (shipLength <= numInLineX(x,y, 0));
	bool horz = (shipLength <= numInLineY(x,y, 0));

	if(horz && vert){
		return 3;
	}
	else if(vert){
		return 2;
	}
	else if (horz){
		return 1;
	}
	else{
		return 0;
	}
}

int GameBoard::numInLineX(int x, int y, int dir){
	if(x > 7 || x < 0  || board[x][y] == 1){
		return 0;
	}
	else if (dir == 0 ){
		return 1 + numInLineX(x + 1, y , 1) + numInLineX(x - 1, y , -1);
	}
	else{
		return 1 + numInLineX(x+ dir, y, dir);
	}
}

int GameBoard::numInLineY(int x, int y, int dir){
	if(y > 7 || y < 0  || board[x][y] == 1){
		return 0;
	}
	else if (dir == 0 ){
		return 1 + numInLineY(x , y +1, 1) + numInLineY(x, y - 1 , -1);
	}
	else{
		return 1 + numInLineY(x, y + dir, dir);
	}
}

bool GameBoard::isOccupied(int x, int y){
	return board[x][y] == 1;
}



void GameBoard::updateOppBoard(int x, int y, string outcome){
    if(outcome == "Miss"){
        oppBoard[x][y] = 4;
    }
    else if (outcome == "Hit"){
        oppBoard[x][y] = 2;
    }
    else if (outcome == "Sunk"){
        oppBoard[x][y] = 3;
    }
    else
        oppBoard[x][y] = 4;
}

void GameBoard::updateMyBoard(int x, int y, string outcome)
{
    if(outcome == "Miss"){
        board[x][y] = 4;
    }
    else if (outcome == "Hit"){
        board[x][y] = 2;
    }
    else if (outcome == "Sunk"){
        board[x][y] = 3;
    }
    else
        board[x][y] = 4;

}



void GameBoard::printBoard(){
  cout <<StringColor::TEXT<< " A  B  C  D  E  F  G  H \n";
  for(int i = 0; i < boardSize; i++){

    for(int j = 0; j < boardSize; j++){
        if(board[i][j] == 0){

            cout << StringColor::WATER;
        }
        else if(board[i][j] == 1){

            cout << StringColor::SHIP;
        }
        else if(board[i][j] == 2){

            cout << StringColor::HIT;
        }
        else if(board[i][j] == 3){

            cout << StringColor::SUNK;
        }
        else if(board[i][j] == 4){

            cout << StringColor::MISS;
        }
      //cout << oppBoard[i][j] << " ";
    }

      cout << StringColor::TEXT << (i + 1) << " \n";
    cout << "";
  }
}

void GameBoard::printOppBoard(){
  cout <<StringColor::TEXT<< " A  B  C  D  E  F  G  H \n";
  for(int i = 0; i < boardSize; i++){

    for(int j = 0; j < boardSize; j++){
        if(oppBoard[i][j] == 0){

            cout << StringColor::WATER;
        }
        else if(oppBoard[i][j] == 1){

            cout << StringColor::SHIP;
        }
        else if(oppBoard[i][j] == 2){

            cout << StringColor::HIT;
        }
        else if(oppBoard[i][j] == 3){

            cout << StringColor::SUNK;
        }
        else if(oppBoard[i][j] == 4){

            cout << StringColor::MISS;
        }
      //cout << oppBoard[i][j] << " ";
    }
      cout << StringColor::TEXT << (i + 1) << " \n";
    cout << "";
  }
}

void GameBoard::resetBoard(){
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
		board[i][j] = 0;
		oppBoard[i][j] = 0;
		}
	}
    ships.clear();
}

GameBoard& GameBoard::operator=(const GameBoard &a)
{
    boardSize = a.boardSize; board = a.board; oppBoard = a.oppBoard; ships = a.ships;

    return *this;  // Return a reference to myself.

}
