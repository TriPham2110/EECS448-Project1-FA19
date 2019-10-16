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
string tempTemp;
	std::cout << "mediumFlag: " << mediumTurnFlag << std::endl;
	if(mediumTurnFlag == 0){
		do{
			int xRandom = rand() % 8;
			int yRandom = rand() % 8;

			xRandomValue = xRandom;
			yRandomValue = yRandom;
		} while(AIBoard.getOppBoard()[xRandomValue][yRandomValue] != 0);
		string temp = Player.fire(xRandomValue, yRandomValue);
		tempTemp = temp;
		AIBoard.updateOppBoard(xRandomValue, yRandomValue, temp);
		if(temp == "Hit") mediumTurnFlag = 1;
	}

	else if(mediumTurnFlag != 0){
		if(xRandomValue >= (0 + mediumTurnFlag) && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue-mediumTurnFlag][yRandomValue] == 0){
			string temp = Player.fire(xRandomValue-mediumTurnFlag, yRandomValue);
			tempTemp = temp;
			AIBoard.updateOppBoard(xRandomValue-mediumTurnFlag, yRandomValue, temp);

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= (7 - mediumTurnFlag) && AIBoard.getOppBoard()[xRandomValue][yRandomValue+mediumTurnFlag] == 0){
			string temp = Player.fire(xRandomValue, yRandomValue+mediumTurnFlag);
			tempTemp = temp;
			AIBoard.updateOppBoard(xRandomValue, yRandomValue+mediumTurnFlag, temp);

			if(!(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0) 				&& !(xRandomValue >= 0 && xRandomValue <= (7- mediumTurnFlag) && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue+mediumTurnFlag][yRandomValue] == 0)){
			mediumTurnFlag++;
			}

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= (7- mediumTurnFlag) && yRandomValue >= 0 && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue+mediumTurnFlag][yRandomValue] == 0){
			string temp = Player.fire(xRandomValue+mediumTurnFlag, yRandomValue);
			tempTemp = temp;
			AIBoard.updateOppBoard(xRandomValue+mediumTurnFlag, yRandomValue, temp);

			if(!(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0)){
			mediumTurnFlag++;
			}

			if(temp == "Sunk")
				mediumTurnFlag = 0;
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AIBoard.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0){
			string temp = Player.fire(xRandomValue, yRandomValue-mediumTurnFlag);
			tempTemp = temp;
			AIBoard.updateOppBoard(xRandomValue, yRandomValue-mediumTurnFlag, temp);
		
			mediumTurnFlag++;

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
