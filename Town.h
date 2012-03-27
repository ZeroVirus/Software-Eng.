#ifndef TOWN_H
#define TOWN_H

#include "Graph.h"
#include "Bar.h"
#include "Agent.h"
using namespace std;

class Town{
public:
	Town();
	Town(int number_bars,int population,int user_cap[]);
	void createBars(int numbars,int user_cap[]);
	void createAgents(int population);
	graphPtr turn();
	int* goingToBar();
	int* getWinners(int a[256]);
	void tellWinners(int a[256]);

protected:
	int user_size, numbars, numpeeps, population;
	Bar barnums[256];
	Agent people[16348];
	int STM[3];
	int ST;

};

#endif