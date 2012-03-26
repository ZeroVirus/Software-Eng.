#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Town.cpp"
using namespace std;

class Agent : public Town {

public:
	Agent(int a);
	
	bool getIsGoingToBar();
	void agentDecision();
	
	void setPercentDown();
	void setPercentUp();
	float getPercent();
	int num_wins();

	~Agent();

protected:
	int bar;
	Strategy strats[3];
	int wins;

};