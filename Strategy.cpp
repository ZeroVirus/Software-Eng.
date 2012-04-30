#include <iostream>
#include <stdlib.h>
#include "Strategy.h"
using namespace std;


Strategy::Strategy()
{ }
Strategy::Strategy(Strategy * s)
{
	int i;
	for(i=0;i<2048;i++)
	{
		st[i]=s->st[i];
	}
	score=s->score;
}
/* Precondition: 1<= numbars <= 255
Postcondition: int array st that holds Strategies,  
Description: Strategy Constructor that is utilized by Agent class
*/
Strategy::Strategy(int numbars)
{
	int i;
	for(i=0;i<2048;i++)
	{
		st[i]=(int)rand()%numbars;
	}
	score=100;
}

/* Precondition: None
Postcondition: None
Description: Returns a Strategy’s current score
*/
double Strategy::getScore()
{
	return score;
}

//Stolen from http://www.concentric.net/~ttwang/tech/inthash.htm
int Strategy::hash(int key)
{
  key = ~key + (key << 15); // key = (key << 15) - key - 1;
  key = key ^ (key >> 12);
  key = key + (key << 2);
  key = key ^ (key >> 4);
  key = key * 2057; // key = (key + (key << 3)) + (key << 11);
  key = key ^ (key >> 16);
  return key%2048;
}

/* Precondition: None
Postcondition: None
Description: Returns which bar number the Agent will go to for a given round.
*/
int Strategy::getBar(long f)
{
	return st[hash(f)];
}

/* Precondition: None
Postcondition: Private variable “score” is updated.
Description: A strategies previous score is updated for a given turn.
*/
double Strategy::updateScore(int i)
{
	score*=.95;
	score+=(i*10);
	return score;
}


