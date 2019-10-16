

//import java.util.Scanner;
#include "Game.h"


Game::Game(){
        int numShips = -1;

        std::cout << ("Welcome to Battleship!") << std::endl;

        while(numShips > 5 || numShips < 1){
            std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
            cin >> numShips;
        }

        std::cout << (" ")<< std::endl;;
        std::cout << ("Player 1 please place your ships")<< std::endl;;
        this->placeShips(Player1, numShips);

        std::cout << ("Player 1's board...")<< std::endl;
        Player1.printBoard();

        std::cout << (" ")<< std::endl;;
        std::cout << ("Player 2 please place your ships")<< std::endl;;
        this->placeShips(Player2, numShips);
        std::cout << ("Player 2's board...")<< std::endl;
        Player2.printBoard();

        playGame(Player1, Player2);

}

Game::~Game(){

}

void Game::placeShips(GameBoard &player, int numShips){
    for(int i = 1; i <= numShips; i++){
        int shipLength = i;
        Ship* tempShip = new Ship(shipLength);
        bool vert = false;

        player.printBoard();
        
        int shipCol;
        int shipRow;
        int path = 3;

        for(int j = 1; j <= shipLength; j++){
            std::cout << (" ")<< std::endl;
            std::cout << "Please place piece " << j << " of " << shipLength<< std::endl;
            

            shipCol = getColumn();
            shipRow = getRow();
            
            if(j==2)
            {
                if(tempShip->getShipCoordinates().at(0)->getY() != shipCol){
                    vert = false;
                    
                }
                else
                    vert = true;
                
                std::cout << vert << " vert" << std::endl;
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

            else 
                tempShip->addCoordinates(shipRow, shipCol);
            
            std::cout << "cookie " << j <<std::endl;
            //checking on 2nd piece placement if the ship
            //is vertical or horizontal
            


        }

        player.addShip(tempShip);

    }

}

void Game::playGame( GameBoard& Player1, GameBoard& Player2){
    while(!Player1.gameOver() && !Player2.gameOver()){
        int row, col;
        bool validInput = false;

        std::cout << ("")<< std::endl;;
        std::cout << ("Player 1 please fire")<< std::endl;;
        Player1.printOppBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();
            string fire = Player2.fire(row,col);

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
                Player1.updateOppBoard(row,col,"Hit");
                validInput = true;
            }
            else if(fire == "Error Bounds"){
                 std::cout << ("Out of bounds")<< std::endl;
            }
            else {
                std::cout << ("IDK what happened")<< std::endl;

            }
        }
        if(Player2.gameOver())
            break;

        std::cout << ("")<< std::endl;
        std::cout << ("Player 2 please fire")<< std::endl;
        Player2.printOppBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();

            string fire = Player1.fire(row,col);

            if(fire == "Miss"){
                std::cout << ("Miss") << std::endl;
                    Player2.updateOppBoard(row,col,"Miss");
                    validInput = true;
            }
            else if(fire == "Hit"){
                std::cout << ("Hit!") << std::endl;
                Player2.updateOppBoard(row,col,"Hit");
                validInput = true;
            }
            else if(fire == "Sunk"){
                std::cout << ("Sunk!") << std::endl;
                Player2.updateOppBoard(row,col,"Hit");
                validInput = true;
            }
            else if(fire == "Error Bounds"){
                 std::cout << ("Out of bounds")<< std::endl;
            }
            else {
                std::cout << ("IDK what happened")<< std::endl;
            }
        }

        if(Player1.gameOver())
            break;
    }

    if(Player1.gameOver())
        std::cout << ("Congrats Player 2, you won") << std::endl;

    if(Player2.gameOver())
        std::cout << ("Congrats Player 1, you won") << std::endl;
}

int Game::getColumn(){
    int shipCol = -1;

    while(shipCol == -1){
        string shipColString;

        std::cout << ("Ship column(A-H): ")<< std::endl;
        cin >> shipColString;



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
    }
    return shipCol;
}

int Game::getRow(){
    int shipRow = -1;
    while(shipRow == -1){
        int tempRow;

        std::cout << ("Ship row(1-8): ")<< std::endl;
        cin >>tempRow;

        if(tempRow > 0 && tempRow <= 8)
            shipRow = tempRow - 1;
    }
    return shipRow;
}
