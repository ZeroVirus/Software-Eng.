#include "Agent.h"



Agent::Agent(){


}

Agent::Agent(int numbars){
	/*strats[0]=Strategy(numbars);
	strats[1]=Strategy(numbars);
	strats[2]=Strategy(numbars);*/
}


void Agent::tellWins(int winners[],int STM) {
	int i;
	for (i=0;i<3;i++) {
		strats[i].updateScore(winners[strats[i].getStrat(STM)]);
			
		
	}
}

int Agent::isGoingToBar(int STM)
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