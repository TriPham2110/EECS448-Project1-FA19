#include<iostream>
#include<string>
#include<tuple>
#include "board.h"
#include "cell.h"
Board::Board()
{
}

void Board::setShip(int row,int col)
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

<<<<<<< HEAD
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
||||||| merged common ancestors
void Board::setShip(int row,int col)
{

=======
  else if ((dir == 'l')&&((col_num - (m_size - 1))>=0))
  {
    m_board[row_num][col_num] -> putShip(); //Something that cell class should have. The size of the ship it is holding and the fact that is has a ship
    for(int i = 1;i<=m_size;i++)
    {
      m_board[row_num][--col_num] -> putShip();
    }
  }
>>>>>>> 9007446e11575c6c4d4d6550b4f4a409add262b1

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
>>>>>>> devel
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
    delete m_board;
}
