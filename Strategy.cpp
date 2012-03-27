#include <iostream>
#include <stdlib.h>
#include "Strategy.h"
using namespace std;


Strategy::Strategy()
{

}
	
Strategy::Strategy(int numbars)
{
	for(int i=0;i<2048;i++)
	{
		st[i]=(int)rand()%numbars;
	}
	score=10;
	
}

double Strategy::getScore()
{
	return score;
}

int Strategy::getBar(long f)
{
	return st[f%2048];
}

void Strategy::updateScore(int i)
{
	score*=.95;
	score+=i;
	return;
}

int Strategy::getStrat(int shortterm) {
	return (int) st[shortterm%2048];
}