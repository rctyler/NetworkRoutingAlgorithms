/*************************************************************************
 * Developer: Raymond Tyler
 * File: KruskalsAlgorithm.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the KruskalsAlgorithm class.
 *************************************************************************/


#ifndef _KRUSKALSHEADERS
#define _KRUSKALSHEADERS

#include "Edge.h"
#include "EdgeHeap.h"
#include "DisjointSet.h"

class KruskalsAlgorithm
{
public: 
	KruskalsAlgorithm(char const*);
	~KruskalsAlgorithm();
	void findMinimumSpanningTree();
	void setupTree(char const*);
	void print();
	void printMST();
	
private:
	int MSTindex;
	Edge *MSTedges;
	EdgeHeap *edgeHeap;
	disjointSet *DisjointS;
	int nE;
	int nV;
	int u;
	int v;
	int cost;	
};

#endif
