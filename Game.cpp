#include "Game.h"
#include <limits>

Game::Game(){
        srand(time(NULL));
        int numShips = -1;
        int choice;
        std::cout << ("Welcome to Battleship!") << std::endl;
        std::cout<<("How many players would you like to have (Press 1 or 2)?")<<std::endl;
        std::cin>>choice;


        if (choice == 1)
        {
              int difficulty = -1;

              while(difficulty > 3 || difficulty < 0){
                  std::cout << "Please select a difficulty" << std::endl;
                  std::cout << "0 - Easy" << std::endl;
                  std::cout << "1 - Medium" << std::endl;
                  std::cout << "2 - Hard" << std::endl;
                  std::cout << "I choose you!: ";
                  std::cin >> difficulty;
              }

              while(numShips > 5 || numShips < 1){
                  std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
                  std::cin >> numShips;
              }
              system("clear");
              std::cout << (" ")<< std::endl;;
              std::cout << ("Please place your ships")<< std::endl;;
              this->placeShips(Player1, numShips);
              std::cout << ("Your board...")<< std::endl;
              Player1.printBoard();

              this->placeShipsAI(AI, numShips);
              this->playAI(Player1, AI, difficulty);
        }
        else if (choice == 2)
        {
              while(numShips > 5 || numShips < 1){
                  std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
                  std::cin >> numShips;
              }

              system("clear");

              std::cout << (" ")<< std::endl;;
              std::cout << ("Player 1 please place your ships")<< std::endl;;
              this->placeShips(Player1, numShips);

              std::cout << ("Player 1's board...")<< std::endl;
              Player1.printBoard();

              system("clear");
              std::cout << (" ")<< std::endl;;
              std::cout << ("Player 2 please place your ships")<< std::endl;;
              this->placeShips(Player2, numShips);
              std::cout << ("Player 2's board...")<< std::endl;
              Player2.printBoard();

              playGame(Player1, Player2);
         }


}

Game::~Game(){}

int Game::restrictIntInput(int option){
	while(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please enter a valid int: ";
		std::cin >> option;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return option;
}

void Game::placeShips(GameBoard &player, int numShips){

	for(int i = 1; i <= numShips; i++){
		int shipLength = i;
		Ship* tempShip = new Ship(shipLength);
		bool vert = false;

        system("clear");

		player.printBoard();

		int shipCol;
		int shipRow;
		int path = 3;


		for(int j = 1; j <= shipLength; j++){
			std::cout << (" ") << std::endl;
			std::cout << "Please place piece " << j << " of " << shipLength << " of ship " << shipLength << std::endl;

			shipCol = getColumn();
			shipRow = getRow();

			if(j==2){
				if(tempShip->getShipCoordinates().at(0)->getY() != shipCol){
					vert = false;
				}
				else{
					vert = true;
				}
			}

			if( j == 1 && shipLength > 1 ){
				path = player.canFindPath(shipRow, shipCol, shipLength);
				if(path == 0){
					j--;
				}
				else{
					tempShip->addCoordinates(shipRow, shipCol);
				}
			}
			else if(player.isOccupied(shipRow, shipCol) || !tempShip->inLine(shipRow, shipCol, vert) || tempShip->containsCoordinate(shipRow, shipCol) || ((((path == 1 ) && vert) || ((path == 2 ) && !vert)))){
				j--;
			}

			else{
				tempShip->addCoordinates(shipRow, shipCol);
			}
			//checking on 2nd piece placement if the ship
			//is vertical or horizontal
		}
		player.addShip(tempShip);
	}

}

void Game::placeShipsAI(GameBoard& AI, int numShips){
	std::cout << std::endl;
	for(int i = 1; i <= numShips; i++){
		int shipLength = i;
		bool placed = false;

		while(!placed){
			// right = 0
			// down = 1
			int orientation = rand() % 2;
			int xRandom = 0;
			int yRandom = 0;

			if(orientation == 0){
				xRandom = rand() % (8 - shipLength);
				yRandom = rand() % 8;
			}
			else if(orientation == 1){
				xRandom = rand() % 8;
				yRandom = rand() % (8 - shipLength);
			}

			if(orientation == 0){
				bool isValid = true;
				Ship* tempShip = new Ship(shipLength);

				for(int j = 0; j < shipLength; j++){
					if(AI.isOccupied(yRandom, xRandom+j)){
						isValid = false;
					}
					else{
						tempShip->addCoordinates(yRandom,xRandom+j);
					}
				}

				if(isValid){
					AI.addShip(tempShip);
					placed = true;
				}
				else{
					delete tempShip;
				}
			}
			else if(orientation == 1){
				bool isValid = true;
				Ship* tempShip = new Ship(shipLength);

				for(int j = 0; j < shipLength; j++){
					if(AI.isOccupied(yRandom+j, xRandom)){
						isValid = false;
					}
					else{
						tempShip->addCoordinates(yRandom+j,xRandom);
					}
				}

				if(isValid){
					AI.addShip(tempShip);
					placed = true;
				}
				else{
					delete tempShip;
				}
			}
		}
	}
}

void Game::playAI(GameBoard& Player1, GameBoard& AI, int difficulty)
{
    AIOpponent AIPlayer = AIOpponent(Player1, AI);

    while(!Player1.gameOver() && !AI.gameOver()){
        int row, col;
        bool validInput = false;
        system("clear");

        system("clear");

        std::cout << ("")<< std::endl;;
        std::cout << ("Player 1 please fire")<< std::endl;
        std::cout << ("AI Board:")<< std::endl;
        Player1.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player1.printBoard();


        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();
            std::string fire = Player2.fire(row,col);

            if(Player1.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                    std::cout << ("Miss") << std::endl;
                        Player1.updateOppBoard(row,col,"Miss");
                        validInput = true;
                }
                else if(fire == "Hit"){
                    std::cout << ("Hit!") << std::endl;
                    Player1.updateOppBoard(row,col,"Hit");
                    validInput = true;
                }
                else if(fire == "Sunk"){
                    std::cout << ("Sunk!") << std::endl;
                    Player1.updateOppBoard(row,col,"Sunk");
                    validInput = true;
                }
                else if(fire == "Error Bounds"){
                     std::cout << ("Out of bounds") << std::endl;
                }
                else {
                    std::cout << ("IDK what happened")<< std::endl;
                }
            }
            else{
                std::cout << std::endl << "You've already fired here" << std::endl << std::endl;
            }
        }

        if(AI.gameOver())
            break;

        // player 2 turn
        if(difficulty == 0)
            AIPlayer.easyTurn();
        else if(difficulty == 1)
            AIPlayer.mediumTurn();
        else if(difficulty == 2)
            AIPlayer.hardTurn();

        AI.printOppBoard();

        if(Player1.gameOver())
            break;
    }

    if(Player1.gameOver())
        std::cout << ("Sorry Player 1, you lost") << std::endl;
    else
        std::cout << ("Congrats Player 1, you won") << std::endl;
}

