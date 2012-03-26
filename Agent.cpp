#include "Agent.h"

//PRE: none
//POST: Agent object created
//Des: Default Constructor
Agent::Agent(int numbars){
	strats[0]=new Strategy(numbars);
	strats[1]=new Strategy(numbars);
	strats[2]=new Strategy(numbars);
	bar=0;
}


//PRE: called before the round is started
//POST: bar boolean set
//Des: Depending on the agents current attendencePercent 
//		this function decides if Agent will attend the
//		a given round
void Agent::agentDecision(){
	
	int percentage;
	/* initialize random seed: */
	srand ( time(NULL) );
	/* generate number from 1 to 100: */
	percentage = rand() % 100 + 1;

	// EX
	// attendencePercent = 82, then 1< x < 82 to have that 
	// amount of chance to land in that range.
	if(percentage > attendencePercent)
		bar = false;
	if(percentage < attendencePercent)
		bar = true;

}

//PRE: none
//POST: returns the Agents status 
//Des: get function
bool Agent::getIsGoingToBar(){
	agentDecision();
	return bar;
}

void changePercent(bool b)
{
	if(b^bar)
	{
		if(bar)
		{
			attendencePercent+=DELTA;
		}
		else
		{
			attendencePercent-=.01;
		}
	}	
	
}

void tellWinners()
	
}

//Agent Class Destructor
Agent::~Agent(){


}