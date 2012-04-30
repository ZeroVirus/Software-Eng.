#include "Group.h"

Group::Group()
{
	
}

Group::Group(int nump,int numb)
{
	numPeeps=0;
	numBars=numb;
	peeps = (Agent **) malloc(sizeof(Agent*)*nump);
	LTM=(int*)malloc(sizeof(int)*(numb));
	int i;
	for(i=0;i<numb;i++)
	{
		LTM[i]=0;
	}
	for(i=0;i<nump;i++)
	{
		peeps[i]=(Agent *)0;
	}
}

Group::Group(int nump,int numb,int avgAge,int drop)
{
	numPeeps=nump;
	numBars=numb;
	peeps = (Agent **) malloc(sizeof(Agent*)*nump);
	LTM=(int*)malloc(sizeof(int)*numb);
	int i;
	for(i=0;i<numb;i++)
	{
		LTM[i]=0;
	}
	for(i=0;i<nump;i++)
	{
		peeps[i]=new Agent(numb,avgAge,drop);
	}
}

int Group::isGoingToBar(int STI)
{
	int* temp=(int*)malloc(sizeof(int*)*numBars);
	int i;
	for(i=0;i<numBars;i++)
	{
		temp[i]=0;
	}
	for(i=0;i<numPeeps;i++)
	{
		temp[peeps[i]->isGoingToBar(STI)]++;
	}
	int max=0;
	int* maxAt=(int*)malloc(sizeof(int)*numBars);
	int h=1;
	for(i=0;i<numBars;i++)
	{
		if(temp[i]>max)
		{
			h=1;
			max=temp[i];
			maxAt[0]=i;
		}
		else if(temp[i]==max)
		{
			maxAt[h]=i;
			h++;
		}
	}
	int l=0;
	if(h==1)
	{
		l= maxAt[0];
	}
	else
	{
		max=0;
		int h2=1;
		int* maxAt2=(int*)malloc(sizeof(int)*h);
		for(i=0;i<h;i++)
		{
			cout<<maxAt[i]<<endl;
			if(LTM[maxAt[i]]>max)
			{
				h2=1;
				max=LTM[maxAt[i]];
				maxAt2[0]=i;
			}
			else if(LTM[maxAt[i]]==max)
			{
				maxAt2[h2]=i;
				h2++;
			}
		}
		if(h2==1)
		{
			l= maxAt2[0];
		}
		else
		{
			l= maxAt2[rand()%h2];
		}
		free(maxAt2);
	}
	
	free(maxAt);
	free(temp);
	barThisTurn=l;
	return l;
}

int Group::getNumPeeps()
{
	return numPeeps;
}

void Group::addAgent(int avgAge,int drop)
{
	peeps[numPeeps]=new Agent(numBars,avgAge,drop);
	numPeeps++;
}

void Group::addAgent(Agent* f)
{
	peeps[numPeeps]=f;
	numPeeps++;
}

Strategy ** Group::tellWins(int* a,int b,int* g)
{
	int i,q;
	Strategy ** rtn = new Strategy*[3*numPeeps];
	Strategy ** temp;
	for(i=0;i<numPeeps;i++)
	{
		temp=peeps[i]->tellWins(a,b);
		for(q=0;q<3;q++)
		{
			rtn[i*3+q]=temp[q];
		}
	}
	(*g)=numPeeps*3;
	if (a[barThisTurn]) {
		LTM[barThisTurn]++;
	}
	else {
	LTM[barThisTurn]--:;
	}
	return rtn;
}

bool Group::isEmpty(int * g)
{
	int i;
	for(i=0;i<numPeeps;i++)
	{
		if(peeps[i]->isDead())
		{
			delete peeps[i];
			peeps[i]=peeps[numPeeps-1];
			peeps[numPeeps-1]=0;
			(*g)++;
			i--;
			numPeeps--;
		}
	}
	if(numPeeps==0)
	{
		return true;
	}
	return false;
}

Group::~Group()
{
	int i;
	for(i=0;i<numPeeps;i++)
	{
		delete peeps[i];
	}
	free(peeps);
	free(LTM);
}
