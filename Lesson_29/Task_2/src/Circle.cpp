#include "Circle.h"

Circle::Circle(int num):radius(num){};

double Circle::square()
{
    return M_PI*radius ;
}

BoundingBoxDimensions Circle::dimensions()
{
    BoundingBoxDimensions str_Circle = { radius*2 , radius*2 };
    return str_Circle ;
}

std::string Circle::type()
{
    return "Circle" ;
}