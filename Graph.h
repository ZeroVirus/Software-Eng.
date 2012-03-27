#ifndef GRAPH_H
#define GRAPH_H

struct pass_graph {
	int numWinBars;
	int numWinners;
	double avgStratScore;
	double bestStratScore;
	bool barCompare[256];
	};


typedef struct pass_graph* graphPtr; 



#endif