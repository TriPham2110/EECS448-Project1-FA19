#include "Game.h"
#include <limits>
#include "StringColor.h"

Game::Game(){




        srand(time(NULL));
        int numShips = -1;
        int choice;
        std::string newGame = "";
    
        s.loadInfo();
        StringColor::changeTheme("default");


    do{
        std::cout << StringColor::TEXT;
        
        
        Player1.resetBoard();
        Player2.resetBoard();
        AI.resetBoard();
        
        numShips = -1;
        newGame = "";
        std::cout << ("Welcome to Battleship!") << std::endl;



        std::cout << "1. Player vs Player" <<std::endl;
        std::cout << "2. Player vs Computer" <<std::endl;
        std::cout << "3. Change Theme" <<std::endl;
        std::cout << "4. Scoreboard" <<std::endl;
        std::cout << "5. Exit" <<std::endl;

        std::cin>>choice;
		choice = restrictIntInput(choice);



        if (choice == 2){
              std::cout <<std::endl;
              std::cout<<("Enter your name:")<<std::endl;
              std::cin>>name1;
              int difficulty = -1;

              if(!s.playerInScoreboard(name1)){
                  
                  s.addNewPlayer(name1);
                  s.loadInfo();
              }

              while(difficulty > 3 || difficulty < 0){
                  std::cout <<std::endl;
                  std::cout << "Please select a difficulty" << std::endl;
                  std::cout << "0 - Easy" << std::endl;
                  std::cout << "1 - Medium" << std::endl;
                  std::cout << "2 - Hard" << std::endl;
                  std::cout << "I choose you!: ";
                  std::cin >> difficulty;
                  difficulty = restrictIntInput(difficulty);
              }

              while(numShips > 5 || numShips < 1){
                  std::cout <<std::endl;
                  std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
                  std::cin >> numShips;
                  numShips = restrictIntInput(numShips);
              }
              system("clear");
              std::cout << (" ")<< std::endl;
              std::cout << ("Please place your ships")<< std::endl;
              this->placeShips(Player1, numShips, 1);
              std::cout << ("Your board...")<< std::endl;
              Player1.printBoard();

              this->placeShipsAI(AI, numShips);
              this->playAI(Player1, AI, difficulty);
        }
        else if (choice == 1){
              std::cout <<std::endl;
              std::cout<<("Enter Player 1 name:")<<std::endl;
              std::cin>>name1;
              std::cout <<std::endl;
              std::cout<<("Enter Player 2 name:")<<std::endl;
              std::cin>>name2;
              std::cout <<std::endl;

              if(!s.playerInScoreboard(name1)){
                  s.addNewPlayer(name1);
                  s.loadInfo();
              }
              if(!s.playerInScoreboard(name2)){
                  s.addNewPlayer(name2);
                  s.loadInfo();
              }

              while(numShips > 5 || numShips < 1){
                  std::cout <<std::endl;
                  std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
                  std::cin >> numShips;
                  numShips = restrictIntInput(numShips);
              }

              system("clear");

              std::cout << (" ")<< std::endl;
              std::cout << name1<<(" please place your ships")<< std::endl;
              this->placeShips(Player1, numShips, 1);

              std::cout << name1<<("'s board...")<< std::endl;
              Player1.printBoard();

              system("clear");
              std::cout << (" ")<< std::endl;;
              std::cout << name2 <<(" please place your ships")<< std::endl;
              this->placeShips(Player2, numShips, 2);
              std::cout << name2<<("'s board...")<< std::endl;
              Player2.printBoard();

              playGame(Player1, Player2);
         }

        else if(choice == 3){
            system("clear");
            std::cout << "Choose Theme" <<std::endl;
            std::cout << "1. Default" <<std::endl;
            std::cout << "2. Meet's Lakers theme" <<std::endl;
            std::cout << "3. Tri's theme" <<std::endl;
            std::cout << "4. Apurva's theme" <<std::endl;
            std::cout << "5. Jace's theme" <<std::endl;
            std::cout << "6. Max's theme" <<std::endl;
            std::cout << "7. Light Mode" <<std::endl;
            std::cout << "8. Dark Mode" <<std::endl;
            std::cout << "9. Chaos" <<std::endl;

            int theme =0;
            std::cin>>theme;
		    theme = restrictIntInput(theme);

            if(theme == 1){
                StringColor::changeTheme("default");
            }
            else if(theme == 2){
                StringColor::changeTheme("meet");
                std::cout << "testing working" <<std::endl;
                std::cout << StringColor::WATER <<std::endl;
            }
            else if(theme == 3){
                StringColor::changeTheme("tri");
            }
            else if(theme == 4){
                StringColor::changeTheme("apurva");
            }
            else if(theme == 5){
                StringColor::changeTheme("jace");
            }
            else if(theme == 6){
                StringColor::changeTheme("max");
            }
            else if(theme == 7){
                StringColor::changeTheme("lightMode");
            }
            else if(theme == 8){
                StringColor::changeTheme("darkMode");
            }
            else if(theme == 9){
                StringColor::changeTheme("chaos");
            }

            system("clear");

        }

        else if (choice == 4){
            system("clear");

            try{
                s.loadInfo();
                s.sort();
                s.print();
            }catch(int e){
                std::cout <<"Couldn't load scoreboard" << std::endl;
            }
            std::cout <<std::endl;
            std::cout << "Press enter to return to main menu" <<std::endl;
            getchar();


        }


        if(choice == 2 || choice == 1){
            std::cout <<std::endl;
            std::cout << "Press enter to return to main menu" <<std::endl;
            getchar();

        }




        system("clear");



    }while(choice !=5);






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

void Game::placeShips(GameBoard &player, int numShips, int pNum){
    std::string tempName;
	for(int i = 1; i <= numShips; i++){
		int shipLength = i;
		Ship* tempShip = new Ship(shipLength);
		bool vert = false;

        system("clear");

		player.printBoard();
        
        tempName = "";
        
        if(pNum == 1){
            tempName = name1;
        }
        else{
            tempName = name2;
        }

		int shipCol;
		int shipRow;
		int path = 3;


		for(int j = 1; j <= shipLength; j++){
			std::cout << (" ") << std::endl;
			std::cout<<tempName << " please place piece " << j << " of " << shipLength << " of ship " << shipLength << std::endl;

            int* cords = new int[2];

            getCoordinateInput(cords);

            shipCol = cords[0];
            shipRow = cords[1];

            delete[] cords;

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
    system("clear");
    player.printBoard();
    std::cout << tempName << "'s board\nPress enter to continue";
    getchar();
    
    system("clear");
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
    system("clear");
    while(!Player1.gameOver() && !AI.gameOver()){
        int row, col;
        bool validInput = false;


        std::cout << ("")<< std::endl;;
        std::cout << name1<<(" please fire")<< std::endl;
        std::cout << ("AI Board:")<< std::endl;
        Player1.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player1.printBoard();


        validInput = false;
        while(!validInput){
            int* cords = new int[2];

            getCoordinateInput(cords);

            col = cords[0];
            row = cords[1];

            delete[] cords;

            std::string fire = AI.fire(row,col);

            if(Player1.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                    std::cout << ("Miss") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Miss");
                    validInput = true;

                }
                else if(fire == "Hit"){
                    std::cout << ("Hit!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();

                    Player1.updateOppBoard(row,col,"Hit");
                    std::cout << ("Hit!") << std::endl;
                    validInput = true;

                    system("clear");
                }
                else if(fire == "Sunk"){
                    std::cout << ("Sunk!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();

                    Player1.updateOppBoard(row,col,"Sunk");
                    std::cout << ("Sunk!") << std::endl;
                    validInput = true;

                    system("clear");
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

        // AI's turn
        if(difficulty == 0)
            easyTurn();
        else if(difficulty == 1)
            mediumTurn();
        else if(difficulty == 2)
            hardTurn();

        if(Player1.gameOver())
            break;
    }

    if(Player1.gameOver()){
        std::cout << "Sorry "<<name1<<", you lost" << std::endl;
        s.playerAddLoss(name1);
        s.updateFile();
    }
    else{
        std::cout << "Congrats "<<name1<<", you won" << std::endl;
        s.playerAddWin(name1);
        s.updateFile();
    }

    std::cout << "Your board :\n";
    Player1.printBoard();
    std::cout << "\nAI's board :\n";
    AI.printBoard();
}

void Game::playGame( GameBoard& Player1, GameBoard& Player2){
    while(!Player1.gameOver() && !Player2.gameOver()){
        int row, col;
        bool validInput = false;
        system("clear");
        
        std::cout << name1 << "'s turn\nPress enter to start turn";
        getchar();
        
        system("clear");
        

        std::cout << ("")<< std::endl;;
        std::cout << name1 <<" please fire"<< std::endl;
        std::cout <<name2<<"'s Board:"<< std::endl;
        Player1.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player1.printBoard();

        validInput = false;
        while(!validInput){
            int* cords = new int[2];

            getCoordinateInput(cords);

            col = cords[0];
            row = cords[1];

            delete[] cords;

            std::string fire = Player2.fire(row,col);

            if(Player1.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                    system("clear");
                    std::cout << ("Missed!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Miss");
                    Player2.updateMyBoard(row, col, "Miss");
                    validInput = true;
                }
                else if(fire == "Hit"){
                    system("clear");
                    std::cout << ("Hit!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();
                    system("clear");

                    Player1.updateOppBoard(row,col,"Hit");
                    Player2.updateMyBoard(row, col, "Hit");
                    validInput = true;
                }
                else if(fire == "Sunk"){
                    system("clear");
                    std::cout << ("Sunk!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
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
        
        std::cout << name2 << "'s turn\nPress enter to start turn";
        getchar();
        
        system("clear");

        std::cout << ("")<< std::endl;
        std::cout << name2<<" please fire"<< std::endl;
        std::cout << name1<<"'s Board:"<< std::endl;
        Player2.printOppBoard();
        std::cout << ("Your Board:")<< std::endl;
        Player2.printBoard();

        validInput = false;
        while(!validInput){
            int* cords = new int[2];

            getCoordinateInput(cords);

            col = cords[0];
            row = cords[1];

            delete[] cords;

            std::string fire = Player1.fire(row,col);

            if(Player2.getOppBoard()[row][col] == 0){
                if(fire == "Miss"){
                        system("clear");
                        std::cout << ("Missed!") << std::endl;
                        std::cout << ("Press enter to continue!") << std::endl;
                        getchar();
                        system("clear");

                        Player2.updateOppBoard(row,col,"Miss");
                        Player1.updateMyBoard(row,col,"Miss");
                        validInput = true;
                }
                else if(fire == "Hit"){
                    system("clear");
                    std::cout << ("Hit!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
                    getchar();
                    system("clear");

                    Player2.updateOppBoard(row,col,"Hit");
                    Player1.updateMyBoard(row,col,"Hit");
                    validInput = true;
                }
                else if(fire == "Sunk"){
                    system("clear");
                    std::cout << ("Sunk!") << std::endl;
                    std::cout << ("Press enter to continue!") << std::endl;
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

    if(Player1.gameOver()) {
        std::cout << "Congrats " <<name2<<", you won" << std::endl;
        s.playerAddLoss(name1);
        s.playerAddWin(name2);
        s.updateFile();
    }

    if(Player2.gameOver()){
        std::cout << "Congrats "<<name1<<", you won" << std::endl;
        s.playerAddLoss(name2);
        s.playerAddWin(name1);
        s.updateFile();

    }

    std::cout << name1 << "'s board :\n";
    Player1.printBoard();
    std::cout << name2 << "'s board :\n";
    Player2.printBoard();

}

void Game::getCoordinateInput(int*& coordinates){
    bool valid = false;
    std::string input;

    while(!valid){
        std::cout << "Please enter a coordinate: ";
        std::getline(std::cin, input);
        if(input.length() == 2){
            std::string x = input.substr(0,1);
            std::string y = input.substr(1,1);

            int xTemp = -1;
            int yTemp = -1;

            if(x == "A"){
    			xTemp = 0;
    		}
    		else if(x == "B"){
    			xTemp = 1;
    		}
    		else if(x == "C"){
    			xTemp = 2;
    		}
    		else if(x == "D"){
    			xTemp = 3;
    		}
    		else if(x == "E"){
    			xTemp = 4;
    		}
    		else if(x == "F"){
    			xTemp = 5;
    		}
    		else if(x == "G"){
    			xTemp = 6;
    		}
    		else if(x == "H"){
    			xTemp = 7;
    		}

            if((y.find_first_not_of( "0123456789" ) == std::string::npos)){
                yTemp = std::stoi(y);
                if(yTemp > 0 && yTemp <= 8 && yTemp){
        			 yTemp--;
        		}
                else{
                    yTemp = -1;
                }
            }

            if(xTemp != -1 && yTemp != -1){
                coordinates[0] = xTemp;
                coordinates[1] = yTemp;
                valid = true;
            }
        }
    }
}

void Game::easyTurn(){
	do{
		int xRandom = rand() % 8;
		int yRandom = rand() % 8;
		xRandomValue = xRandom;
		yRandomValue = yRandom;
	}while(AI.getOppBoard()[xRandomValue][yRandomValue] != 0);

    std::string outcome = Player1.fire(xRandomValue, yRandomValue);
    Player1.updateMyBoard(xRandomValue, yRandomValue, outcome);

	AI.updateOppBoard(xRandomValue, yRandomValue, outcome);
}

void Game::mediumTurn(){
	std::string tempTemp;
	std::cout << "mediumFlag: " << mediumTurnFlag << std::endl;
	if(mediumTurnFlag == 0){
		do{
			int xRandom = rand() % 8;
			int yRandom = rand() % 8;
			xRandomValue = xRandom;
			yRandomValue = yRandom;
		}while(AI.getOppBoard()[xRandomValue][yRandomValue] != 0);
		std::string temp = Player1.fire(xRandomValue, yRandomValue);
		tempTemp = temp;
		AI.updateOppBoard(xRandomValue, yRandomValue, temp);
        Player1.updateMyBoard(xRandomValue, yRandomValue, temp);
		if(temp == "Hit"){
			mediumTurnFlag = 1;
		}
	}

	else if(mediumTurnFlag != 0){
		if(xRandomValue >= (0 + mediumTurnFlag) && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue-mediumTurnFlag][yRandomValue] == 0){
			std::string temp = Player1.fire(xRandomValue-mediumTurnFlag, yRandomValue);
			tempTemp = temp;
			AI.updateOppBoard(xRandomValue-mediumTurnFlag, yRandomValue, temp);
            Player1.updateMyBoard(xRandomValue, yRandomValue, temp);

			if(!(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0) && !(xRandomValue >= 0 && xRandomValue <= (7- mediumTurnFlag) && yRandomValue >= 0 && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue+mediumTurnFlag][yRandomValue] == 0) && !(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= (7 - mediumTurnFlag) && AI.getOppBoard()[xRandomValue][yRandomValue+mediumTurnFlag] == 0)){
				mediumTurnFlag++;
			}

			if(temp == "Sunk"){
				mediumTurnFlag = 0;
			}
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= 0 && yRandomValue <= (7 - mediumTurnFlag) && AI.getOppBoard()[xRandomValue][yRandomValue+mediumTurnFlag] == 0){
			std::string temp = Player1.fire(xRandomValue, yRandomValue+mediumTurnFlag);
			tempTemp = temp;
			AI.updateOppBoard(xRandomValue, yRandomValue+mediumTurnFlag, temp);
            Player1.updateMyBoard(xRandomValue, yRandomValue, temp);

			if(!(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0) && !(xRandomValue >= 0 && xRandomValue <= (7- mediumTurnFlag) && yRandomValue >= 0 && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue+mediumTurnFlag][yRandomValue] == 0)){
				mediumTurnFlag++;
			}

			if(temp == "Sunk"){
				mediumTurnFlag = 0;
			}
		}
		else if(xRandomValue >= 0 && xRandomValue <= (7- mediumTurnFlag) && yRandomValue >= 0 && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue+mediumTurnFlag][yRandomValue] == 0){
			std::string temp = Player1.fire(xRandomValue+mediumTurnFlag, yRandomValue);
			tempTemp = temp;
			AI.updateOppBoard(xRandomValue+mediumTurnFlag, yRandomValue, temp);
            Player1.updateMyBoard(xRandomValue, yRandomValue, temp);

			if(!(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0)){
				mediumTurnFlag++;
			}

			if(temp == "Sunk"){
				mediumTurnFlag = 0;
			}
		}
		else if(xRandomValue >= 0 && xRandomValue <= 7 && yRandomValue >= (0 + mediumTurnFlag) && yRandomValue <= 7 && AI.getOppBoard()[xRandomValue][yRandomValue-mediumTurnFlag] == 0){
			std::string temp = Player1.fire(xRandomValue, yRandomValue-mediumTurnFlag);
			tempTemp = temp;
			AI.updateOppBoard(xRandomValue, yRandomValue-mediumTurnFlag, temp);
            Player1.updateMyBoard(xRandomValue, yRandomValue, temp);

			mediumTurnFlag++;

			if(temp == "Sunk"){
				mediumTurnFlag = 0;
			}
		}
	}
}

void Game::hardTurn(){
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			if(Player1.getBoard()[x][y] == 1 && (AI.getOppBoard()[x][y] != 2 )){
                std::string outcome = Player1.fire(x,y);
                Player1.updateMyBoard(x,y,outcome);
				AI.updateOppBoard(x, y, outcome);
				return;
			}
		}
	}
}
