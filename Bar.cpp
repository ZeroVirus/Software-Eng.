#include <iostream>
using namespace std;

class Bar {
	public:
		Bar(int cap) {
			maxcapacity = cap;
		}
		
		int getBarCapacity() {
			return maxcapacity;
		}
		
		double wonThisTurn(int peeps) {
		
			return peeps/maxcapacity;
		}

	private:
		int maxcapacity;
		int size;
};

