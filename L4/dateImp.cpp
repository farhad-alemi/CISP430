// Implementation file date

#include <iostream>             // provides cin, cout
#include "date.h"               // class header file

using namespace std;            // defining the namespace
 
// the main function which sets the date after verifying 
// it for accuracy
void dateType::setDate(int month, int day, int year)
{
    if (year > 0)               // is the year positive?
    {
        dYear = year;           // if yes, set it to dYear
    }
    else                        // if not, then...
    {
        dYear = 1900;           // set dYear to 1900
    }

    if (month > 0 && month < 13) // is the month less than 13 and greater than 0?
    {
        dMonth = month;          // if yes, set it to dMonth
    }
    else                         // if not, then...
    {
        dMonth = 1;              // set dMonth to 1
    }

    // if month is January, March, May, July, August, October, and December
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        // is day less than 32 and greater than 0?
        if (day > 0 && day < 32)
        {
            dDay = day;           // if yes, set it to dDay
        }
        // if not then...
        else
        {
            dDay = 1;            // set dDay to 1
        }
    }
    // if month is April, June, September, and November
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        // is day less than 31 and greater than 0?
        if (day > 0 && day < 31)
        {
            dDay = day;          // if yes, set it to dDay
        }
        // if not, then...
        else
        {
            dDay = 1;           // set dDay to 1
        }
    }
    // for February
    else
    {
        // is it leap year?
        if (isLeapYear())
        {
            // is day less than 30 and greater than 0?
            if (day > 0 && day < 30)
            {
                dDay = day;     // if yes, set it to dDay
            }
            // if not, then...
            else
            {
                dDay = 1;       // set dDay to 1
            }
        }
        // if not a leap year
        else
        {
            // is day less than 29 and greater than 0?
            if (day > 0 && day < 29)
            {
                dDay = day;     // if yes, set it to dDay
            }
            // if not, then...
            else
            {
                dDay = 1;       // set dDay to 1
            }
        }
    }
}

// const function which returns dDay
int dateType::getDay() const 
{
    return dDay;
}

// const function which returns dMonth
int dateType::getMonth() const 
{
    return dMonth;
}

// const function which returns dYear
int dateType::getYear() const 
{
    return dYear;
}

// const function which prints the obj contents on the screen
void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

// Constructor with parameters
dateType::dateType(int month, int day, int year) 
{ 
    setDate(month, day, year);          // call to setDate() function for data entry
}

// the function returns true if dYear is a leap year, otherwise returns false
bool dateType::isLeapYear()
{
    // mathematical logic for determining leap year
    if (((dYear % 400 == 0 || dYear % 100 != 0) && (dYear % 4 == 0)))
    {
        return true;
    }
    return false;
}