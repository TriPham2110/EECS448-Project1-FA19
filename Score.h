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
		/**
		 * @pre none
		 *		@param none
		 *		@post constructor
		 * 		@return none
		 */
		Score();
		/**
		 * @pre none
		 *		@param none
		 *		@post loading the info
		 * 		@return none
		 */
		void loadInfo();
		/**
		 * @pre none
		 *		@param none
		 *		@post prints the scoreboard
		 * 		@return none
		 */
		void print();
		/**
		 * @pre none
		 *		@param none
		 *		@post sorts the players from best to worst
		 * 		@return none
		 */
		void sort();
		/**
		 * @pre none
		 *		@param none
		 *		@post writes into Scoreboard.tri
		 * 		@return none
		 */
		void write();
		/**
		 * @pre none
		 *		@param none
		 *		@post inserts player into the Scoreboard.tri
		 * 		@return none
		 */
		void insert();
		/**
		 * @pre none
		 *		@param name
		 *		@post checks to see if the player is in scoreboard
		 * 		@return true or false whether the player is in scoreboard
		 */
		bool playerInScoreboard(std::string name);
		/**
		 * @pre none
		 *		@param name
		 *		@post adds new player to the scoreboard
		 * 		@return none
		 */
		void addNewPlayer(std::string name);
		/**
		 * @pre none
		 *		@param name
		 *		@post player's win
		 * 		@return none
		 */
		void playerAddWin(std::string name);
		/**
		 * @pre none
		 *		@param name
		 *		@post player's loss
		 * 		@return none
		 */
		void playerAddLoss(std::string name);
		/**
		 * @pre none
		 *		@param none
		 *		@post updates Scoreboard.tri
		 * 		@return none
		 */
		void updateFile();
};
#endif
