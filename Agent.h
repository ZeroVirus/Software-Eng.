#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cstdlib>
#include "Strategy.h"
using namespace std;

class Agent {

public:
	Agent();
	Agent(int a);
	
	int isGoingToBar(int STM);
	void tellWins(int winners[],int STM);
	~Agent();

protected:
	Strategy strats[3];

};

#endif