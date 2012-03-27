#ifndef BAR_H
#define BAR_H

#include <iostream>
using namespace std;


class Bar {
	public:
		Bar();
		Bar(int cap);
		int getBarCapacity();
		double wonThisTurn(int peeps);

	private:
		int maxcapacity;
		int size;
};

#endif