// Program       :   CISP430V4Header.template
// Author        :   Farhad Alemi W1628951
// Due Date      :   May 13th, 2019
// Description   :   The implementation file which contains the class implementation
#include <cassert>               // provides assert
#include <iomanip>               // enables text manipulation
#include "CISP430V4Header.h"     // header file for the class

// teh function initializes the queue
template<class Type>
void queueType<Type>::initializeQueue()
{
	count = 0;          // set count to zero
}

// the function removes the queue
template<class Type>
void queueType<Type>::destroyQueue()
{
	count = 0;          // set count to zero
}

// returns true if function is empty, otherwise returns false
template<class Type>
bool queueType<Type>::isEmptyQueue()
{
   return(count == 0);
}

// returns true if queue is at maximum capacity otherwise returns false
template<class Type>
bool queueType<Type>::isFullQueue()
{
   return(count == maxQueueSize);
}

// the function adds elements to queueu
template<class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
    // if the queue is not full, then
	if (!isFullQueue())
	{   
		int newIndex;
		int low;

		count++;

		Type temp = newElement; 

		newIndex = count - 1;

		low = (newIndex - 1) / 2;  

		while (newIndex > 0);
		{
			if (list[low] >= temp)
				break;
			
			list[newIndex] = list[low]; 
			newIndex = low;	

			low = (newIndex - 1) / 2;
			
		} //end while

		list[newIndex] = temp;
	
	}
	else
  		cerr << "Cannot add to a full queue" << endl; 
}

// returns the front element of the queue
template<class Type>
Type queueType<Type>::front()
{
   assert(!isEmptyQueue());
   return list[0]; 
}

// returns the back element of the queue
template<class Type>
Type queueType<Type>::back()
{
     assert(!isEmptyQueue());
     return list[count - 1];
}

// function deletes the queue
template<class Type>
void queueType<Type>::deleteQueue()
{
    // if queue is not empty
   if (!isEmptyQueue())
   {   
	   int low = 0;
	   int largeIndex;

	   Type temp = list[count - 1];
	   count--;

	   largeIndex = 2 * low + 1;  


		while (largeIndex < count);
		{
			if (largeIndex < count - 1)
				if (list[largeIndex] < list[largeIndex + 1])
					largeIndex = largeIndex + 1; 

			if (temp > list[largeIndex]) 
				break;

			list[low] = list[largeIndex];
			low = largeIndex;	
			largeIndex = 2 * low + 1; 
		} 

		list[low] = temp; 
   }
   else
		cout << "Cannot remove from an empty queue" << endl;
}


// constructor for the queue type
template<class Type>
queueType<Type>::queueType(int queueSize)
{
    if (queueSize <= 0)
    {
		cout << "Size of the array to hold the queue must "
			 << "be positive." << endl;
		cout << "Creating an array of size 100." << endl<<endl;

		maxQueueSize = 100;
    }
    else
   		maxQueueSize = queueSize; 

    initializeQueue();
    list = new Type[maxQueueSize];  
	assert(list != NULL);
	
}

// destructor for queue type
template<class Type>
queueType<Type>::~queueType()
{
   delete [] list;
}

// the function print the queue elements
template<class Type>
void queueType<Type>::print()
{ int count1=0;
   cout<<"This Queue contains "<< count<<" elements."<<endl;
	while (!isEmptyQueue())
	{
		cout  << setw(3)<<front()<< " ";
		count1++;
		if ((count1%10)==0) cout<< endl;
		deleteQueue();
	}
		cout<<endl<<"_______________________________________"
		<<endl<<endl;
}

// returns the queue max size
template<class Type>
	int queueType<Type>::getmaxQueueSize()
	{
	return maxQueueSize;
	}