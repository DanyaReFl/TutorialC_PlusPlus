#include "header.h"

class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;
    double p = ( a + b + c ) / 2 ;
public:
    Triangle(double numA , double numB ,double numC);
    double square();
    BoundingBoxDimensions dimensions();
    std::string type();
};