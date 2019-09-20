#include<iostream>
#include<string>
#include "board.h"
#include "cell.h"
Board::Board()
{
    Board cells = new Board[8][8];
}



void Board::setShip(int row,int col)
{

}
void Board::hit(int row, in col)
{
    cells[row, col].hit();
}
bool Board::isHit()
{

}
bool Board::isSunk()
{

}
bool Board::miss()
{

}
Board::~Board()
{
  //
}
