// Implementation file circleTypeImp.cpp

#include <iostream>                     // provides input/output functions
#include "circleType.h"                 // header file which includes class declaration

using namespace std;

// const function which outputs the object data
void circleType::print() const
{
    cout << "Center: ";
    pointType::print();                     // call to parent's overridden print()
    cout << endl;
    cout << "Radius: " << radius << endl;
    cout << "Circumference: " << getCircumference() << endl;
    cout << "Area: " << getArea() << endl;
}

// setter function which assigns the function 
// parameter to the class variable
void circleType::setRadius(double r)
{
    radius = r;
}

// const getter function which returns radius
double circleType::getRadius() const
{
    return radius;
}

// const getter function which calculates the circumference, for
// the circle, on the fly and returns it
double circleType::getCircumference() const
{
    return (2 * 3.1416 * radius);
}

// const getter function which calculates the area, for
// the circle, on the fly and returns it
double circleType::getArea() const
{
    return (3.1416 * radius * radius);
}

// constructor which calls the parent constructor (in the initialization list)
// and assigns the function parameter to the member variable
circleType::circleType(double x, double y, double r) :pointType(x,y)
{
    radius = r;
}