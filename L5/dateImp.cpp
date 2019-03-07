//Implementation file date

#include <iostream>                 // provides cout
#include "date.h"                   // class header file

using namespace std;                // defining the namespace

// the main function which sets the date after verifying 
// it for accuracy
void dateType::setDate(int month, int day, int year)
{
    if (year >= 1)                  // is the year positive?
    {
        dYear = year;               // if yes, set it to dYear
    }
    else                            // if not, then...
    {
        dYear = 1900;               // set dYear to 1900
    }

    // is the month less than 13 and greater than 0?
    if (1 <= month && month <= 12)
    {
        dMonth = month;             // if yes, set it to dMonth
    }
    else                            // if not, then...
    {
        dMonth = 1;                 // set dMonth to 1
    }

    switch (dMonth)
    {
    // if month is January, March, May, July, August, October, and December
    case 1: 
    case 3: 
    case 5: 
    case 7:
	case 8: 
    case 10: 
    case 12:
        // is day less than 32 and greater than 0?
        if (1 <= day && day <= 31)
        {
            dDay = day;             // if yes, set it to dDay
        }
        // if not then...
        else
        {
            dDay = 1;               // set dDay to 1
        }
        break;

    // if month is April, June, September, and November
    case 4: 
    case 6: 
    case 9: 
    case 11: 
        // is day less than 31 and greater than 0?
        if (1 <= day && day <= 30)
        {
            dDay = day;             // if yes, set it to dDay
        }
        // if not, then...
        else
        {
            dDay = 1;               // set dDay to 1
        }
        break;

    // for February
    case 2: 
        if (isLeapYear())           // is it leap year?
        {
            // is day less than 30 and greater than 0?
            if (1 <= day && day <= 29)
            {
                dDay = day;         // if yes, set it to dDay
            }
            // if not, then...
            else
            {
                dDay = 1;           // set dDay to 1
            }
        }
        // if not a leap year
        else
        {
            // is day less than 29 and greater than 0?
            if (1 <= day && day <= 28)
            {
                dDay = day;         // if yes, set it to dDay
            }
            // if not, then...
            else
            {
                dDay = 1;           // set dDay to 1
            }
        }
    }
}

// returns the object data members by using pass-by-reference
// parameters.
void dateType::getDate(int& month, int& day, int& year)
{
    month = dMonth;
    day = dDay;
    year = dYear;
}

// const function which prints the obj contents on the screen
void dateType::print() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

// constructor with parameters
dateType::dateType(int month, int day, int year)
{ 
    setDate(month, day, year);	    // call to setDate() function for data entry
}

// the function returns true if dYear is a leap year, otherwise returns false
bool dateType::isLeapYear()
{
    // mathematical logic for determining leap year
    if ((dYear % 4 == 0) && (dYear % 100 != 0 || dYear % 400 == 0))
    {
        return true;
    }
    return false;
}

// the function sets dMonth to the function parameter
// by calling setDate().
void dateType::setMonth(int month)
{
    setDate(month, dDay, dYear);
}

// the function sets dDay to the function parameter
// by calling setDate().
void dateType::setDay(int day)
{
    setDate(dMonth, day, dYear);
}

// the function sets dYear to the function parameter
// by calling setDate().
void dateType::setYear(int year)
{
    setDate(dMonth, dDay, year);
}

// const function which returns dMonth.
int dateType::getMonth() const
{
    return dMonth;
}

// const function which returns dDay.
int dateType::getDay() const
{
    return dDay;
}

// const function which returns dYear.
int dateType::getYear() const
{
    return dYear;
}

// returns the number of days in that month.
int dateType::getDaysInMonth(int month)
{
    int totalDays;              // total number of days

    switch (month)
    {
    // if month is January, March, May, July, August, October, and December
    case 1: 
    case 3: 
    case 5: 
    case 7:
	case 8: 
    case 10: 
    case 12:
        totalDays = 31;
        break;

    // if month is April, June, September, and November
    case 4: 
    case 6: 
    case 9: 
    case 11: 
        totalDays = 30;
        break;

    // if month is February
    case 2: 
        if (isLeapYear())           // is it a leap year?
        {
            totalDays = 29;
        }
        else
        {
            totalDays = 28;
        }
        break;
    }

    return totalDays;
}

// returns the number of days passed since 
// JAN 1 of the year.
int dateType::numberOfDaysPassed()
{
    int totalDaysPassed = 0;        // number of days passed after JAN 1

    // calculating the number of days passed after JAN 1 till the
    // beginning of the current month
    for (int i = 1; i < dMonth; i++)
    {
        totalDaysPassed += getDaysInMonth(i);
    }

    // also add days passed after the start of the current month
    totalDaysPassed += dDay;

    return totalDaysPassed;
}

// returns the number of days left to the end 
// of the year starting from today.
int dateType::numberOfDaysLeft()
{
    // is it a leap year?
    if (isLeapYear())
    {
        // subtract days-passed from 366
        return (366 - numberOfDaysPassed());
    }
    else
    {
        // subtract days-passed from 365
        return (365 - numberOfDaysPassed());
    }
}

// increments the date by the number provided
// by the function parameter. It uses Julian
// Day number and Astronomical formulae to
// perform internal calculations.
void dateType::incrementDate(int days)
{
    // the following are intermediate variables used for calculating
    // Julian Day Number (JDN).
    int a, m, y, leap_days;

    // the following are intermediate variables used for converting JDN
    // back to day, month, and year.
    int p, q, r, s, t, u, v;

    int jdn;                        // Julian Day Number                   
 
    // internal calculations for calculating jdn
    a = ((14 - dMonth) / 12);
    m = (dMonth - 3) + (12 * a);
    y = dYear + 4800 - a;
    leap_days = (y / 4) - (y / 100) + (y / 400);
    jdn = (dDay + (((153 * m) + 2) / 5) + (365 * y) + leap_days - 32045);

    // incrment the date once we have it in JDN format
    jdn += days;

    // the following are internal calculations required for converting JDN
    // back to day, month, and year.
    p = jdn + 68569;
    q = 4 * p / 146097;
    r = p - (146097 * q + 3) / 4;
    s = 4000 * (r + 1) / 1461001;
    t = r - 1461 * s / 4 + 31;
    u = 80 * t / 2447;
    v = u / 11;

    // update obj data members
    dYear = 100 * (q - 49) + s + v;
    dMonth = u + 2 - 12 * v;
    dDay = t - 2447 * u / 80;

    //*********************************************************************
    // ALGORITHM SOURCE
    /*
        Fliegel, H. F., and Van Flandern, T. C., "A Machine Algorithm for
        Processing Calendar Dates," Communications of the Association of
        Computing Machines, vol. 11 (1968), p. 657.
    */
}