/*************************************************************************
 * Developer: Raymond Tyler
 * File: EdgeHeap.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the EdgeHeap class.
 *************************************************************************/


#ifndef _HEAPHEADERS
#define _HEAPHEADERS

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Edge.h"

using namespace std;

class EdgeHeap
{
public:
	EdgeHeap(int);
	~EdgeHeap();
	int parent(int);
	int left(int);
	int right(int);
	Edge heapExtractMin();
	void minHeapInsert(int, int, int);
	void minHeapify(int);
	int findCost(int, int);
	Edge *getEdges();
	Edge findEdge(int, int);
	void print();
	void printOverview();
	
private:
	void heapDecreaseKey(int);
	Edge *Edges;
	int heapSize;
	int nE;
};

#endif
