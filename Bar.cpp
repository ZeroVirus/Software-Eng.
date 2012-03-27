#include "Bar.h"

Bar::Bar(){


}


Bar::Bar(int cap) {
	maxcapacity = cap;
	cout << "maxCapacity of bar : " << maxcapacity << endl;
}
		
int Bar::getBarCapacity() {
	return maxcapacity;
}
		
double Bar::wonThisTurn(int peeps) {
	return (((double)peeps)/((double)maxcapacity));
}