#include <iostream>
#include <stdlib.h>
#include "Agent.h"
using namespace std;

class Strategy {
	
Strategy(int numbars)
{
	for(int i=0;i<2048;i++)
	{
		st[i]=(int)rand()%numbars;
	}
	score=10;
	
}

double getScore()
{
	return score;
}

int getBar(long f)
{
	return st[f%2048];
}

void updateScore(bool i)
{
	score*=.95;
	score+=i;
	return;
}

int getStrat(int shortterm) {
	return 
}

	
private:
	int st[2048];
	double score;


};