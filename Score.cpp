#include "Score.h"
#include "StringColor.h"

Score::Score(){}

void Score::loadInfo(){
	ifstream input;
	input.open("Scoreboard.tri");
	int numPlayer = 0;
	
	while(input >> name >> wins >> losses){
		scoreboard.push_back(Player());
		
		scoreboard[numPlayer].name = name;
		scoreboard[numPlayer].wins = std::stoi(wins);
		scoreboard[numPlayer].losses = std::stoi(losses);
		
		if(scoreboard[numPlayer].wins == 0 && scoreboard[numPlayer].losses == 0){
			scoreboard[numPlayer].percentage = 0;
		}
		else{
			scoreboard[numPlayer].percentage = 100*(scoreboard[numPlayer].wins)/(scoreboard[numPlayer].wins + scoreboard[numPlayer].losses);
		}
		numPlayer++;
	}
	input.close();
}

void Score::playerAddWin(std::string name){
    
    for(int rep = 0; rep < scoreboard.size(); rep++){
        if(scoreboard[rep].name == name ){
            scoreboard[rep].wins = scoreboard[rep].wins + 1; //add 1 win
            //also update percentages
            scoreboard[rep].percentage = 100*(scoreboard[rep].wins)/(scoreboard[rep].wins + scoreboard[rep].losses);
        }
    }
    
    
    
    
}

void Score::playerAddLoss(std::string name){
    
    for(int rep = 0; rep < scoreboard.size(); rep++){
        if(scoreboard[rep].name == name ){
            scoreboard[rep].losses = scoreboard[rep].losses + 1; //add 1 win
            //also update percentages
            scoreboard[rep].percentage = 100*(scoreboard[rep].wins)/(scoreboard[rep].wins + scoreboard[rep].losses);
        }
    }
    
    
            
}

void Score::print(){
	std::cout << "#" << "\t" << "NAME" << "\t" << "WINS"<< "\t" << "Loss" << "\t" << "W/L PERCENT" << "\n";
	
	ten = (int)(scoreboard.size()-1);
	
	if(ten > 9){
		ten = 9;
	}
	for(int i=0; i <= ten; i++){
        if(scoreboard[i].name.length() > 1){
		  std::cout << (i+1) << ":\t" << scoreboard[i].name << "\t" << scoreboard[i].wins << "\t" << scoreboard[i].losses << "\t" << scoreboard[i].percentage << "%\n";
        }
	}
}

bool Score::playerInScoreboard(std::string name){
	for(int rep=0; rep<(int)scoreboard.size(); rep++){
		if(scoreboard[rep].name == name){
			return true;
		}
	}
    
    
	return false;
}

void Score::addNewPlayer(std::string name){
	ofstream output;
	output.open("Scoreboard.tri", std::ios_base::app);
	output << name << std::endl << "0" << std::endl << "0" << std::endl;
	output.close();
}

void Score::updateFile(){
    //go through file and update changes hehe
    
    std::ofstream ofs;
    ofs.open("Scoreboard.tri", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    
    ofstream output;
	output.open("Scoreboard.tri", std::ios_base::app);
    

    
    
    for(int rep = 0; rep < (int)scoreboard.size(); rep++){
       if(scoreboard[rep].name.length() > 1){
            output << scoreboard[rep].name << endl;
    
            output << std::to_string(scoreboard[rep].wins) << endl;
     
            output << std::to_string(scoreboard[rep].losses)<< endl;;
       }
	  
    }
	output.close();
}

void Score::sort() {
	std::sort(scoreboard.begin(), scoreboard.end(), [](const Player& lhs, const Player& rhs){
		return lhs.percentage > rhs.percentage;
	});
}

void Score::insert(){
	//scoreboard.peek()
}

void Score::write(){
	//Entry e;
}
