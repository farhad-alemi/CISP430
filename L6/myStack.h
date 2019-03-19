//Header file: myStack.h

#ifndef H_StackType
#define H_StackType
 
#include <cassert>
#include "stackADT.h"

//*************************************************************
// This class specifies the basic operation on a stack as an 
// array.
//*************************************************************

// The child class which inherits from stackADT. It implements a stack
// using a dynamic array and member variables.
template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0;

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //    otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //    otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem is
      //    added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //    terminates; otherwise, the top element of the stack
      //    is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top element is
      //    removed from the stack.

    bool operator==(const stackType<Type>& otherStack) const;

    stackType(int stackSize = 100); 
      //Constructor
      //Create an array of the size stackSize to hold 
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base address 
      //   of the array, stackTop = 0, and maxStackSize = stackSize

    stackType(const stackType<Type>& otherStack); 
      //Copy constructor

    ~stackType(); 
      //Destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //    elements is deleted.

private:
    int maxStackSize; //variable to store the maximum stack size
    int stackTop;     //variable to point to the top of the stack
    Type *list; //pointer to the array that holds the stack elements

    void copyStack(const stackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and assigned
      //    to this stack.
};


// Function to initialize the stack to an empty state.
// Postcondition: stackTop = 0;
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

// Function to determine whether the stack is empty.
// Postcondition: Returns true if the stack is empty,
// otherwise returns false.
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);                     // is stack empty?
}

// Function to determine whether the stack is full.
// Postcondition: Returns true if the stack is full,
// otherwise returns false.
template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (maxStackSize == stackTop);          // is stack full?
}

// Function to add newItem to the stack.
// Precondition: The stack exists and is not full.
// Postcondition: The stack is changed and newItem is
// added to the top of the stack.
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    // make sure the stack exists and is not full.
    assert(list != nullptr && !isFullStack());

    // populate new item
    list[stackTop] = newItem;
    ++stackTop;

}

// Function to return the top element of the stack.
// Precondition: The stack exists and is not empty.
// Postcondition: If the stack is empty, the program 
// terminates; otherwise, the top element of the stack
// is returned.
template <class Type>
Type stackType<Type>::top() const
{
    // make sure the stack exists and is not empty.
    assert(list != nullptr && !isEmptyStack());
    return (list[stackTop - 1]);                // return the top item
}

// Function to remove the top element of the stack.
// Precondition: The stack exists and is not empty.
// Postcondition: The stack is changed and the top element is
// removed from the stack.
template <class Type>
void stackType<Type>::pop()
{
    // make sure the stack exists and is not empty.
    assert(list != nullptr && !isEmptyStack());
    
    // the top element is removed out-of-sight
    --stackTop;
}

// Constructor
// Create an array of the size stackSize to hold 
// the stack elements. The default stack size is 100.
// Postcondition: The variable list contains the base address 
// of the array, stackTop = 0, and maxStackSize = stackSize
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)                         // make sure to avoid invalid entry
    {
        maxStackSize = 100;                     // set to default value
    }
    else
    {
        maxStackSize = stackSize;               // set to function parameter
    }

    stackTop = 0;                               // stack is empty.
    list = new Type(maxStackSize);              // allocate list (array) on heap
}

// Copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    copStack(otherStack);                       // call to the private member function
}


// Destructor
// Remove all the elements from the stack.
// Postcondition: The array (list) holding the stack 
// elements is deleted.
template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;                             // deallocates the memory
}

// Function to make a copy of otherStack.
// Postcondition: A copy of otherStack is created and assigned
// to this stack.
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    if (this != &otherStack)                    // is it doing self-assignment?
    {
        stackTop = otherStack.stackTop;         // set stockTop
        maxStackSize = otherStack.maxStackSize; // set maxStackSize

        delete[] list;                          // deallocate old memory FIRST
        
        // set the pointer to point to the new location
        list = new Type(maxStackSize);

        // perform deep copy
        for (int i = 0; i < stackTop; i++)
        {
            list[i] = otherStack.list[i];
        }
    }
}

//Overload the assignment operator.
template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& source)
{
    if (this == &source)                        // is it doing self-assignment?
    {
        return *this;                           // if yes, then return *this
    }

    copyStack(source);                          // call to the private member function

    return *this;                               // if yes, then return *this
}

// The funciton overloads the == operator. It returns true if otherStack is equal
// to this object; otherwise, it returns false.
template <class Type>
bool stackType<Type>::operator==(const stackType<Type>& otherStack) const
{
    // are both objects empty?
    if (isEmptyStack() && otherStack.isEmptyStack())
    {
        return true;
    }

    // is stackTop equal to otherStack.stackTop AND maxStackSize == 
    // otherStack.maxStackSize?
    else if (stackTop == otherStack.stackTop && maxStackSize == otherStack.maxStackSize)
    {
        // perform element-by-element comparison
        for (int i = 0; i < stackTop; i++)
        {
            // if list[i] is not equal to otherStack.list[i], then return false
            if (list[i] != otherStack.list[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

#endif