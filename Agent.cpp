#include "Agent.h"
#include "rnorrexp.c"

// Default Agent Constructor
Agent::Agent(){
}

Agent::Agent(int numb,int avgAge,int dropS, Strategy * s1, Strategy * s2, Strategy * s3){
	strats =new Strategy * [3];
	strats[0]=new Strategy(s1);
	strats[1]=new Strategy(s2);
	strats[2]=new Strategy(s3);
	numbars=numb;
	age=0;
	zigset(time(NULL));
	float a=RNOR;
	a=a*5;
	a=a+avgAge;
	if(avgAge<0)
	{
		
		death=-1;
	}
	else
	{
		
	death=(int) a;
}
	drop=dropS;
	bar=0;
}


/* Precondition: 0 <= numb <= 256
Postcondition: An Agents Strategies has been initialized and 
Description: Initializes an Agents Strategy
*/
Agent::Agent(int numb,int avgAge,int dropS){
	strats =new Strategy*[3];
	strats[0]=new Strategy(numb);
	strats[1]=new Strategy(numb);
	strats[2]=new Strategy(numb);
	numbars=numb;
	age=0;
	zigset(time(NULL));
	float a=RNOR;
	a=a*10;
	a=a+avgAge;
		if(avgAge<0)
		{

			death=-1;
		}
		else
		{

		death=(int) a;
	}
	bar=0;
	drop=dropS;
}

/* Precondition: bars have decided if they  won the current round
Postcondition: Strategies score of agent has been updated appropriately and strategies have been replaced of necessary
Description: this function takes in an array of currents turn bar winners and the current STM, it then uses this information to update
strategy scores and if score drops below predefined threshold the strategy is replaced with another. It then returns needed variables 
to the GUI
*/
Strategy ** Agent::tellWins(int winners[],int STM) {
	int i;
	double t;
	double max=0;
	double sum=0;
	for (i=0;i<3;i++) {
		t=strats[i]->updateScore(winners[strats[i]->getBar(STM)]);
		if(t<drop)
		{
			delete strats[i];
			strats[i]= new Strategy(numbars);
			if(max<10)
			{
				max=10;
			}
		}
	}
	return strats;
}

/* Precondition: A turn has just begun
Postcondition: The Agent successfully decided where they are going for the current turn
Description: This function, using a random number generator, picks a strategy to utilize where he/she is going to bar for current turn 
*/
int Agent::isGoingToBar(int STM)
{
	int i;
	double f = (double)rand() / RAND_MAX;
	f*=(strats[0]->getScore()+strats[1]->getScore()+strats[2]->getScore());
	for(i=0;i<3;i++)
	{
		if((f-=strats[i]->getScore())<=0)
		{
			bar=strats[i]->getBar(STM);
			return strats[i]->getBar(STM);
		}
	}
	age++;
	return -1;
	
}

bool Agent::isDead()
{
	if(death<0)
	{
		return false;
	}
	else if(age>=death)
	{
		return true;
	}
	return false;
}
	
//Agent Class Destructor
Agent::~Agent(){
	delete strats[0];
	delete strats[1];
	delete strats[2];
}


