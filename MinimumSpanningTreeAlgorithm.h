/*************************************************************************
 * Developer: Raymond Tyler
 * File: MinimumSpanningTreeAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the MininimumSpanning-
 *				TreeAlgorithm abstract class. Any class that inherits from
 *				this must define the findMinimumSpanningTree(), print(), and
 *				printMST() functions
 *************************************************************************/

#ifndef _MSTALGORITHM_HEADERS
#define _MSTALGORITHM_HEADERS

#include <fstream>
#include "AdjacencyList.h"
#include "EdgeHeap.h"
	
using namespace std;

class MinimumSpanningTreeAlgorithm
{
public:
	virtual ~MinimumSpanningTreeAlgorithm() = 0;
	virtual void findMinimumSpanningTree() = 0;
	virtual void print() = 0;
	virtual void printMST() = 0;
protected:
	MinimumSpanningTreeAlgorithm(char const*);
	EdgeHeap *edgeHeap;
	AdjacencyList *adjacencyList;
	int nE, nV, u, v, cost; 
};

inline MinimumSpanningTreeAlgorithm::~MinimumSpanningTreeAlgorithm()
{ 
	delete edgeHeap;
}

#endif