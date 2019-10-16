#include "AIOpponent.h"

AIOpponent::AIOpponent(GameBoard& Player1, GameBoard& AIBoardPass){
	srand(time(NULL));
	AIBoard = AIBoardPass;
	Player = Player1;
	mediumTurnFlag = 0;
}

void AIOpponent::easyTurn(){
	do{
		int xRandom = rand() % 8;
		int yRandom = rand() % 8;
		xRandomValue = xRandom;
		yRandomValue = yRandom;
	} while(AIBoard.getOppBoard()[xRandomValue][yRandomValue] != 0);

	AIBoard.updateOppBoard(xRandomValue, yRandomValue, Player.fire(xRandomValue, yRandomValue));
}

void AIOpponent::mediumTurn(){
	std::cout << "mediumFlag: " << mediumTurnFlag << std::endl;
	if(mediumTurnFlag == 0){
		do{
			int xRandom = rand() % 8;
			int yRandom = rand() % 8;

			xRandomValue = xRandom;
			yRandomValue = yRandom;
		} while(AIBoard.getOppBoard()[xRandomValue][yRandomValue] != 0);
		string temp = Player.fire(xRandomValue, yRandomValue);
		AIBoard.updateOppBoard(xRandomValue, yRandomValue, temp);
		if(temp == "Hit") mediumTurnFlag = 1;
	}

<<<<<<< HEAD
	else if(mediumTurnFlag == 1){
		if(xRandomValue > 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue] == 0){
			string temp = Player.fire(xRandomValue-1, yRandomValue);
=======
	if(mediumTurnFlag == 1){
		if(xRandomValue > 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue] == 0){
			string temp = AIBoard.fire(xRandomValue-1, yRandomValue);
>>>>>>> be2e77ccc80791046cc7a34171b0cf43748b1206
			AIBoard.updateOppBoard(xRandomValue-1, yRandomValue, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue < 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue] == 0){
<<<<<<< HEAD
			string temp = Player.fire(xRandomValue, yRandomValue+1);
=======
			string temp = AIBoard.fire(xRandomValue, yRandomValue+1);
>>>>>>> be2e77ccc80791046cc7a34171b0cf43748b1206
			AIBoard.updateOppBoard(xRandomValue, yRandomValue+1, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue < 7 && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue] == 0){
<<<<<<< HEAD
			string temp = Player.fire(xRandomValue+1, yRandomValue);
=======
			string temp = AIBoard.fire(xRandomValue+1, yRandomValue);
>>>>>>> be2e77ccc80791046cc7a34171b0cf43748b1206
			AIBoard.updateOppBoard(xRandomValue+1, yRandomValue, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue > 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue] == 0){
<<<<<<< HEAD
			string temp = Player.fire(xRandomValue, yRandomValue-1);
=======
			string temp = AIBoard.fire(xRandomValue, yRandomValue-1);
>>>>>>> be2e77ccc80791046cc7a34171b0cf43748b1206
			AIBoard.updateOppBoard(xRandomValue, yRandomValue-1, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
	}
}

void AIOpponent::hardTurn(){
	for(int x = 0; x < 7; x++){
		for(int y = 0; y < 7; y++){
			if(AIBoard.getBoard()[x][y] == 1){
				AIBoard.updateMyBoard(x, y, Player.fire(x, y));
				return;
			}
		}
	}
}
