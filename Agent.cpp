#include "Agent.h"
#include "Strategy.cpp"

Agent::Agent(int numbars){
	strats[0]=new Strategy(numbars);
	strats[1]=new Strategy(numbars);
	strats[2]=new Strategy(numbars);
	bar=0;
}

void tellWins(int winners[],int STM) {
	int i;
	for (i=0;i<3;i++) {
		if((strats[i].updateScore(winners[strats[i].getStrat(ST)]))<5)
		{
			delete strats[i];
			strats[i]=new Strategy(numbars);
		}
	}
}

int isGoingToBar(int STM)
{
	int i;
	double f = (double)rand() / RAND_MAX;
	f*=(strats[0].getScore()+strats[1].getScore()+strats[2].getScore());
	for(i=0;i<3;i++)
	{
		if((f-=strats[i].getScore())<=0)
		{
			return strats[i].getStrat(STM);
		}
	}
	return -1;
	
}
	


//Agent Class Destructor
Agent::~Agent(){



}