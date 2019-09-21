#include<iostream>
#include<string>
#include "board.h"
#include "cell.h"
Board::Board()
{
  m_board = new cell **[8];
  for(int i =0;i<8;i++)
  {
    m_board[i] = new cell*[8];
  }
  for(int j = 0; j<8;j++)
  {
    for(int k =0;k<8;k++)
    {
      m_board[j][k] = new cell();
    }
  }
}

void Board::setShip(int row_num,int col_num)
{
  if ((dir == 'u')&&((row_num - (m_size - 1))>=0))
  {
    m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
    for(int i = 1;i<=m_size;i++)
    {
      m_board[--row_num][col_num] -> putShip();
    }
  }

  else if ((dir == 'd')&&((row_num + (m_size - 1))<8))
  {
    //m_board.setShip(row_num,col_num);
    m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
    for(int i = 1;i<=m_size;i++)
    {
      m_board[++row_num][col_num] -> putShip();
    }
  }

  else if ((dir == 'l')&&((col_num - (m_size - 1))>=0))
  {
    m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
    for(int i = 1;i<=m_size;i++)
    {
      m_board[row_num][--col_num] -> putShip();
    }
  }

  else if ((dir == 'r')&&((col_num + (m_size - 1))<8))
  {
    m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
    for(int i = 1;i<=m_size;i++)
    {
      m_board[row_num][--col_num] -> putShip();
    }
  }
  else
  {
    std::cout<<"\nShip is too big to place using the given orientation and position. Try Again!";
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
}
