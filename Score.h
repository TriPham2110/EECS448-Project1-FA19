#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Player{
	string name; 
	int wins;
	int losses;
	double percentage;
};

//http://www.cplusplus.com/forum/beginner/78887/
class Score{
	private:

		std::vector<Player> scoreboard;
		string name;
		string wins;
		string losses;
		int ten = 0;

	public:
		Score();
		void loadInfo();
		void print();
		void sort();
		void write();
		void insert();
		bool playerInScoreboard(std::string name);
		void addNewPlayer(std::string name);
        void playerAddWin(std::string name);
        void playerAddLoss(std::string name);
        void updateFile();
};
#endif
