// Program       :   CISP430L4_MainProgram.cpp
// Author        :   Farhad Alemi
// Due Date      :   March 4th, 2019
// Description   :   This is a driver program for dateType class. It creates
//                   4 objects of the class and then displays their content.

#include <iostream>                 // provides cout, cin
#include "date.h"                   // header file for the class

using namespace std;                // defining the namespace

int main()
{
    int      month,                 // temp variable for storing month
             day,                   // temp variable for storing day
             year;                  // temp variable for storing year

    dateType date1(3, 15, 2017),    // declaring and initializing first obj
             date2(15, 20, 2018),   // declaring and initializing second obj
             date3(2, 30, 2019),    // declaring and initializing third obj
             date4;                 // declaring fourth obj

    cout << "Date 1: ";
    date1.printDate();              // print contents
    cout << endl;

    cout << "Date 2: ";
    date2.printDate();              // print contents
    cout << endl;

    cout << "Date 3: ";
    date3.printDate();              // print contents
    cout << endl;

    // getting data for obj date4
    cout << "Enter month day year: ";
    cin >> month;
    cin >> day;
    cin >> year;

    // passing the data to setDate() function which sets the data
    // after verifying it
    date4.setDate(month, day, year);

    cout << "Date 4: ";
    date4.printDate();              // print contents
}