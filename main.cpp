#include <iostream>
#include "Town.h"

int main(){
	//Mock Simulation
	//1. set up town

	int numBars =3;
	int pop = 1001;
	int *user_BarCap;
	user_BarCap= new int[160000000];

	Town *newTown = new Town(numBars, pop, user_BarCap);
	system("pause");



	return 0;
}