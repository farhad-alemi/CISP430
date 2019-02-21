// Implementation File pointTypeImp.cpp

#include <iostream>
#include "pointType.h"

using namespace std;

// this function assigns the parameters to the 
// member variables
void pointType::setPoint(double x, double y)
{
    xCoordinate = x;
    yCoordinate = y;
}

// this function prints the member variables in a
// specific format
void pointType::print() const
{
    cout << "(" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

// const getter function which returns xCoordinate
double pointType::getX() const
{
    return xCoordinate;
}

// const getter function which returns yCoordinate
double pointType::getY() const
{
    return yCoordinate;
}

// constructor which assigns the parameters to the
// member variables
pointType::pointType(double x, double y)
{
    xCoordinate = x;
    yCoordinate = y;
}