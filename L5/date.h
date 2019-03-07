#ifndef date_H
#define date_H

//************************************************************
// 
// class dateType
// This class specifies the members to implement a date.
//************************************************************


class dateType
{
public:
    void setDate(int month, int day, int year);
      //Function to set the date
      //Data members dMonth, dDay, and dYear are set 
      //according to the parameters
      //Postcondition: dMonth = month; dDay = day;
      //    dYear = year

    void getDate(int& month, int& day, int& year);
      //Function to return the date
      //Postcondition: month = dMonth; day = dDay;
      //    year = dYear;

	bool isLeapYear(); 
      //Function to check if a year is a leap year
      //Return true if a year is a leap year, false otherwise

    void print() const;
      //Function to output the date in the form mm-dd-yyyy.

    dateType(int month = 1, int day = 1, int year = 1900);
      //Constructor to set the date
      //Data members dMonth, dDay, and dYear are set 
      //according to the parameters
      //Postcondition: dMonth = month; dDay = day; 
      //    dYear = year
      //If no values are specified, the default values are 
      //used to initialize the data members.

    void setMonth(int month);
      // assigns a (valid) function parameter to 
      // dMonth by calling setDate().

    void setDay(int day);
      // assigns a (valid) function parameter to 
      // dDay by calling setDate().

    void setYear(int year);
      // assigns a (valid) function parameter to 
      // dYear by calling setDate().

    int getMonth() const;
      // const function which returns dMonth.

    int getDay() const;
      // const function which returns dDay.

    int getYear() const;
      // const function which returns dYear.

    int getDaysInMonth(int);
      // returns the number of days in that month.

    int numberOfDaysPassed();
      // returns the number of days passed since 
      // JAN 1 of the year.

    int numberOfDaysLeft();
      // returns the number of days left to the end 
      // of the year starting from today.

    void incrementDate(int days);
      // increments the date by the number provided
      // by the function parameter. It uses Julian
      // Day number and Astronomical formulae to
      // perform internal calculations.

private:
    int dMonth;	// variable to store month
    int dDay;   // variable to store day
    int dYear;  // variable to store year
};

#endif