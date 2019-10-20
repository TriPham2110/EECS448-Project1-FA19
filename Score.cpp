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

void Score::printStart(){
	std::cout << "#" << "\t" << "NAME" << "\t" << "WINS"<< "\t" << "Loss" << "\t" << "W/L PERCENT" << "\n";
	
	ten = (scoreboard.size()-1);
	
	if(ten > 10){
		ten = 10;
	}
	for(int i=0; i <= ten; i++){
		std::cout << (i+1) << ":\t" << scoreboard[i].name << "\t" << scoreboard[i].wins << "\t" << scoreboard[i].losses << "\t" << scoreboard[i].percentage << "%\n";
	}
}

void Score::printEnd(){
	std::cout << "#" << "\t" << "NAME" << "\t" << "WINS"<< "\t" << "Loss" << "\t" << "W/L PERCENT" << "\n";
	
	if(ten > 10){
		ten = 10;
	}
	for(int i=0; i <= ten+1; i++){
		std::cout << (i+1) << ":\t" << scoreboard[i].name << "\t" << scoreboard[i].wins << "\t" << scoreboard[i].losses << "\t" << scoreboard[i].percentage << "%\n";
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
	output.open("scoreboard.tri", std::ios_base::app);
	output << std::endl << name << std::endl << "0" << std::endl << "0";
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
