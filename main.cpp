/*************************************************************************
 * Developer: Raymond Tyler
 * File: main.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for main. The program
 *				starts here, and gives the user the option of whether to
 *				find the minimum spanning tree of a grpah, or the shortest
 *				path in a graph. NOTE: The program reads from 
 *				InputFiles/input.txt to build the graph, so if you want to
 *				try out your own graph, make sure you name it input.txt
 *************************************************************************/

#include "main.h"

int main(int argc, char** argv)
{
prompt:
    cout << "\n\n================================================================================";
    cout << "\n                           Network Routing Algorithms ";
    cout << "\n Programmer:";
    cout << "\n    Raymond Tyler";
    cout << "\n Description:";
    cout << "\n    This program takes an undirected graph representation of routing nodes ";
    cout << "\n    and computes either a minimum spanning tree, or the shortest path from";
    cout << "\n    a client to a server node.";
    cout << "\n Operating Instructions:";
    cout << "\n    Choose whether you want to find a minimum spanning tree or the";
    cout << "\n    shortest path from a client node to a server node. Then choose"; 
    cout << "\n    a desired algorithm to step through";
    cout << "\n================================================================================";
	
    char stage1;
    char stage2;
    int clientNode;
    int serverNode;
	
    //read from file
    ifstream file_in(_InputFile);
	
    int nE, nV, u, v, cost = 0;     
    file_in >> nV >> nE;
	
    EdgeHeap *edgeHeap = new EdgeHeap(nE); 
	
    for (int i = 1; i <= nE; i++)
    {
        file_in >> u >> v >> cost;
		edgeHeap->minHeapInsert(cost, u, v);
    }
	
    cout << "\n\nUndirected Network Graph: < Link_Cost[NodeX, NodeY] >" << endl;
    edgeHeap->printOverview();
    
    cout << "\nActive Routers: "; 	
    for (int i = 1; i < nV - 1; i++)
        cout << "Node " << i << ", ";
    cout << "Node " << nV - 1 << ", and Node " << nV << endl;
	
    while (1)
    { 
    	cout << "\nWould you like to:";
    	cout << "\n(A) Find the minimum spanning tree of this undirected graph";
    	cout << "\n(B) Find the shortest path from the client to server node";
        cout << "\n(Q) Quit Program" << endl;
    	cout << "\n# ";
    	
        cin >> stage1;
		
		switch (stage1)
		{
			case'a':
			case 'A': {
				while (1) {
					cout << "\nYou have chosen to find a minimum spanning tree. ";
	            	cout << "\nWhich agorithm would you prefer?";
	            	cout << "\n(1) Kruskal's Algorithm";
	            	cout << "\n(2) Prim's Algorithm" << endl;
	            	cout << "\n# ";
	            	cin >> stage2;
	            	switch (stage2)
	            	{	
	                    case '1': {
							cout << "\n================================================="; 
							cout << "\nKruskal's Minimum Spanning Tree Algorithm:";
							cout << "\n================================================="<< endl << endl << endl;
							KruskalsAlgorithm *kruskalsMinimumSpanningTree = new KruskalsAlgorithm(_InputFile);
							kruskalsMinimumSpanningTree->findMinimumSpanningTree();
							kruskalsMinimumSpanningTree->printMST();
							delete kruskalsMinimumSpanningTree;
	                    	
							char a;
							while(1) {
								cout << "Would you like to analyze this network graph again using another algorithm? [y/n] ";
								cin >> a;
								if (a == 'Y' or a == 'y')
								{
									cout << endl;
									goto prompt;
								}
								else if (a == 'N' or a == 'n')
								{
									printGoodbyeMessage();
									return 0;
								}
								else
								{
									cout << "\nPlease enter y or n." << endl << endl;
								}
							}
						}
	                    case '2': {
							cout << "\n=================================================";
	                    	cout << "\nPrim's Minimum Spannning Tree Algorithm:";
							cout << "\n=================================================" << endl << endl << endl;
							PrimsAlgorithm *primsMinimumSpanningTree = new PrimsAlgorithm(_InputFile);
							primsMinimumSpanningTree->findMinimumSpanningTree();
							delete primsMinimumSpanningTree;
	                    	
							char a;
							while(1) {
								cout << "Would you like to analyze this network graph again using another algorithm? [y/n] ";
								cin >> a;
								if (a == 'Y' or a == 'y')
								{
									cout << endl;
									goto prompt;
								}
								else if (a == 'N' or a == 'n')
								{
									printGoodbyeMessage();
									return 0;
								}
								else
								{
									cout << "\nPlease enter y or n." << endl << endl;
								}
							}
						}
	                    default: {
							cout << "\nCommand not recognized, please type either 1 or 2" << endl;
							break;
						}
					}
	            }
	            break;
			}
			case 'b':
			case 'B': {
				bool continueAsking = true;
	            cout << "\nYou have chosen to find the shortest path from a Client to Server node.";
				
	     	    while (continueAsking) {
	            	cout << "\nWhich node is the Client?" << endl;
	            	cout << "\n# ";
	            	cin >> clientNode;
	            	cout << "\nWhich node is the Server?" << endl;
	            	cout << "\n# ";
	            	cin >> serverNode;
					
					if (clientNode > nV)
						cout << "\nClient node must be a number less than " << nV + 1 << ". Please try again." << endl;
					else if (clientNode < 1)
						cout << "\nClient node must be a number greater than 1. Please try again." << endl;
					else if (serverNode > nV)
						cout << "\nServer node must be a number less than " << nV + 1 << ". Please try again." << endl;
					else if (serverNode < 1)
						cout << "\nServer node must be a number greater than 1. Please try again." << endl;
					else
						continueAsking = false;
				}
				
				while (1) {
					char a;
					
					cout << "\nWhich agorithm would you prefer?";
					cout << "\n(1) Dijkstra's Algorithm ";
					cout << "\n(2) Bellman Ford's Algorithm" << endl;
					cout << "\n# ";
					cin >> stage2;
	            	switch (stage2)
	            	{
	                    case '1': {
							cout << "\n========================================";
	                    	cout << "\nDijkstra's Shortest Path Algorithm:";
							cout << "\n========================================" << endl << endl << endl;
							
							DijkstrasAlgorithm *dijkstrasShortestPath = new DijkstrasAlgorithm(clientNode, serverNode, _InputFile);
							dijkstrasShortestPath->findShortestPath();
							delete dijkstrasShortestPath;
							
							char a;
							while(1) {
								cout << "Would you like to analyze this network graph again using another algorithm? [y/n] ";
								cin >> a;
								if (a == 'Y' or a == 'y')
								{
									cout << endl;
									goto prompt;
								}
								else if (a == 'N' or a == 'n')
								{
									printGoodbyeMessage();
									return 0;
								}
								else
								{
									cout << "\nPlease enter y or n." << endl << endl;
								}
							}
						}
	                    case '2': {
							bool flag = false;
							cout << "\n==========================================";
							cout << "\nBellman Ford's Shortest Path Algorithm:";
							cout << "\n==========================================" << endl << endl << endl;
	                    	BellmanFordsAlgorithm *bellmanFordsShortestPath = new BellmanFordsAlgorithm(clientNode, serverNode, _InputFile);
							flag = bellmanFordsShortestPath->findShortestPath();
							delete bellmanFordsShortestPath;
	                        
							char a;
							while(1) {
								cout << "Would you like to analyze this network graph again using another algorithm? [y/n] ";
								cin >> a;
								if (a == 'Y' or a == 'y')
								{
									cout << endl;
									goto prompt;
								}
								else if (a == 'N' or a == 'n')
								{
									printGoodbyeMessage();
									return 0;
								}
								else
								{
									cout << "\nPlease enter y or n." << endl << endl;
								}
							}
						}
	                    default: {
							cout << "\nCommand not recognized, please type either 1 or 2" << endl;
	                    	break;
						}
					}
	            }
	            break;
			}
			case 'q':
			case 'Q':
				printGoodbyeMessage();
				return 0;
				
	        default:
				cout << "\nCommand not recognized, please type either A, B, or Q" << endl;
	            break;
		}
    }
	
    //close file
    file_in.close();
	
    return(1);
}

void printGoodbyeMessage()
{
	cout << "\n\n===============================================================\n";
	cout << "Goodbye! and thank you for using my program -- Raymond Tyler\n";	
	cout << "===============================================================\n\n\n";
}