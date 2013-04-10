/*************************************************************************
 * Developer: Raymond Tyler
 * File: AdjacencyList.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the Adjacency List class
 *************************************************************************/

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>

using namespace std;

class AdjacencyList
{
public:
	AdjacencyList(int);
	~AdjacencyList();
	void addVertex(int, int);
	void removeLastVertexAt(int);
	int getLastVertexAt(int);
	vector<int> getListAt(int);
	void print();
	
private:
	int adjacencyDepth;
	vector< vector<int> > adjacencyList;
};

#endif
