#include "Agent.h"
#include "Strategy.cpp"

Agent::Agent(int numbars){
	strats[0]=new Strategy(numbars);
	strats[1]=new Strategy(numbars);
	strats[2]=new Strategy(numbars);
	bar=0;
}

void createStrats()

void tellWins(int winners[],int STM) {
	int i;
	for (i=0;i<3;i++) {
		strats[i].updateScore(winners[strats[i].getStrat(ST)]);
			
		
	}
}
	


//Agent Class Destructor
Agent::~Agent(){



}