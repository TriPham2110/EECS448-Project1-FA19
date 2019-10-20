#include "Score.h"
#include "StringColor.h"


Score::Score(){
}

void Score::loadInfo(){

        ifstream input;
        input.open("Scoreboard.tri");
        int numPlayer = 0;
    
        while(input)
        {
            
            
            input >> name >> wins >> losses;
            
            
            scoreboard.push_back(Player());
            
            scoreboard[numPlayer].name = name;
            scoreboard[numPlayer].wins = stoi(wins);
            scoreboard[numPlayer].losses = stoi(losses);
            scoreboard[numPlayer].percentage = 100*(scoreboard[numPlayer].wins)/((scoreboard[numPlayer].wins) + scoreboard[numPlayer].losses);
            
            
            numPlayer++;
        }

        input.close();
}

void Score::print(){
    this->sort();
    std::cout << "#" << "\t" << "NAME" << "\t" << "WINS"<< "\t" << "Loss" << "\t" << "W/L PERCENT" << "\n";
    
        int ten = (scoreboard.size()-1);
    
        if(ten > 10)
            ten = 10;
    
        for(int i=0; i < ten; i++){
            std::cout << (i+1) << ":\t" << scoreboard[i].name << "\t" << scoreboard[i].wins << "\t" << scoreboard[i].losses << "\t" << scoreboard[i].percentage << "%\n";
        }
}

bool Score::playerInScoreboard(std::string name){
    for(int rep=0; rep<scoreboard.size(); rep++){
        if(scoreboard[rep].name == name)
            return true;
    }
    return false;
}

void Score::addNewPlayer(std::string name){
    ofstream output;
    output.open("scoreboard.tri");
    
    output << name << "0" << "0";
    
    output.close();
}

void Score::sort() {
    for(int x=0; x<scoreboard.size(); x++)
    {
        for(int y=0; y<scoreboard.size()-1; y++)
        {
            if(scoreboard[y].percentage < scoreboard[y+1].percentage)
            {
                    Player temporary = scoreboard[y+1];
                    scoreboard[y+1] = scoreboard[y];
                    scoreboard[y] = temporary;
            }
        }
    }
}

void Score::insert(){

  //scoreboard.peek()

}

void Score::write()
{
//Entry e;


}
