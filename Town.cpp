#include <iostream>
#include <vector>
#include <math.h>
#include "Bar.cpp"

class Town {

protected:
	bool pecentTrue;
	int user_size;
	int user_cap;
	Bar array[];
	int poulation;
	int numpeeps[population];
	
public:
	Town (int numpeople){
		population = numpeople;
	}
	int createBars() {
		Bar *getinfo = new Bar(user_size,user_cap);
		Bar array[getinfo->user_size];
    }
	
	void turn () {
		goingToBar();
		askPercent();
		getWinners();
	}
	
	
	int askPercent ();
	
	int* goingToBar() {
		int i,count;
		Bar *barpeep;
		for (i=0;i<;i++) 
			barpeep[numpeeps[i].isGoingToBar()]++;

		return barpeep;
	}

	void getWinners() {
		int j,countalt;
		for (j=0;j<numpeeps;j++)
			if numpeeps[j].isGoingToBar() == 0
				countalt++;

		if goingToBar() > countalt
			 cout << "Winner is the group not in the bar."
		else
			cout << "Winner is the group in the bar."
	}

};








	


	
