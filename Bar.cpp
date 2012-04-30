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

/* Precondition: The number of Agents going to this specific bar has been decided.
Postcondition: The outcome of this bar(bar has won/lost) has been decided
Description: Using division, we divide the number of people going to this bar by 
the bars maxcapacity in order return a number that shows what the bars capacity ratio
was for a specific round.
*/
double Bar::wonThisTurn(int peeps) {
	return (((double)peeps)/((double)maxcapacity));
}

