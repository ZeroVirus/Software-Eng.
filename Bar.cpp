#include "Bar.h"

Bar::Bar(){
}

/* Precondition: A Town has been initialized
Postcondition: maxcapacity variable is initialized for a given bar
Description: Bar Constructor
*/
Bar::Bar(int cap) {
	maxcapacity = cap;
}

/* Precondition: maxcapacity is initialized
Postcondition: None
Description: Returns a bars maxcapacity
*/
int Bar::getBarCapacity() {
	return maxcapacity;
}

/* Precondition:
Postcondition:
Description:
*/
double Bar::wonThisTurn(int peeps) {
	return (((double)peeps)/((double)maxcapacity));
}