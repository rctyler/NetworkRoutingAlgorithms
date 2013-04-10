/*************************************************************************
 * Developer: Raymond Tyler
 * File: PrimsAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the Prims Algorithm class
 *************************************************************************/


#ifndef PRIMSALGORITHM_H
#define PRIMSALGORITHM_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "AdjacencyList.h"
#include "VertexHeap.h"
#include "EdgeHeap.h"
#include "Vertex.h"

using namespace std;

class PrimsAlgorithm
{
public:
	PrimsAlgorithm(char const*);
	~PrimsAlgorithm();
	void findMinimumSpanningTree();
	void computeMST();
	void print();
	void printMST();
	
private:
 	VertexHeap *queue;
	Vertex *referenceArray;
	AdjacencyList *adjacencyList;
	EdgeHeap *edgeHeap;
	EdgeHeap *MSTedges;
	int *closedList;
	int closedIndex;
	int nV;
	int nE;
	int key;
	int cost;
	int u;
	int v;
};

#endif