void Game::playGame( GameBoard& Player1, GameBoard& Player2){
    while(!Player1.gameOver() && !Player2.gameOver()){
        int row, col;
        bool validInput = false;
        system("clear");

        std::cout << ("")<< std::endl;;
        std::cout << ("Player 1 please fire")<< std::endl;
        std::cout << ("Opponents Board:")<< std::endl;
        Player1.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player1.printBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();
            std::string fire = Player2.fire(row,col);

            if(Player1.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                    system("clear");
                    std::cout << ("Missed!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Miss");
                    Player2.updateMyBoard(row, col, "Miss");
                    validInput = true;
                }
                else if(fire == "Hit"){
                    system("clear");
                    std::cout << ("Hit!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Hit");
                    Player2.updateMyBoard(row, col, "Hit");
                    validInput = true;
                }
                else if(fire == "Sunk"){
                    system("clear");
                    std::cout << ("Sunk!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Sunk");
                    Player2.updateMyBoard(row, col, "Sunk");
                    validInput = true;
                }
                else if(fire == "Error Bounds"){
                     std::cout << ("Out of bounds")<< std::endl;
                }
            }
            else{
                std::cout << std::endl << "You've already fired here" << std::endl << std::endl;
            }
        }
        if(Player2.gameOver())
            break;

        system("clear");

        std::cout << ("")<< std::endl;
        std::cout << ("Player 2 please fire")<< std::endl;
        std::cout << ("Opponents Board:")<< std::endl;
        Player2.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player2.printBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();

            std::string fire = Player1.fire(row,col);

            if(Player2.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                        system("clear");
                        std::cout << ("Missed!") << std::endl;
                        getchar();
                        system("clear");

                        Player2.updateOppBoard(row,col,"Miss");
                        Player1.updateMyBoard(row,col,"Miss");
                        validInput = true;
                }
                else if(fire == "Hit"){
                    system("clear");
                    std::cout << ("Hit!") << std::endl;
                    getchar();
                    system("clear");

                    Player2.updateOppBoard(row,col,"Hit");
                    Player1.updateMyBoard(row,col,"Hit");
                    validInput = true;
                }
                else if(fire == "Sunk"){
                    system("clear");
                    std::cout << ("Sunk!") << std::endl;
                    getchar();
                    system("clear");

                    Player2.updateOppBoard(row,col,"Sunk");
                    Player1.updateMyBoard(row,col,"Sunk");
                    validInput = true;
                }
                else if(fire == "Error Bounds"){
                     std::cout << ("Out of bounds")<< std::endl;
                }
            }
            else{
                std::cout << std::endl << "You've already fired here" << std::endl << std::endl;
            }
        }

        if(Player1.gameOver())
            break;
        system("clear");
    }

    if(Player1.gameOver())
        std::cout << ("Congrats Player 2, you won") << std::endl;

    if(Player2.gameOver())
        std::cout << ("Congrats Player 1, you won") << std::endl;

}

int Game::getColumn(){
	int shipCol = -1;
	std::string shipColString;

	do{
		std::cout << ("Ship column(A-H): ") << std::endl;
		std::getline(std::cin, shipColString);

		if(shipColString == "A"){
			shipCol = 0;
		}
		else if(shipColString == "B"){
			shipCol = 1;
		}
		else if(shipColString == "C"){
			shipCol = 2;
		}
		else if(shipColString == "D"){
			shipCol = 3;
		}
		else if(shipColString == "E"){
			shipCol = 4;
		}
		else if(shipColString == "F"){
			shipCol = 5;
		}
		else if(shipColString == "G"){
			shipCol = 6;
		}
		else if(shipColString == "H"){
			shipCol = 7;
		}
		else{
			shipCol = -1;
		}
	}while(shipColString.length() != 1 || shipCol == -1);

	return shipCol;
}

int Game::getRow(){
	int shipRow = -1;
	while(shipRow == -1){
		int tempRow;
		std::cout << ("Ship row(1-8): ") << std::endl;
		std::cin >> tempRow;
		tempRow = restrictIntInput(tempRow);
		if(tempRow > 0 && tempRow <= 8){
			shipRow = tempRow - 1;
		}
	}
	return shipRow;
}
