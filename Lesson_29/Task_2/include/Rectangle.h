#include "header.h"

class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double numW , double numH);
    double square();
    BoundingBoxDimensions dimensions();
    std::string type();
};