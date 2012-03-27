#include <iostream>
#include "Town.h"
#include "Graph.h"
int main(){
	//Mock Simulation
	//1. set up town

	int numBars =30;
	int pop = 16000;
	int *a;
	a= new int[10];
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=1;
	}
	Town *newTown = new Town(10, 20, a);
	graphPtr t=newTown->turn();
	cout<<t->numWinBars<<endl;
	t=newTown->turn();
	cout<<t->numWinBars<<endl;
	t=newTown->turn();
	cout<<t->numWinBars<<endl;
	 system("pause");

	return 0;
}