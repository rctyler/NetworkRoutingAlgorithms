/*************************************************************************
 * Developer: Raymond Tyler
 * File:  ShortestPathAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the ShortestPathAlgorithm
 *				abstract class. Any class that inherits from this must
 *				define the findShortestPath(), print(), and printShortestPath()
 *				functions
 *************************************************************************/

#ifndef _SPALGORITHM_HEADERS
#define _SPALGORITHM_HEADERS

#include <fstream>
#include <cstring>
#include "AdjacencyList.h"
#include "EdgeHeap.h"

using namespace std;

class ShortestPathAlgorithm
{
public:
	virtual ~ShortestPathAlgorithm() = 0;
	virtual bool findShortestPath() = 0;
	virtual void print() = 0;
	virtual void printShortestPath() = 0;
protected:
	ShortestPathAlgorithm(int src, int dest, char const*inputFile);
	bool checkForNegativeEdges();
	char InputFile[10];
	EdgeHeap *edgeHeap;
	AdjacencyList *adjacencyList;
	int source, destination;
	int nE, nV, u, v, cost;
	
};

inline ShortestPathAlgorithm::~ShortestPathAlgorithm()
{ 
	delete edgeHeap;
}

#endif