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

double updateScore(int i)
{
	score*=.95;
	score+=i;
	return score;
}

int getStrat(int shortterm) {
	return (int) st[shortterm%2048];
}
	
~Strategy::Strategy();
	
private:
	int st[2048];
	double score;



};