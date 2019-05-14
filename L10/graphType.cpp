// Implementation File for Class graphType
#include "graphType.h"							// class header file

// returns true if size is zero
bool graphType::isEmpty() const
{
	return (gSize == 0);
}

// the function creates a graph by reading data using a file-stream.
// If the file cannot be openned, it returns.
void graphType::createGraph()
{
	ifstream infile;				// file-stream variable
	char fileName[50];				// array of 50 characters

	int index;						// the index
	int vertex;						// the vertex
	int adjacentVertex;				// the adjacent vertex

	if (gSize != 0)					// if the graph size is not zero,
	{
		clearGraph();				// clear the graph
	}

	// open the input file
	infile.open("C:\CISP430V4L10.txt");

	// if there is a problem with openning the input file,
	if (!infile)
	{
		cout << "Cannot open input file." << endl;
		return;						// return after displaying an error message
	}

	// start reading the file
	infile >> gSize;

	// the reading process
	for (index = 0; index < gSize; index++)
	{
		// read the vertex and the adjacent vertex
		infile >> vertex;
		infile >> adjacentVertex;

		// perform the loop until you reach the end-flag(-999)
		while (adjacentVertex != -999)
		{
			// keep inserting the vertexes
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}

	// close the file stream
	infile.close();
}

// this function clears the graph
void graphType::clearGraph()
{
	int index;					// temp variable used as the for-loop index

	// the for-loop which clears the list
	for (index = 0; index < gSize; index++)
	{
		graph[index].destroyList();
	}

	// set the size to 0.
	gSize = 0;
}

// the function prints the graph to the computer screen
void graphType::printGraph() const
{
	int index;				    // temp variable used as the for-loop index

	// the for-loop prints the contents
	for (index = 0; index < gSize; index++)
	{
		cout << index << " ";
		graph[index].print();
		cout << endl;
	}

	cout << endl;
}

// the function performs a depth-first traversal
// by utilizing the dynamic memory
void graphType::depthFirstTraversal()
{
	bool* visited;				// pointer to visited vertexes
	visited = new bool[gSize];	// allocating dynamic memory

	int index;					// temp variable used as the for-loop index

	// initializing the array
	for (index = 0; index < gSize; index++)
	{
		visited[index] = false;
	}


	for (index = 0; index < gSize; index++)
	{
		if (!visited[index])
		{
			dft(index, visited);
		}
	}
	delete[] visited;
}

// helper member function
void graphType::dft(int v, bool visited[])
{
	visited[v] = true;
	cout << " " << v << " ";

	linkedListIterator<int> graphIt;


	for (graphIt = graph[v].begin(); graphIt != graph[v].end();
		++graphIt)
	{
		int w = *graphIt;
		if (!visited[w])
			dft(w, visited);
	}
}

// helper member function
void graphType::dftAtVertex(int vertex)
{
	bool* visited;

	visited = new bool[gSize];

	for (int index = 0; index < gSize; index++)
		visited[index] = false;

	dft(vertex, visited);

	delete[] visited;
}

// the function performs a breadth-first traversal
// by utilizing the dynamic memory
void graphType::breadthFirstTraversal()
{
	// instantiating an object of linkedQueueType of type int
	linkedQueueType<int> queue;

	// pointer to visited nodes
	bool* visited;
	visited = new bool[gSize];

	// initializing the array
	for (int ind = 0; ind < gSize; ind++)
	{
		visited[ind] = false;
	}

	// instantiating an iterator
	linkedListIterator<int> graphIt;

	// the loop implements the main logic of the function
	for (int index = 0; index < gSize; index++)
	{
		if (!visited[index])
		{
			queue.addQueue(index);
			visited[index] = true;
			cout << " " << index << " ";

			while (!queue.isEmptyQueue())
			{
				int u = queue.front();
				queue.deleteQueue();

				for (graphIt = graph[u].begin();
					graphIt != graph[u].end(); ++graphIt)
				{
					int w = *graphIt;
					if (!visited[w])
					{
						queue.addQueue(w);
						visited[w] = true;
						cout << " " << w << " ";
					}
				}
			}
		}
	}

	// deallocating the array
	delete[] visited;
}

// constructor which allocates an array of unorderedLinkedList
// of type int and initializes the maxSize and gSize member variables
graphType::graphType(int size)
{
	maxSize = size;
	gSize = 0;
	graph = new unorderedLinkedList<int>[size];
}

// destructor which calls the clearGraph() member function
graphType::~graphType()
{
	clearGraph();
}