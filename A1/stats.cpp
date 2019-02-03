// Program       :   stats.cpp
// Author        :   Farhad Alemi
// Due Date      :   February 2nd, 2019
// Description   :   This .cpp file contains the definition for class stats.cpp
//                   which resides inside the CISP430_A1 namespace. This class
//                   keeps track of the largest, smallest, total amount and
//                   number-of-entry values in a sequence.

#include <assert.h>                     // header file for the class
#include "stats.h"                      // needed for assert()

using namespace CISP430_A1;             // defining the namespace

// default constructor which initializes the member variables count and total
// to 0.
statistician::statistician()
{
    // initializing member variables
    count = 0;                          
    total = 0;
}

// This function adds values to the sequence of entries. It also sets the value
// for member variables.
void statistician::next(double r)
{
    total += r;             // update total

    // if object has previous entries
    if (length() > 0)
    {
        if (r < tiniest)
        {
            tiniest = r;
        }

        if (r > largest)
        {
            largest = r;
        }
    }

    // if object does not have entries
    else if(length() == 0)
    {
        tiniest = r;
        largest = r;
    }

    count++;                // increment count
}

// This function clears the statistician by setting the member variables
// to 0.
void statistician::reset()
{
    count = 0;
    total = 0;
    tiniest = 0;
    largest = 0;
}

// This function calculates and returns the mean value for the sequence
// of entries.
double statistician::mean() const
{
    assert(length() > 0);           // make sure object has entries.

    return (total / count);
}

// This function returns the minimum value for the sequence of entries.
double statistician::minimum() const
{
    assert(length() > 0);           // make sure object has entries.

    return tiniest;
}

// This function returns the maximum value for the sequence of entries.
double statistician::maximum() const
{
    assert(length() > 0);           // make sure object has entries.

    return largest;
}

// This function overloads the (+) operator.
statistician CISP430_A1::operator+(const statistician& s1, const statistician& s2)
{
    statistician s3;

    // if s1 has no entries
    if (s1.length() == 0)
    {
        s3.total = s2.total;
        s3.count = s2.count;
        s3.tiniest = s2.tiniest;
        s3.largest = s2.largest;
    }
    // if s2 has no entries
    else if (s2.length() == 0)
    {
        s3.total = s1.total;
        s3.count = s1.count;
        s3.tiniest = s1.tiniest;
        s3.largest = s1.largest;
    }
    // if both s1 and s2 have entries
    else
    {
        s3.total = s1.total + s2.total;
        s3.count = s1.count + s2.count;

        if (s1.tiniest < s2.tiniest)
        {
            s3.tiniest = s1.tiniest;
        }
        else
        {
            s3.tiniest = s2.tiniest;
        }

        if (s1.largest > s2.largest)
        {
            s3.largest = s1.largest;
        }
        else
        {
            s3.largest = s2.largest;
        }
    }

    return s3;
}

// This function overloads the (*) operator.
statistician CISP430_A1::operator *(double scale, const statistician& s)
{
    statistician s1;

    // if s has entries
    if (s.length() != 0)
    {
        s1.total = scale * s.total;
        s1.count = s.count;

        // if scale is positive
        if (scale > 0)
        {
            s1.tiniest = scale * s.tiniest;
            s1.largest = scale * s.largest;
        }
        // if scale is negative
        else
        {
            s1.tiniest = scale * s.largest;
            s1.largest = scale * s.tiniest;
        }
    }

    return s1;
}

// This function overloads the (==) operator.
bool CISP430_A1::operator ==(const statistician& s1, const statistician& s2)
{
    // In order for two statisticians to be equal, they must have the same length
    // Also, if their length is greater than zero, they must also have the same
    // mean, the same minimum, the same maximum, and the same sum.
    if ((s1.length() == 0 && s2.length() == 0) || (s1.length() == s2.length()
        && s1.sum() == s2.sum() && s1.mean() == s2.mean() 
        && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()))
    {
        return true;        // s1 equals s2
    }
    return false;           // s1 does not equal s2
}