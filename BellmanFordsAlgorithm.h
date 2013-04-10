/*************************************************************************
 * Developer: Raymond Tyler
 * File: BellmanFordsAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the BellmanFordsAlgorithm class
 *************************************************************************/

#ifndef BELLMANFORDSALGORITHM_H
#define BELLMANFORDSALGORITHM_H

#include <stdlib.h>
#include <fstream>
#include "EdgeHeap.h"
#include "Vertex.h"

class BellmanFordsAlgorithm
{
public:
	BellmanFordsAlgorithm(int, int, char const*);
	~BellmanFordsAlgorithm();
	void initializeSingleSource();
	bool findShortestPath();
	void relax(int, int, int, int);
	void print();
	void printShortestPath();
	
private:
	EdgeHeap *edgeHeap;
	Vertex *Vertices;
	int *shortestPathArray;
	int nV;
	int nE;
	int source;
	int destination;
	int a;
	int b;
	int u;
	int v;
	int w;
};

#endif
