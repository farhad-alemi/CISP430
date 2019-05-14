// Program       :   CISP430V4L10.cpp
// Author        :   Farhad Alemi
// Due Date      :   May 13th, 2019
// Description   :   This program writes data to a file using 
//                   graphs, linked lists, and queues. 

#include <iostream>					// provides cin, cout, ...
#include <fstream>					// provides filestream
#include "graphType.h"				// header file for the program

using namespace std;				// utilizing the standard namespace

int main()
{
	// instantiating an object of type graphType
    graphType myGraph(50);

	// activating the createGraph() function
    myGraph.createGraph();
    cout << endl << endl;

	// performing breadth-first traversal
    cout << "Breadth First Traversal: ";
    myGraph.breadthFirstTraversal();

    cout << endl << endl;
    system("PAUSE");

    return 0;
}