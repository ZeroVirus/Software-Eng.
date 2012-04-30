#ifndef GRAPH_H
#define GRAPH_H

/*This is the structure that is used to communicate between the GUI frontend and 
backend. This structure is repopulated and filled in with current round data 
everytime a turn has passed in order to update the graph data on the frontend 
for all graphs */
struct pass_graph {
	int numWinBars; //The number of bars that won
	int numWinners; //The number of Agents that won the current round
	double avgStratScore; //The average score of all Agent strategies
	double bestStratScore;//The score of the best faring Agent Strategy for the current round
	bool barCompare[256];
	};

	typedef struct pass_graph* graphPtr; 

#endif

