// Program       :   CISP430V4L5_MainProgram.cpp
// Author        :   Farhad Alemi
// Due Date      :   March 11th, 2019
// Description   :   This is a driver program for dateType class. It creates
//                   2 objects of the class and then displays their content
//                   after manipulating their members.

#include <iostream>                 // provides cout, cin
#include "date.h"                   // header file for the class

using namespace std;                // defining the namespace

#define INCREMENT 41                // constant number for incrementing date
#define YEAR1 0                     // sample year 1
#define YEAR2 2019                  // sample year 2
#define MONTH1 14                   // sample month 1
#define MONTH2 2                    // sample month 2
#define DAY1 40                     // sample day 1
#define DAY2 31                     // sample day 2

int main()
{
    dateType date1(3, 15, 2017),    // declaring and initializing first obj
             date2(15, 20, 2018);   // declaring and initializing second obj
             
    // ---date1 content---
    cout << "Date 1: ";
    date1.print();                  // print contents
    cout << endl;

    // displaying calculated data
    cout << " Number of the days passed for Date 1 is " 
        << date1.numberOfDaysPassed() << ".\n";
    cout << " Number of the days left for Date 1 is " 
        << date1.numberOfDaysLeft() << ".\n";
    cout << " The number of days in Date's 1 month is " 
        << date1.getDaysInMonth(date1.getMonth()) << ".\n";
    
    // incrementing date1
    cout << " Adding " << INCREMENT << " days to Date 1, the Date 1 is ";
    date1.incrementDate(INCREMENT); // increment date
    date1.print();                  // print contents
    cout << ".\n";
    cout << " The number of days in Date's 1 new month is " 
        << date1.getDaysInMonth(date1.getMonth()) << ".\n";
    
    // ---date2 content---
    cout << "\n**************************************\n";
    cout << "Date 2: ";
    date2.print();                  // print contents
    cout << endl;

    // using setDate function
    cout << " call setDate function to set the month to " << MONTH1 << ", \n day to "
        << DAY1 << " and year to " << YEAR1 << " for Date 2." << endl;
    date2.setDate(MONTH1, DAY1, YEAR1);           // call to setDate()
    cout << "Date 2's new information is : ";
    date2.print();                                // print contents
    cout << ".\n\n";

    // using setter functions
    cout << " **call setYear, setMonth and setDay functions\n of Date 2 to set the year to "
        << YEAR2 << ", month to " << MONTH2 << "\n and day to " << DAY2 << ".\n\n";
    date2.setMonth(MONTH2);                       // call to setMonth()
    date2.setDay(DAY2);                           // call to setDay()
    date2.setYear(YEAR2);                         // call to setYear()

    // using getter functions
    cout << " **call getYear, getMonth and getDay functions to display the Date 2.**\n";
    cout << " Date 2's new information is : \n";
    cout << " The month is " << date2.getMonth() << ".\n";
    cout << " The day is " << date2.getDay() << ".\n";
    cout << " The year is " << date2.getYear() << ".\n";
}