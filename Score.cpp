#include "Score.h"

struct Entry{
    std::string name;
    int score;
};

void Score::AddPlayer(std::string playerName, int points){

        ifstream input;
        input.open("Scoreboard.tri");
        white(input)
        {
            input >> playerName >> points;
            name = playerName;
            score = points;
            scoreboard.push_back(Entry);
        }

        input.close();
}

void Score::Print(){
        for(int i=0; i < scoreboard.size(); i++){
            std::cout << (i+1) << ":\n" << scoreboard[i].name << "\n" << scoreboard[i].score << "\n";
        }
}

void Score::Sort() {
    for(int x=0; x<scoreboard.size(); x++)
    {
        for(int y=0; y<scoreboard.size()-1; y++)
        {
            if(scoreboard[y].score < scoreboard[y+1].score)
            {
                    Entry temporary = scoreboard[y+1];
                    scoreboard[y+1] = scoreboard[y];
                    scoreboard[y] = temporary;
            }
        }
    }
}

void Score::insert(){

  scoreboard.peek()

}

void Score::write()
{
//Entry e;

while(scoreboard.peek().score >>)

}
