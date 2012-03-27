#include <iostream>
#include <stdlib.h>
#include "Strategy.h"
using namespace std;


Strategy::Strategy()
{ }

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
	score=10;
	
}

/* Precondition: None
Postcondition: None
Description: Returns a Strategy’s current score
*/
double Strategy::getScore()
{
	return score;
}

/* Precondition: None
Postcondition: None
Description: Returns which bar number the Agent will go to for a given round.
*/
int Strategy::getBar(long f)
{
	return st[f%2048];
}

/* Precondition: None
Postcondition: Private variable “score” is updated.
Description: A strategies previous score is updated for a given turn.
*/
double Strategy::updateScore(int i)
{
	score*=.95;
	score+=i;
	return score;
}

/* Precondition: 0 < shortterm <= 254^4 - 1
Postcondition: Returns which strategy number(0,1,2) the Agent is going to utilize.
Description: Gets either strategy 0 1 of 2 because each Agent has 3 strategies to choose from.
*/
int Strategy::getStrat(int shortterm) {
	return (int) st[shortterm%2048];
}