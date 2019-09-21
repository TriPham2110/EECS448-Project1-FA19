#include<iostream>
#include<string>
#include "board.h"
#include "cell.h"
Board::Board()
{
  for(int i = 0; i < 8; i++)
  {
        for(int j = 0; j< 8; j++)
        {
          m_board[i][j];
        }
  }
}

void Board::setShip(int row,int col)
{

}
void Board::hit(int row, int col)
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
