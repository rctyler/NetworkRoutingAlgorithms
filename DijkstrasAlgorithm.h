/*************************************************************************
 * Developer: Raymond Tyler
 * File: DijkstrasAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the DijkstrasAlgorithm class
 *************************************************************************/

#ifndef DIJKSTRASALGORITHM_H
#define DIJKSTRASALGORITHM_H

#include <stdlib.h>
#include <fstream>
#include "Vertex.h"
#include "VertexHeap.h"
#include "AdjacencyList.h"
#include "EdgeHeap.h"
#include "ShortestPathAlgorithm.h"

using namespace std;

class DijkstrasAlgorithm : public ShortestPathAlgorithm
{
public:
	DijkstrasAlgorithm(int, int, char const*);
	~DijkstrasAlgorithm();
	void initializeSingleSource();
	void relax(Vertex, Vertex,  int);
	bool findShortestPath();
	void print();
	void printShortestPath();
	
private:
	VertexHeap *queue;
	Vertex *referenceArray;
	int *S;
 	int nodesProcessedIndex;
};

#endif
