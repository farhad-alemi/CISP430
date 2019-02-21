//Class pointType

#ifndef H_PointType         // if H_PointType is not defined,
#define H_PointType         // then define H_PointType

class pointType
{
public:
    void setPoint(double x, double y);
    void print() const;
    double getX() const;
    double getY() const;
    pointType(double x = 0.0, double y = 0.0);

protected:
    double xCoordinate;     // x-coordinate of the point
    double yCoordinate;     // y-coordinate of the point
};

#endif                      // end macro definition