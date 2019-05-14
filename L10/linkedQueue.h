#ifndef H_linkedQueue			// pre-processor macros
#define H_linkedQueue			// defining H_linkedQueue

#include <iostream>				// provides cin, cout,...
#include <cassert>				// provides assert
#include "queueADT.h"			// class header file

using namespace std;

template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
    const linkedQueueType<Type>& operator=
        (const linkedQueueType<Type>&);
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    Type front() const;
    Type back() const;
    void addQueue(const Type& queueElement);
    void deleteQueue();

	// default constructor
    linkedQueueType();

	// constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue);

	// destructor
    ~linkedQueueType();

private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;
};

template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == nullptr);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
}

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;

    while (queueFront != nullptr)
    {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }

    queueRear = nullptr;
}

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;

    newNode->info = newElement;
    newNode->link = nullptr;

    if (queueFront == nullptr)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
}

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear != nullptr);
    return queueRear->info;
}

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())
    {
        temp = queueFront;
        queueFront = queueFront->link;

        delete temp;

        if (queueFront == nullptr)

            queueRear = nullptr;
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}

// destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    this->initializeQueue();
}

// overloaded assignment operator
template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue)
{
    this->initializeQueue();

    if (!(otherQueue.isEmptyQueue()))
    {
        nodeType<Type> *temp;
        temp = otherQueue.queueFront;

        while (temp != nullptr)
        {
            addQueue(temp->info);
            temp = temp->link;
        }
    }
}

// copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType
(const linkedQueueType<Type>& otherQueue)
{
    this = otherQueue;
}

#endif
