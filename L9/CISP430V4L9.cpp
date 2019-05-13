#include <iostream>
#include <fstream>
#include "graphType.h" 
  
using namespace std;

int main() 
{
	graphType myGraph(50);

	myGraph.createGraph();
	cout << endl << endl;
	
	cout << "Depth First Traversal: ";
	myGraph.depthFirstTraversal();
	cout << endl<<endl;
	system("PAUSE");

	return 0;
}