#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cstdlib>
#include "Strategy.h"
using namespace std;

class Agent {

public:
	Agent();
	Agent(int,int,int);
	Agent(int numb,int avgAge,int drop, Strategy * s1, Strategy * s2, Strategy * s3);
	int isGoingToBar(int);
	Strategy ** tellWins(int[],int);
	bool isDead();
	~Agent();

protected:
	Strategy** strats;
	int numbars,bar,age,death,drop;
};

#endif

