#include "Agent.h"



Agent::Agent(){


}

Agent::Agent(int numb){
	if(numb>200)
	{
		exit(1);
	}
	strats[0]=Strategy(numb);
	strats[1]=Strategy(numb);
	strats[2]=Strategy(numb);
	numbars=numb;
	bar=0;
}


double* Agent::tellWins(int winners[],int STM) {
	int i;
	double * rtn;
	rtn=new double[3];
	double t;
	double max=0;
	double sum=0;
	for (i=0;i<3;i++) {
		t=strats[i].updateScore(winners[strats[i].getStrat(STM)]);
		sum+=t;
		if(t<5)
		{
			strats[i]=Strategy(numbars);
			if(max<10)
			{
				max=10;
			}
		}
		else if(t>max)
		{
			max=t;
		}
	}
	rtn[0]=max;
	rtn[1]=(sum/3);
	return rtn;
}

int Agent::isGoingToBar(int STM)
{
	int i;
	double f = (double)rand() / RAND_MAX;
	f*=(strats[0].getScore()+strats[1].getScore()+strats[2].getScore());
	for(i=0;i<3;i++)
	{
		if((f-=strats[i].getScore())<=0)
		{
			bar=strats[i].getStrat(STM);
			if(strats[i].getStrat(STM)>30)
			{
				cout<<"b"<<endl;
			}
			return strats[i].getStrat(STM);
		}
	}
	return -1;
	
}
	


//Agent Class Destructor
Agent::~Agent(){



}