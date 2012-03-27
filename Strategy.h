#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy{
public:
	Strategy();
	Strategy(int numbars);
		double getScore();
		int getBar(long f);
		double updateScore(int i);
		int getStrat(int shortterm);

private:
	int st[2048];
	double score;

};

#endif