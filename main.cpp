#include <iostream>
#include "Game.h"
#include <string>

#include "StringColor.h"

    


int main(){
    
    std::string heath = StringColor::YELLOW;
    
    for(int rep = 0; rep<200; rep++){
        std::cout << StringColor::YELLOW << " POOR YORICK ";
       // if(rep%10 == 0)
          //  std::cout << std::endl;
        
    }
    std::cout << std::endl;
    
    
    
    Game g;
}

