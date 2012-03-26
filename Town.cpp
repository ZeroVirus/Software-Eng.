#include <iostream>
#include <vector>
#include <math.h>
#include "Bar.cpp"
#include <stdlib.h>

class Town {

protected:
	int user_size,user_cap,numbars,numpeeps,population;
	Bar barnums[256];
	Agent people[16348];
	int STM[3];
	
public:

	Town(int number_bars,int population,int user_cap[]) {
		numbars=number_bars;
		numpeeps=population;
		int i,j,k;
		for (i=0;i<3;i++) {
			STM[i] = rand()%numbars;
		}
	}

	void createBars(int numbars,int user_cap[]) {
		int i;
		for (i=0;i<numbars;i++) {
			barnums[i] = new Bar(user_cap[i]);
		}
    }

	void createAgents(int population) {
		int i;
		for (i=0;i<population;i++) {
			people[i] = new Agent(numbars);
		}
	}

	int* clearBar() {
		int i;
		for (i=0;i<)
	}
	
	void turn () {
		clearBar();
		goingToBar();
		getWinners();
	}
	
	int* goingToBar() {
		int i,count;
		int barpeople[256];
		for (i=0;i<256;i++) 
			barpeople[numpeeps[i].isGoingToBar()]++;

		return barpeople;
	}

	void getWinners() {
		int j,countalt;
		for (j=0;j<numpeeps;j++)
			if numpeeps[j].isGoingToBar() == 0
				countalt++;

};








	


	
