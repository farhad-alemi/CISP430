// Program       :   sequence.cpp
// Author        :   Farhad Alemi
// Due Date      :   February 27th, 2019
// Description   :   This .cpp file contains the definition for class sequence.cpp
//                   which resides inside the CISP430_A2 namespace. It uses multiple
//                   member functions to insert, attach, and remove entries from the
//                   the sequence.

#include <assert.h>                     // provides assert()
#include <algorithm>                    // provides copy()
#include "sequence4.h"                  // class header file

using namespace CISP430_A3;             // the namespace inside which the class has
                                        // been defined

// Default constructor which creates a dynamic array on the heap.
// It also initializes the member variables.
template <class Item>
sequence<Item>::sequence()
{
	head_ptr = new node<Item>;
	tail_ptr = new node<Item>;
	cursor = new node<Item>;
	//precursor = nullptr;
	many_nodes = 0;
    
	/*data = new value_type[entry];       // dynamic array used for storing entries.
    used = 0;                           // the number of elements in the sequence
    current_index = 0;                  // current index in the array
    capacity = entry;                   // total number of elements allocated in
                                        // the array
									*/
}

// Copy constructor which creates a dynamic array on the heap.
// It also assigns to the member variables the members
// of the parameter object.
template <class Item>
sequence<Item>::sequence(const sequence& entry)
{

    /*
    data = new value_type[entry.capacity];          // dynamic array for storing entries
    used = entry.used;                              // number of entries
    current_index = entry.current_index;            // current index in the array
    capacity = entry.capacity;                      // total number of elements allocated in

    // performing a deep copy of the array contents
    for (int i = 0; i < used; i++)
    {
        data[i] = entry.data[i];
    }
*/}

// Destructor which deallocates the memory 
// used by dynmaic array elements.
template <class Item>
sequence<Item>::~sequence()
{
    //delete head_ptr;
    //delete tail_ptr;
    //delete cursor;
    //delete precursor;
    //delete[] data;                // deallocating memory used by dynamic array elements
}

// ---MODIFICATION MEMBER FUNCTIONS---
// the start() function sets the current_index to 0.
template <class Item>
void sequence<Item>::start()
{
    precursor = nullptr;
    cursor = head_ptr;            // moving to the beginning of the array
}

// moves the cursor one element forward by
// incrementing current_index.
template <class Item>
void sequence<Item>::advance()
{
    //assert(is_item());            // make sure the current element is valid
    //precursor = cursor;
    //cursor = cursor->link();              // move to the cursor one element forward
}

// insert() adds an element in the current_index location after shifting
// existing elements one element to the right.
template <class Item>
void sequence<Item>::insert(const value_type& entry)
{
    /*if (used == capacity)          // does array need to be resized?
    {
        resize(1 + (1.1 * used));  // if yes, then make sure to expand it by 10%
    }

    if (!is_item())                // is the sequence empty?
    {
        current_index = 0;         // set the position to the beginning of the array
    }

    // shifting existing elements to the right
    for (int i = used; i > current_index; i--)
    {
        data[i] = data[i - 1];     // shift to the right
    }

    data[current_index] = entry;   // put the new element in the current_index position
    used++;                        // increment the number of elements*/
}

// attach() adds an element in the (current_index + 1) location after shifting
// existing elements one element to the right. It then makes the newly added element
// the current element.
template <class Item>
void sequence<Item>::attach(const value_type& entry)
{
    /*if (used >= capacity)          // does array need to be resized?
    {
       resize(1 + (1.1 * used));   // if yes, then make sure to expand it by 10%
    }

    if (!is_item())                // is the sequence empty?
    {
        data[used] = entry;        // put the new element in the front
        ++used;                    // increment the number of elements
    }
    else
    {
        // shifting existing elements to the right
        for (size_type i = used; i > (current_index + 1); --i)
        {
            data[i] = data[i - 1];   // shift to the right
        }
        ++current_index;             // move the cursor one unit forward
        data[current_index] = entry; // put the new element after the previously selected one 
        ++used;                      // increment the number of elements
    }
*/}

//
template <class Item>
void sequence<Item>::remove_current()
{
    assert(is_item());
    precursor->set_link(cursor->link());
    --many_nodes;
    
    /*for (int i = current_index; i < used - 1; i++)
    {
        data[i] = data[i + 1];
    }
    used--;*/
}

// resize() function extends the capacity of the dynamically allocated
// array by copying the items to a newly and larger dynamically allocated array.
/*void sequence::resize(size_type new_capacity)
{
      if(new_capacity > capacity)           // does the array need to be enlarged?
      {
         value_type *larger_array;          // the new array

         // allocating new array on the heap
         larger_array = new value_type[new_capacity];

         // performing deep copy
         for (int i = 0; i < used; ++i)
         {
            larger_array[i] = data[i];
         }
         delete [] data;                    // deallocating the old array
         data = larger_array;               // setting the pointer to point to the new array
         capacity = new_capacity;           // updating the capacity
      }
   }*/

// this function overloads the assignment operator. It does so by allocating a new array,
// copying items to the new array and then deallocating the old array.
template <class Item>
void sequence<Item>::operator =(const sequence& source)
{/*
      value_type *new_data;                 // declaring pointer to the new array

      // Check for possible self-assignment
      if ( this == &source )                // are we trying to assign the pointer to itself?
      {
          return;                           // if yes, then exit
      }

      // if the capacity is not the same
      if (capacity != source.capacity)
      {
         new_data = new value_type[source.capacity];    // allocate a new array on the heap
         delete[] data;                                 // deallocate previous elements
         data = new_data;                               // setting the pointer to point to the new array
         capacity = source.capacity;                    // updating the capacity
      }

      used = source.used;                               // updating used
      current_index = source.current_index;             // updating current index
      std::copy(source.data, source.data + used, data); // performing a deep copy using the copy() function
   */}


//---CONSTANT MEMBER FUNCTIONS---
// this function returns the number of entries in the array

// returns true if there is a valid entry, otherwise returns false


// returns the data in the current slot after making sure that the 
// slot has valid entry.
template <class Item>
typename sequence<Item>::value_type sequence<Item>::current() const
{
    assert(is_item());              // make sure the current entry is valid

    return cursor->data();     // return data in the current slot
}