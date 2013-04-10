/*************************************************************************
 * Developer: Raymond Tyler
 * File: Edge.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for the Edge class.
 *************************************************************************/

#ifndef _EDGEHEADERS
#define _EDGEHEADERS

class Edge
{
public:
	Edge();
	void setCost(int);
	void setU(int);
	void setV(int);
	void setKey(int);
	int getCost();
	int getU();
	int getV();
	int getKey();
	
private:
	int cost;
	int u;
	int v;
	int key;
};

#endif