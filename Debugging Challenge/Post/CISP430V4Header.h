// Program       :   CISP430V4Header.h
// Author        :   Farhad Alemi W1628951
// Due Date      :   May 13th, 2019
// Description   :   The header file which contains the class declaration

// preprocessor macros
#ifndef H_H_CISP430V4Header
#define H_H_CISP430V4Header

#include <iostream>
#include <cassert>
#include <string>
using namespace std;
 
// the class declaration
template<class Type>
class queueType
{
public:
    void initializeQueue();
    void destroyQueue();
    bool isEmptyQueue();
    bool isFullQueue();
    void addQueue(const Type& queueElement);
    Type front();
    Type back();
    void deleteQueue();
    queueType(int queueSize = 100); 
    ~queueType(); 
     void print();
     int getmaxQueueSize();

private:
    int maxQueueSize;           // the maximum number of elements in queue
    int count;                  // current number of elements in queue
    std::string* list;  	            // pointer to a string array which stores the queue
     };

//#include "CISP430V4Header.cpp" 
#endif