#include <iostream>
#include <vector>
#include <math.h>
#include <Agent.h>

class Town {
private:
	vector<Agent *> numpeeps;
	double BarCapacity;
	boolean pecentTrue;
public:
	void turn ();
	static int goingToBar ();
	static void getWinners ();
	int askPercent ();
};

void turn () {
	goingToBar();
	askPercent();
	getWinners();
}

static int goingToBar () {
	int i,count;
	for (i=0;i<numpeeps.max_size();i++) 
		if numpeeps[i].isGoingToBar() == 1 
			count++; 

	return count;
}

staic void getWinners() {
	int j,countalt;
	for (j=0;j<numpeeps;j++)
		if numpeeps[j].isGoingToBar() == 0
			countalt++;
	
	if goingToBar() > countalt
		 cout << "Winner is the group not in the bar."
	else
		cout << "Winner is the group in the bar."
}

int[] askPercent {
	int popper[1];
	popper[0]=(goingToBar()/numpeeps.max_size())*100;
	popper[1]=((numpeeps.max_size() - goingToBar())/*100;
	return popper;
}


	


	
