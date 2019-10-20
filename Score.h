#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <iostream>
#include "Game.h"
#include <fstream>
#include "GameBoard.h"
using namespace std

//http://www.cplusplus.com/forum/beginner/78887/
class Score{
	private:

        std::vector<Entry> scoreboard;

        //Score();

	public:
        void AddPlayer(std::string playerName, int points);
        void Print();
        void Sort();
        void write();
				void insert();

};
#endif
