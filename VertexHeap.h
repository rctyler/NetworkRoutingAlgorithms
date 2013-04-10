/*************************************************************************
 * Developer: Raymond Tyler
 * File: VertexHeap.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the VertexHeap class.
 *************************************************************************/

#ifndef _VERTEXHEAP_H
#define _VERTEXHEAP_H

#include <iostream>
#include <stdlib.h>
#include "Vertex.h"

using namespace std;

class VertexHeap
{
public:
	VertexHeap(int);
	~VertexHeap();
	int parent(int);
	int left(int);
	int right(int);
	Vertex heapExtractMin();
	void minHeapInsert(int, int, int);
	void minHeapify(int);
	Vertex getVertex(int);
	int length();
	void print();
	void printNetworkOverview();
	
private:
	void heapDecreaseKey(int);
	int heapSize;
  	Vertex *Vertices;
};

#endif