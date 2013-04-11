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
#include "ShortestPathAlgorithm.h"

class BellmanFordsAlgorithm : public ShortestPathAlgorithm
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
	Vertex *Vertices;
	int *shortestPathArray;
	int a;
	int b;
	int w;
};

#endif
