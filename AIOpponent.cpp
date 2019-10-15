#include "AIOpponent.h"

void AIOpponent::easy(){

	do{
	
	int xRandom = rand() % 8;
	int yRandom = rand() % 8;
	
	}while(AIBoard.oppBoard[xRandom][yRandom] != 0);

	updateOppBoard(xRandom, yRandom, AIBoard.fire()); 

}
