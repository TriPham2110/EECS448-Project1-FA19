#include<iostream>
#include<string>
#include<tuple>
#include "board.h"
#include "cell.h"
Board::Board()
{
    Board cells = new Board[8][8];
}



void Board::setShip(head[int, int], int len, int ort)
{
    // horizontal
    if(ort == 0)
    {
        for (i = head[0], i <= head[0] + len, ++i)
        {
            cells[i,head[1]].putShip();
        }
    }
    else
    { 
        for (j = head[1], j <= head[1] + len, ++j)
        {
            cells[head[0],j].putShip();
        }
    }
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
    delete cells;
}
