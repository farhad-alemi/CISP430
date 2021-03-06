#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;
 
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;


    void insertFirst(const Type& newItem);


    void insertLast(const Type& newItem);


    void deleteNode(const Type& deleteItem);

};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; 
    bool found = false;
    
    current = first; 

    while (current != nullptr && !found)    
        if (current->info == searchItem) 
            found = true;
        else
            current = current->link; 

    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; 

    newNode = new nodeType<Type>; 

    newNode->info = newItem;    
    newNode->link = first;      
    first = newNode;            
                                
    count++;                    

    if (last == nullptr)   

        last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; 

    newNode = new nodeType<Type>; 

    newNode->info = newItem;  
    newNode->link = nullptr;     
                              

    if (first == nullptr)  
    {
        first = newNode;
        last = newNode;
        count++;        
    }
    else    
    {
        last->link = newNode; 
        last = newNode; 
                        
        count++;       
    }
}


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; 
    nodeType<Type> *trailCurrent; 
    bool found;

    if (first == nullptr)     
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) 
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    
                last = nullptr;
            delete current;
        }
        else 
        {
            found = false;
            trailCurrent = first;  
                                   
            current = first->link; 
                                   

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }

            if (found) 
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   
                                       
                    last = trailCurrent; 
                                        
                delete current;  
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }
    }
}


#endif
