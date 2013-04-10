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
#include "MinimumSpanningTreeAlgorithm.h"

using namespace std;

class PrimsAlgorithm : public MinimumSpanningTreeAlgorithm
{
public:
	PrimsAlgorithm(char const*);
	~PrimsAlgorithm();
	void findMinimumSpanningTree();
	void print();
	void printMST();
	
private:
	void computeMST();
 	VertexHeap *queue;
	Vertex *referenceArray;
	EdgeHeap *MSTedges;
	int *closedList;
	int closedIndex;
	int key;
	
};

#endif