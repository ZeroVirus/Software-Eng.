#include <iostream>
#include <vector>
#include <math.h>
#include "Bar.cpp"
#include <stdlib.h>

class Town {

struct pass_graph {
	int numWinBars;
	int numWinners;
	double avgStratScore;
	double bestStratScore;
	bool barCompare[256];
};

typedef struct pass_graph* graphPtr; 
protected:
	int user_size,numbars,numpeeps,population;
	Bar barnums[256];
	Agent people[16348];
	int STM[3];
	int ST;
	
public:

	Town(int number_bars,int population,int user_cap[]) {
		numbars=number_bars;
		numpeeps=population;
		int i,j,k;
		for (i=0;i<3;i++) {
			STM[i] = rand()%numbars;
		}
		createBars(int numbars,int user_cap[]);
		createAgents(int population);
	}

	void createBars(int numbars,int user_cap[]) {
		int i;
		int temp=0;
		for (i=0;i<numbars;i++) {
			barnums[i+1] = new Bar(user_cap[i]);
			temp+=user_cap[i];
		}
		barnums[0]=new Bar((numpeeps>temp?numpeeps-temp:0));
    }

	void createAgents(int population) {
		int i;
		for (i=0;i<population;i++) {
			people[i] = new Agent(numbars);
		}
	}
	
	struct  turn () {
		ST=pow(STM[2],3)+pow(STM[1],2)+STM[0];
		int a[256]=goingToBar();
		a=getWinners(a);
		tellWinners(a);
	}
	
	int* goingToBar() {
		int i,count;
		int barpeople[256];
		for (i=0;i<population;i++) 
			barpeople[people[i].isGoingToBar(ST)]++;

		return barpeople;
	}

	int* getWinners(int[] a) {
		int j,countalt;
		double k;
		int minAt=0;
		double min=1;
		int rtn[256];
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

void tellWinners(int a[256]) {
	int i;
	for (i=0;i<population;i++) 
		people[i].tellWins(a,ST);
}
};








	


	
