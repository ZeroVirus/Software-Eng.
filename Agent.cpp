#include "Agent.h"
#include "Strategy.cpp"

Agent::Agent(int numbars){
	strats[0]=new Strategy(numbars);
	strats[1]=new Strategy(numbars);
	strats[2]=new Strategy(numbars);
	bar=0;
}

void tellWinners(int winners[],int STM) {
	int i;
	for (i=0;i<3;i++) {
		if (winners[st[i].getStrats(STM)])
	}
}
	


//Agent Class Destructor
Agent::~Agent(){


}