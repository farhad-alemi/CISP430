// Program       :   CISP430V4L1.cpp
// Author        :   Farhad Alemi
// Due Date      :   February 11th, 2019
// Description   :   This .cpp file contains the definition for class romanType
//                   which converts numeric value in Roman numerals to a numeric
//                   value in Arabic numerals.

#include <iostream>                     // provides cin, cout
#include <string>                       // provides string functions

using namespace std;                    // standard namespace

// This class converts a numeric value in Roman numerals to a numeric
// value in Arabic numerals. It does so by utilizing a string and an
// int member variable. It also has several getter & setter functions.
class romanType
{
public:
    void setRoman(string);
    void romanToDecimal();
    void printDecimal() const;
    void printRoman() const;
    romanType();
    romanType(string);

private:
    string romanNum;                    // the value in Roman numerals
    int    decimalNum;                  // the value in Arabic numerals
};

// This function prints the value in Arabic numerals.
void romanType::printDecimal() const
{
    cout << decimalNum;
}

// This function prints the value in Roman numerals.
void romanType::printRoman() const
{
    cout << romanNum;
}

// A setter function which assigns the member romanNum to the
// function parameter. It also calls the main converter function.
void romanType::setRoman(string rString)
{
    romanNum = rString;
    romanToDecimal();                   // call to the main converter function.
}

// This is the main converter function. It utilizes a switch-block
// nested inside a for-loop.
void romanType::romanToDecimal()
{
    int sum = 0;                        // intermediate variable for storing 
                                        // the equivalent Arabic numeral value

    int length = romanNum.length();     // the length of the Roman numeral

    int i;                              // int variable used in the for-loop. 

    int previous = 1000;                // the logic assumes that the previous
                                        // character had a value of 1000. It does
                                        // so because we don't need to subtract
                                        // anything from the first character in 
                                        // Roman numerals.

    for (i = 0; i < length; i++)
    {
        switch (romanNum[i])            // iterating through the string as if it
                                        // is an array of char(s).
        {
        case'M':
            sum += 1000;                // add the equivalent value of 'M' to sum.

            if (previous < 1000)        // if |previous character| < |'M'|,
            {
                sum -= 2 * previous;    // then subtract 2*it from sum.
            }
            previous = 1000;            // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'M'.
            break;

        case 'D':
            sum += 500;                 // add the equivalent value of 'D' to sum.
            if (previous < 500)         // if |previous character| < |'D'|,
            {
                sum -= 2 * previous;    // then subtract 2*it from sum.
            }
            previous = 500;             // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'D'.
            break;

        case 'C':
            sum += 100;                 // add the equivalent value of 'C' to sum.
            if (previous < 100)         // if |previous character| < |'C'|,
            {
                sum -= 2 * previous;    // then subtract 2*it from sum.
            }
            previous = 100;             // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'C'.
            break;

        case 'L':
            sum += 50;                  // add the equivalent value of 'L' to sum.
            if (previous < 50)          // if |previous character| < |'L'|,
            {
                sum -= 2 * previous;    // then subtract 2*it from sum.
            }
            previous = 50;              // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'L'.
            break;

        case 'X':
            sum += 10;                  // add the equivalent value of 'X' to sum.
            if (previous < 10)          // if |previous character| < |'X'|,
            {
                sum -= 2 * previous;    // then subtract 2*it from sum.
            }
            previous = 10;              // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'X'.
            break;

        case 'V':
            sum += 5;                   // add the equivalent value of 'V' to sum.
            if (previous < 5)           // if |previous character| < |'V'|,
            {
                sum -= 2 * previous;    // / then subtract 2*it from sum.
            }
            previous = 5;               // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'V'.
            break;

        case 'I':
            sum += 1;                   // add the equivalent value of 'I' to sum.

            previous = 1;               // getting ready for next iteration by 
                                        // assigning previous to equivalent value
                                        // of 'I'.
        }
    }

    decimalNum = sum;                   // the final calculated value in Arabic
                                        // numerals.
}

// Argument-less costructor which initializes the member variables.
romanType::romanType()
{
    romanNum = 'I';                     // initialized to 1 since Roman numerals
                                        // do not have 0.
    decimalNum = 1;
}

// Constructor which assigns the member variable to the function parameter.
romanType::romanType(string rString)
{
    romanNum = rString;                 // initialzes the function parameter.
    romanToDecimal();                   // call to converter function.
}
    
int main()
{
    // instantiating an object of type romanType
    romanType roman;

    string romanString;                 // intermediate variable for storing user-input.

    cout << "Enter a roman number: ";
    cin >> romanString;
    cout << endl;

    // call to setRoman() member function.
    roman.setRoman(romanString);

    cout << "The equivalent of the Roman numeral " << romanString << " is ";
    roman.printDecimal();               // call to the printDecimal() member function.
    cout << endl;
    system("PAUSE");                    // pause the command-prompt window

    return 0;
}