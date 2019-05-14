#ifndef H_graph						// pre-processor macros
#define H_graph						// defining H_graph

#include <iostream>					// provides cin, cout,...
#include <fstream>					// provides file-stream variables
#include <iomanip>					// allows text display manipulations
#include "linkedList.h"				// project header file
#include "unorderedLinkedList.h"	// project header file
#include "linkedQueue.h"			// project header file

using namespace std;

class graphType
{
public:
	// public member functions
    bool isEmpty() const;
    void createGraph();
    void clearGraph();
    void printGraph() const;
    void depthFirstTraversal();
    void dftAtVertex(int vertex);
    void breadthFirstTraversal();
    
	// the constructor
	graphType(int size = 0);

	// the destructor
    ~graphType();

protected:
	// protected member variables
    int maxSize;						// the maximum size of the graph
    int gSize;							// current size
    unorderedLinkedList<int> *graph;	// pointer to unorderedLinkedList of type int

private:
    void dft(int v, bool visited[]);	// private helper function
};

#endif