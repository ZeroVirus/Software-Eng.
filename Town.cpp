#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Town.h"

//Default Town Constructor
Town::Town()
{
}

/*
Precondition: The parameters are initialized within the following constraints: 
1 <=  number_bars <= 255 and 1<= population <=16348 (2^14) and user_cap is the 
array for the capacity for each bar ( whose size may exceed the population.)
Postcondition: Barnums array and people array initialized as well as STM array
which keeps track which bar has won.
Description: Town Constructor which creates the Bars and Agents using inputted 
parameters by the createBars() and createAgents() functions
*/
Town::Town(int number_bars,int population,int user_cap[],bool isPercent,int grpSize,int avgAge2,int dropValue) {
		avgAge=avgAge2;
		numbars= number_bars+1;
		numpeeps=population;
		int i;
		STM=new int[3];
		for (i=0;i<3;i++) {
			STM[i] = rand()%numbars;
		}
		barnums=(Bar **)malloc(sizeof(Bar)*numbars);
		createBars(numbars, user_cap, isPercent);
		createGroups(population,grpSize,avgAge,dropValue);
		stuff=new struct pass_graph;
		
		topStrats=(Strategy **)malloc(sizeof(Strategy*)*20);
		drop=dropValue;
	}

/* Precondition: 1 <= numbars <= 255
Postcondition: Bar array barnums[] has been initialized
Description: The Bar array barnums[] is initialized and bar[0] is the
normalizing home location that if the population is greater 
than the sum of all “user_cap[]”s, then bar [0] gets the value of population - SUM(user_cap[])
*/
void Town::createBars(int numbars,int user_cap[],bool isPercent) {
		int i,j;
		int temp=0;
		for (i=0;i<(numbars-1);i++) {
			j=(isPercent?((numpeeps*user_cap[i])/100):user_cap[i]);
			barnums[i+1] = new Bar(j);
			temp+=j;
		}
		barnums[0]= new Bar((numpeeps>temp?numpeeps-temp:0));
    }

/* Precondition: 1<= population <= 16348 (2^14)
Postcondition: Agent array people[] is initialized and holds all initialized Agents in the population
Description: Populates Agent array people[] with initialized Agent Objects.
*/
void Town::createGroups(int population,int grpSize,int avgAge,int dropValue) {
		int q=(int)(population/grpSize);
		int q2=population%grpSize;
		int i;
		for(i=0;i<q;i++)
		{
			groups.push_back(new Group(grpSize,numbars,avgAge,dropValue));
		}
		groups.push_back(new Group(grpSize,numbars));
		Group * y=groups.back();
		for(i=0;i<q2;i++)
		{
			y->addAgent(avgAge,dropValue);
		}
	}
	
/* Precondition: Input parameters have been passed from the GUI and have initialized all appropriate instances.
Postcondition: One turn has passed, all parameters have been updated and recorded.
Description: One turn is simulated when turn() is run.
*/
graphPtr Town::turn() {
		STI = (int)(pow((double)STM[2],3)+pow((double)STM[1],2)+STM[0]);
		//cout<<ST<<endl;
		int* a;
		a=new int[256];
		a= goingToBar();
		a=getWinners(a);
		tellWinners(a);
		popcontrol();
		return stuff;
	}

/* Precondition: All necessary variables are set and a simulation is underway
Postcondition: Returns a pointer to an array which holds counters for how many 
Agents are going to a particular bar for a given turn
Description: Polls all the agents of which bar they are going to and populates 
an array which keeps track of this.
*/
int* Town::goingToBar() {
		int i,j;
		j=0;
		int * barpeople;
		barpeople=new int[numbars];
		for(i=0;i<numbars;i++)
		{
			barpeople[i]=0;
		}
		for ( it=groups.begin() ; it != groups.end(); it++ )
		{
			j=(*it)->isGoingToBar(STI);
			barpeople[j]+=(*it)->getNumPeeps();
		}
		return barpeople;
		}


int Town::popcontrol()
{
		int * g=(int*)malloc(sizeof(int));
		(*g)=0;
		for ( it=groups.begin() ; it != groups.end(); it++ )
		{
			if((*it)->isEmpty(g))
			{
				delete (*it);
				it=groups.erase(it);
				it--;
			}
		}
		int x=*g;
		free(g);
		Group * a=groups.back();
		while(x)
		{
			while(a->getNumPeeps()!=grpSize)
			{
				a->addAgent(new Agent(numbars,avgAge,drop,topStrats[rand()%20],topStrats[rand()%20],topStrats[rand()%20]));
				x--;
				if(!x)
				{
					break;
				}
			}
			groups.push_back(new Group(grpSize,numbars));
			a=groups.back();
		}

}


/* Precondition: Input is an int array which contains 1s's where bars won 
and 0's where bars lost
Postcondition: Bars that have won for a particular round have been acknowledged
and updated
Description: Function updates the STM to add current turn data. Also populates
Stuff structure to pass back to the GUI for graph output
*/
int* Town::getWinners(int a[]){
		int j;
		double k;
		int minAt = 0;
		double min=1;
		int* rtn;
		int winBars=0;
		double winpeeps=0;
		rtn=new int[numbars];
		for(j=0;j<numbars;j++)
		{
			rtn[j]=0;
		}
		for (j=0;j<numbars;j++)
		{
			k=barnums[j]->wonThisTurn(a[j]);
			if(k<=1)
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
		stuff->numWinners=(int)winpeeps;
		return rtn;
}

/* Precondition: The array that holds valid bars for the current simulation has been populated
Postcondition: stuff has been populated
Description: Function goes through the population and tells an agent they have either won or
lost the current round. Also populates Stuff structure to pass back to the GUI for graph output
*/
void Town::tellWinners(int a[256]) {
	int i,j;
	int* k=(int*)malloc(sizeof(int));
	int q=0;
	int h=0;
	double max=0;
	double average=0;
	double minmax=200;
	int minmaxat=0;
	Strategy ** temp;
	list<Group*>::iterator it;
	for ( it=groups.begin() ; it != groups.end(); it++ )
	{
		temp=(*it)->tellWins(a,STI,k); //returns array of graph data
		for(i=0;i<*k;i++)
		{
			average+=temp[i]->getScore();
			h++;
			if(q<20)
			{
				topStrats[q]=temp[i];
				if(temp[i]->getScore()<minmax)
				{
					minmax=temp[i]->getScore();
					minmaxat=q;
				}
				q++;
			}
			else
			{
				if(temp[i]->getScore()<minmax)
				{
					topStrats[minmaxat]=temp[i];
					minmax=200;
					minmaxat=0;
					for(j=0;j<20;j++)
					{
						if(topStrats[j]->getScore()<minmax)
						{
							minmax=temp[i]->getScore();
							minmaxat=j;
						}
					}
				}
			}
			if(temp[i]->getScore()>max)
			{
				max=temp[i]->getScore();
			}
		}
	}
	average/=h;
	stuff->avgStratScore=average;
	stuff->bestStratScore=max;
}

Town::~Town()
{
	int i;
	for(i=0;i<numbars;i++)
	{
		delete barnums[i];
	}
	free(barnums);
	free(topStrats);
}

