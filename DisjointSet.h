/*************************************************************************
 * Developer: Raymond Tyler
 * File: DisjointSet.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the DisjointSet class.
 *************************************************************************/


#ifndef _DISJOINTHEADERS
#define _DISJOINTHEADERS

#include <iostream>
#include <stdio.h>

using namespace std;

class disjointSet
{
public:
	disjointSet(int);
	~disjointSet();
	void MakeSet(int);
	int FindSet_withPathCompression(int);
	int FindSet_withoutPathCompression(int);
	void Union_withPathCompression(int, int);
	void Union_withoutPathCompression(int, int);
	void printSet();
	
private:
	int len;
	int *DisjointSet;
	void Link(int, int);
};


#endif