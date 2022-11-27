#include "Rectangle.h"

Rectangle::Rectangle(double numW, double numH):width(numW),height(numH) {}

double Rectangle::square()
{
    return height*width;
}

BoundingBoxDimensions Rectangle::dimensions()
{
    BoundingBoxDimensions str_Rectangle = {width,height};
    return  str_Rectangle;
}

std::string Rectangle::type()
{
    return "Rectangle";
}