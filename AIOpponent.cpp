#include "AIOpponent.h"

AIOpponent::AIOpponent(GameBoard& AIBoardPass){
	AIBoard = AIBoardPass;
	mediumTurnFlag = 0;
}

void AIOpponent::easyTurn(){
	do{
		int xRandom = rand() % 8;
		int yRandom = rand() % 8;
		xRandomValue = xRandom;
		yRandomValue = yRandom;
	} while(AIBoard.getOppBoard()[xRandomValue][yRandomValue] != 0);

	AIBoard.updateOppBoard(xRandomValue, yRandomValue, AIBoard.fire(xRandomValue, yRandomValue));
}

void AIOpponent::mediumTurn(){
	if(mediumTurnFlag == 0){
		do{
			int xRandom = rand() % 8;
			int yRandom = rand() % 8;
			xRandomValue = xRandom;
			yRandomValue = yRandom;
		} while(AIBoard.getOppBoard()[xRandomValue][yRandomValue] != 0);

		AIBoard.updateOppBoard(xRandomValue, yRandomValue, AIBoard.fire(xRandomValue, yRandomValue));
		mediumTurnFlag = 1;
	}

	if(mediumTurnFlag == 1){
		if(xRandomValue > 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= 7){
			string temp = AIBoard.fire(xRandomValue-1, yRandomValue);
			AIBoard.updateOppBoard(xRandomValue-1, yRandomValue, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue < 7){
			string temp = AIBoard.fire(xRandomValue, yRandomValue+1);
			AIBoard.updateOppBoard(xRandomValue, yRandomValue+1, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue < 7 && yRandomValue >= 0 && yRandomValue <= 7){
			string temp = AIBoard.fire(xRandomValue+1, yRandomValue);
			AIBoard.updateOppBoard(xRandomValue+1, yRandomValue, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue > 0 && yRandomValue <= 7){
			string temp = AIBoard.fire(xRandomValue, yRandomValue-1);
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
				AIBoard.updateMyBoard(x, y, AIBoard.fire(x, y));
				return;
			}
		}
	}
}
