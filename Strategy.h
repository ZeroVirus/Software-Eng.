#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy{
public:
	Strategy();
	Strategy(Strategy * s);
	Strategy(int numbars);
	double getScore();
	int getBar(long);
	double updateScore(int);
	int getStrat(int);
	int hash(int);
	int st[2048];
	double score;

};

#endif

