
  
//import java.util.Scanner;
#include "Game.h"

    
Game::Game(){
        

        Player1 = new GameBoard();
        Player2 = new GameBoard();

        int numShips = -1;
        
        std::cout << ("Welcome to Battleship!") << std::endl;

        while(numShips > 5 || numShips < 1){
            std::cout << ("How many ships would you like to have(1-5): ")<< std::endl;
            cin >> numShips;
        }

        std::cout << (" ")<< std::endl;;
        std::cout << ("Player 1 please place your ships")<< std::endl;;
        placeShips(input, Player1, numShips);
    
        std::cout << ("Player 1's board...")<< std::endl;;
        //Player1.printBoard();

        std::cout << (" ")<< std::endl;;
        std::cout << ("Player 2 please place your ships")<< std::endl;;
        placeShips(input, Player2, numShips);
        std::cout << ("Player 2's board...")<< std::endl;;
        //Player2.printBoard();

        playGame(input, Player1, Player2);

}

void Game::placeShips( GameBoard player, int numShips){
    for(int i = 1; i <= numShips; i++){
        int shipLength = i;
        Ship tempShip = new Ship(shipLength);

        //player.printBoard();

        for(int j = 1; j <= shipLength; j++){
            std::cout << (" ")<< std::endl;;
            std::cout << ("Please place piece " + j + " of " + shipLength)<< std::endl;;

            int shipCol = getColumn(input);
            int shipRow = getRow(input);

            if(tempShip.inline(shipRow, shipCol) && !player.isOccupied(shipRow, shipCol) && !tempShip.containsCoordinate(shipRow, shipCol))
                tempShip.addCoordinates(shipRow,shipCol);
            else
                j--;
        }

        player.addShip(tempShip);
    }
}

void Game::playGame(Scanner input, GameBoard Player1, GameBoard Player2){
    while(!Player1.gameOver() && !Player2.gameOver()){
        int row, col;
        boolean validInput = false;

        std::cout << ("")<< std::endl;;
        std::cout << ("Player 1 please fire")<< std::endl;;
        Player1.printOppBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();
            switch(Player2.fire(row,col)){
                case "Miss":
                    std::cout << ("Miss")<< std::endl;;
                    Player1.updateOppBoard(row,col,"Miss");
                    validInput = true;
                    break;

                case "Hit":
                    std::cout << ("Hit!")<< std::endl;;
                    Player1.updateOppBoard(row,col,"Hit");
                    validInput = true;
                    break;

                case "Sunk":
                    std::cout << ("Sunk!")<< std::endl;;
                    Player1.updateOppBoard(row,col,"Hit");
                    validInput = true;
                    break;

                case "Error Bounds":
                    std::cout << ("Out of bounds")<< std::endl;;
                    break;

                case "Error":
                    std::cout << ("IDK what happened")<< std::endl;;
                    break;
            }
        }
        if(Player2.gameOver())
            break;

        std::cout << ("")<< std::endl;;
        std::cout << ("Player 2 please fire")<< std::endl;;
        Player2.printOppBoard();

        validInput = false;
        while(!validInput){
            col = getColumn();
            row = getRow();
            switch(Player1.fire(row,col)){
                case "Miss":
                    std::cout << ("Miss")<< std::endl;;
                    Player2.updateOppBoard(row,col,"Miss");
                    validInput = true;
                    break;

                case "Hit":
                    std::cout << ("Hit!")<< std::endl;;
                    Player2.updateOppBoard(row,col,"Hit");
                    validInput = true;
                    break;

                case "Sunk":
                    std::cout << ("Sunk!")<< std::endl;;
                    Player2.updateOppBoard(row,col,"Hit");
                    validInput = true;
                    break;

                case "Error Bounds":
                    std::cout << ("Out of bounds")<< std::endl;;
                    break;

                case "Error":
                    std::cout << ("IDK what happened")<< std::endl;;
                    break;
            }
        }

        if(Player1.gameOver())
            break;
    }

    if(Player1.gameOver())
        std::cout << ("Congrats Player 2, you won")<< std::endl;;

    if(Player2.gameOver())
        std::cout << ("Congrats Player 1, you won")<< std::endl;;
}

int Game::getColumn(){
    int shipCol = -1;

    while(shipCol == -1){
        String shipColString;

        std::cout << ("Ship column(A-H): ")<< std::endl;;
        cin >> shipColString;

        switch (shipColString){
            case "A": shipCol = 0; break;
            case "B": shipCol = 1; break;
            case "C": shipCol = 2; break;
            case "D": shipCol = 3; break;
            case "E": shipCol = 4; break;
            case "F": shipCol = 5; break;
            case "G": shipCol = 6; break;
            case "H": shipCol = 7; break;
            default: shipCol = -1; break;
        }
    }
    return shipCol;
}

int Game::getRow(){
    int shipRow = -1;
    while(shipRow == -1){
        int tempRow;

        std::cout << ("Ship row(1-8): ")<< std::endl;;
        cin >>tempRow;

        if(tempRow > 0 && tempRow <= 8)
            shipRow = tempRow - 1;
    }
    return shipRow;
}

}

