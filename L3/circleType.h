// Class circleType

#ifndef H_CircleType        // if H_CircleType is not defined,
#define H_CircleType        // then define H_CircleType

#include "pointType.h"      // include the pointType header file

// class circleType inherits pointType
class circleType: public pointType
{
public:
    void print() const;
    void setRadius(double r);
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
    circleType(double x = 0.0, double y = 0.0, double r = 0.0);

protected:
    double radius;          // circle radius
};

#endif                      // end macro definition