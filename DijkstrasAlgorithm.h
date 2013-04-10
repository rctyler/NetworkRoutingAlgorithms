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

using namespace std;

class DijkstrasAlgorithm
{
public:
	DijkstrasAlgorithm(int, int, char const*);
	~DijkstrasAlgorithm();
	void initializeSingleSource();
	void relax(Vertex, Vertex,  int);
	void findShortestPath();
	void print();
	void printShortestPath();
	
private:
	EdgeHeap *edgeHeap;
	VertexHeap *queue;
	Vertex *referenceArray;
	AdjacencyList *adjacencyList;
	int *S;
	int source;
	int destination;
	int nV;
	int nE;
 	int nodesProcessedIndex;
};

#endif
