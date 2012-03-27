#include <iostream>
#include <stdlib.h>

#include "Town.h"

Town::Town(int number_bars,int population,int user_cap[]) {
		numbars=number_bars;
		cout << "numBars: " << numbars << endl;
		numpeeps=population;
		cout << "numPeeps: " << numpeeps << endl;
		int i;
		for (i=0;i<3;i++) {
			STM[i] = rand()%numbars;
		}
		createBars(numbars, user_cap);
		createAgents( population);
	}

void Town::createBars(int numbars,int user_cap[]) {
		int i;
		int temp=0;
		for (i=0;i<numbars;i++) {
			barnums[i+1] = Bar(user_cap[i]);
			temp+=user_cap[i];
		}
		barnums[0]= Bar((numpeeps>temp?numpeeps-temp:0));
    }

void Town::createAgents(int population) {
		int i;
		int count = 0;
		for (i=0;i<population;i++) {
			people[i] = Agent(numbars);
			++count;
		}
		if(count == population){
			cout << "Successfully created " << population << " new Agents." <<endl;
		}
	}
	
graphPtr Town::turn() {
		cout << "Turn function started" << endl;
		ST = (int)(pow((double)STM[2],3)+pow((double)STM[1],2)+STM[0]);
		int* a;
		a=new int[256];
		a= goingToBar();
		a=getWinners(a);
		tellWinners(a);
		return NULL;
	}


int* Town::goingToBar() {
		int i;
		int * barpeople;
		barpeople=new int[256];
		for (i=0;i<population;i++) 
			barpeople[people[i].isGoingToBar(ST)]++;

		return barpeople;
	}

int* Town::getWinners(int a[]){
		int j;
		double k;
		int minAt = 0;
		double min=1;
		int* rtn;
		rtn=new int[256];
		for (j=0;j<256;j++)
		{
			k=barnums[j].wonThisTurn(a[j]);
			if(k<1)
			{
				rtn[j]=1;
				if(k<min)
				{
					min=k;
					minAt=j;
				}
			}
			else
			{
				rtn[j]=0;
			}
		}
		STM[2]=STM[1];
		STM[1]=STM[0];

		STM[0]=minAt;
		
		return rtn;
}

void Town::tellWinners(int a[256]) {
	int i;
	for (i=0;i<population;i++) 
		people[i].tellWins(a,ST);
}