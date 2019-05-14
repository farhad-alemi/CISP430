//Header file: stackADT.h 
#ifndef H_queueADT							// pre-processor macro
#define H_queueADT							// defining H_queueADT

// template for class queueADT which is an abstract class.
// All the public member functions are pure virtual functions which
// must be overridden in child classes. 
template <class Type>
class queueADT
{
public:
    virtual bool isEmptyQueue() const = 0;
    virtual bool isFullQueue() const = 0;
    virtual void initializeQueue() = 0;
    virtual Type front() const = 0;
    virtual Type back() const = 0;
    virtual void addQueue(const Type& queueElement) = 0;
    virtual void deleteQueue() = 0;
};

#endif