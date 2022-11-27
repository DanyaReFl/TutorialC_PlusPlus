#include "header.h"

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(int num);
    double square();
    BoundingBoxDimensions dimensions();
    std::string type();
};
