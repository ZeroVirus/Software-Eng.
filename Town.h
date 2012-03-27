#ifndef TOWN_H
#define TOWN_H

#include "Graph.h"
#include "Bar.h"
#include "Agent.h"
using namespace std;

class Town{
public:
	Town();
	Town(int number_bars,int population,int user_cap[],bool isPercent);
	void createBars(int numbars,int user_cap[],bool isPercent);
	void createAgents(int population);
	graphPtr turn();
	int* goingToBar();
	int* getWinners(int a[256]);
	void tellWinners(int a[256]);
	~Town();

protected:
	int user_size, numbars, numpeeps;
	Bar barnums[256];
	Agent people[16348];
	int STM[3];
	int ST;
	graphPtr stuff;
};

#endif