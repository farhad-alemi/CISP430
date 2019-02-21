// Lab3 Programming Exercise

#include <iostream>                     // provides input/output functions
#include <iomanip>                      // provides fixed and showpoint
#include "circleType.h"                 // header file which contains class declaration

using namespace std;

int main()
{
    circleType circle1(3, 2.5, 4);      // declaring and defining object of type circleType
    circleType circle2;                 // defining object of type circleType

    // When the showpoint format flag is set, the decimal point is always written
    // for floating point values inserted into the stream (even for those whose
    // decimal part is zero).
    cout << fixed << showpoint;
    cout << setprecision(2);

    cout << "***** Circle 1 *****" << endl;
    circle1.print();
    cout << endl;

    // defining circle2
    circle2.setPoint(-2.5, 7);
    circle2.setRadius(4);

    cout << "***** Circle 2 *****" << endl;
    circle2.print();
    cout << endl;

    double x, y;                            // x and y coordinates for circle 3
    double r;                               // radius for circle 3

    circleType circle3;                     // declaring circle3
    
    cout << "Enter x Coordinate of the center: ";
    cin >> x;
    cout << endl;

    cout << "Enter y Coordinate of the center: ";
    cin >> y;
    cout << endl;

    cout << "Enter radius: ";
    cin >> r;
    cout << endl;

    // defining circle3
    circle3.setPoint(x, y);
    circle3.setRadius(r);

    cout << "***** Circle 3 *****" << endl;
    circle3.print();
    cout << endl;

    system("pause");                // pauses the command-prompt before the exit

    return 0;
}