#ifndef GROUP_H
#define GROUP_H
#include "Agent.h"

#include <iostream>
#include <cstdlib>

class Group {

public:
	Group();
	Group(int,int);
	Group(int,int,int,int);
	int isGoingToBar(int);
	int getNumPeeps();
	void addAgent(Agent *);
	void addAgent(int,int);
	Strategy ** tellWins(int*,int,int*);
	bool isEmpty(int*);
	int barThisTurn;
	~Group();

protected:
	Agent** peeps;
	int numPeeps;
	int numBars;
	int * LTM;
	int avgAge;
};
#endif
