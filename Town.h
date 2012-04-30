#ifndef TOWN_H
#define TOWN_H

#include "Graph.h"
#include "Bar.h"
#include "Group.h"
#include <list>
using namespace std;

class Town{
public:
	Town();
	Town(int,int,int[],bool,int,int,int);
	void createBars(int numbars,int* user_cap,bool isPercent);
	void createGroups(int population,int numGrps,int avgAge,int dropValue);
	graphPtr turn();
	int* goingToBar();
	int* getWinners(int *a);
	void tellWinners(int *a);
	int popcontrol();
	~Town();

protected:
	int numbars, numgroups;
	int grpSize,numpeeps,drop;
	Bar ** barnums;
	list<Group *> groups;
	list<Group *>::iterator it;
	Strategy ** topStrats;
	list<Strategy *>::iterator it2;
	int *STM;
	int STI;
	int avgAge;
	graphPtr stuff;
};

#endif
