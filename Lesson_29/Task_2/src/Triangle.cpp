#include "Triangle.h"

Triangle::Triangle(double numA, double numB, double numC):a(numA),b(numB),c(numC){}

double Triangle::square()
{
    return sqrt ( p * (p - a) * (p - b) * (p - c) );
}

BoundingBoxDimensions Triangle::dimensions()
{
    double rad = a * b * c / ( 4 * sqrt( p * (p - a) * (p - b) * (p - c) ) );
    BoundingBoxDimensions str_Triangle = { rad * 2 , rad * 2 };
    return  str_Triangle;
}

std::string Triangle::type()
{
    return "Triangle";
}