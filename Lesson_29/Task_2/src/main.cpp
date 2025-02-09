#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void printParams(Shape *shape)
{
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width: " << shape->dimensions().width << std::endl;
    std::cout << "Height: " << shape->dimensions().height << std::endl;
}

int main()
{
    std::cout << "The program \"Shape Interface\"!" << std::endl;
    Triangle t(3,4,5);
    printParams(&t);

    return 0;
}
