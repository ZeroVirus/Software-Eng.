#include "Agent.h"
#include "Strategy.h"
#include "Group.h"
#include "Town.h"
#include "Bar.h"

int main()
{
	int i,j;
	/*Strategy * a;
	for(i=0;i<1000;i++)
	{
		a= new Strategy(5);
		a->getScore();
		a->getBar(20);
		a->updateScore(1);
		delete a;
	}
	cout<<"strat"<<endl;
	int c[]={1,0,1,1,0,1,0,1,1,0};
	Agent * b;
	for(i=0;i<1000;i++)
	{
		b= new Agent(10,0,0);
		b->isGoingToBar(20);
		b->tellWins(c,40);
		b->isDead();
		delete b;
	}
	cout<<"Agent"<<endl;
	Group * d;
	for(i=0;i<1000;i++)
	{
	d=new Group(4,5,0,0);
	d->isGoingToBar(20);
	d->getNumPeeps();
	d->isEmpty();
	delete d;
	}
	cout<<"Group"<<endl;*/
	int g[]={1,2,3,4,5};
	Town * t;
	for(i=0;i<1000;i++)
	{
		t=new Town(5,100,g,true,3,50,50);
		for(j=0;j<1000;j++)
		{
			//cout<<i<<" "<<j<<endl;
			t->turn();
		}
		delete t;
	}
	cout<<"Town"<<endl;
}
