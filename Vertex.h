/*************************************************************************
 * Developer: Raymond Tyler
 * File: Vertex.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the Vertex class.
 *************************************************************************/

#ifndef VERTEX_H
#define VERTEX_H

#include <math.h>
#include <stdio.h>

class Vertex
{
public:
	Vertex();
  	int getParent();
	int getKey();
	int getReference();
	void setParent(int);
	void setKey(int);
	void setReference(int);
private:
	int parent;
	int key;
	int reference;
};

#endif