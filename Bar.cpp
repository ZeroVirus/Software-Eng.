#include <iostream>
using namespace std;

class Bar {
	public:
		Bar() {
			size = 254;
			maxcapacity = 66; 
		}
		
		Bar(int numbars, int cap) {
			maxcapacity = cap;
			size = numbars;
		}
		
		int getBarCapacity() {
			return maxcapacity;
		}
		
		int getTotalBars() {
			return size;
		}
		
		bool wonThisTurn(Bar array[]) {
			int i,arr_size=(sizeof(array)/sizeof(array[0]));
			int temp[];
			for (i=0;i<size;i++) {
				
			}
			
		}
		
		int getPeople(int people) {
			return (maxcapacity - people);
		}
		
	private:
		int maxcapacity;
		int size;
};

int main() {
	Bar* a = new Bar(2,3);
	Bar b[a->getTotalBars()];
	cout << a->getTotalBars();
}