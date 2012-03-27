#include <iostream>
#include <stdlib.h>

#include "Town.h"

//Default Town Constructor
Town::Town()
{
}

/*
Precondition: The parameters are initialized within the following constraints: 1 <=  number_bars <= 255 and 1<= population <=16348 
(2^14) and user_cap is the array for the capacity for each bar ( whose size may exceed the population.)
Postcondition: Barnums array and people array initialized as well as STM array which keeps track which bar has won.
Description: Town Constructor which creates the Bars and Agents using inputted parameters by the createBars() and createAgents() functions
*/
Town::Town(int number_bars,int population,int user_cap[]) {
	numbars=number_bars;
		numpeeps=population;
		int i;
		for (i=0;i<3;i++) {
			STM[i] = rand()%numbars;
		}
		createBars(numbars, user_cap);
		createAgents( population);
		stuff=new struct pass_graph;
		stuff->numWinners=0;
	}

/* Precondition: 1 <= numbars <= 255
Postcondition: Bar array barnums[] has been initialized
Description: The Bar array barnums[] is initialized and bar[0] is the normalizing home location that if the population is greater 
than the sum of all “user_cap[]”s, then bar [0] gets the value of population - SUM(user_cap[])
*/
void Town::createBars(int numbars,int user_cap[]) {
		int i;
		int temp=0;
		for (i=0;i<numbars;i++) {
			barnums[i+1] = Bar(user_cap[i]);
			temp+=user_cap[i];
		}
		barnums[0]= Bar((numpeeps>temp?numpeeps-temp:0));
    }

/* Precondition: 1<= population <= 16348 (2^14)
Postcondition: Agent array people[] is initialized and holds all initialized Agents in the population
Description: Populates Agent array people[] with initialized Agent Objects.
*/
void Town::createAgents(int population) {
		int i;
		int count = 0;
		for (i=0;i<numpeeps;i++) {
			people[i] = Agent(population);
			++count;
		}
		if(count == population){
		}
	}
	
/* Precondition: Input parameters have been passed from the GUI and have initialized all appropriate instances.
Postcondition: One turn has passed, all parameters have been updated and recorded.
Description: One turn is simulated when turn() is run.
*/
graphPtr Town::turn() {
		ST = (int)(pow((double)STM[2],3)+pow((double)STM[1],2)+STM[0]);
		int* a;
		a=new int[256];
		a= goingToBar();
		
		a=getWinners(a);
		tellWinners(a);
		return stuff;
	}

/* Precondition: All necessary variables are set and a simulation is underway
Postcondition: Returns a pointer to an array which holds counters for how many Agents are going to a particular bar for a given turn
Description: Polls all the agents of which bar they are going to and populates an array which keeps track of this.
*/
int* Town::goingToBar() {
		int i;
		int * barpeople;
		barpeople=new int[256];
		for(i=0;i<256;i++)
		{
			barpeople[i]=0;
		}
		for (i=0;i<numpeeps;i++) 
		{
			barpeople[people[i].isGoingToBar(ST)]++;
		}
		return barpeople;
	}

/* Precondition: 
Postcondition: Agents that have won for a particular round have been acknowledged and updated
Description:
*/
int* Town::getWinners(int a[]){
		int j;
		double k;
		int minAt = 0;
		double min=1;
		int* rtn;
		int winBars=0;
		double winpeeps=0;
		rtn=new int[256];
		for (j=0;j<numbars;j++)
		{
			k=barnums[j].wonThisTurn(a[j]);
			if(k<1)
			{
				rtn[j]=1;
				winBars++;
				stuff->barCompare[j]=true;
				winpeeps+=a[j];
				if(k<min)
				{
					min=k;
					minAt=j;
				}
			}
			else
			{
				rtn[j]=0;
				stuff->barCompare[j]=false;
			}
		}
		STM[2]=STM[1];
		STM[1]=STM[0];
		STM[0]=minAt;
		stuff->numWinBars=winBars;
		stuff->numWinners=winpeeps;
		return rtn;
}

/* Precondition: The array that holds valid bars for the current simulation has been populated
Postcondition: stuff has been populated
Description: Function goes through the population and tells an agent they have either won or
lost the current round. Also populates Stuff structure to pass back to the GUI for graph output
*/
void Town::tellWinners(int a[256]) {
	int i;
	double max=0;
	double average=0;
	double* temp;
	for (i=0;i<numpeeps;i++) 
	{
		temp=people[i].tellWins(a,ST);
		average+=temp[1];
		if(temp[0]>max)
		{
			max=temp[0];
		}
	}
	average/=numpeeps;
	stuff->avgStratScore=average;
	stuff->bestStratScore=max;
}