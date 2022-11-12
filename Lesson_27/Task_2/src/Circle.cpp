#include "Header.h"

    Circle::Circle()
    {
        colorCentre();
        std::cout << "Enter the radius: " ;
        std::cin >> radius;
    }

    void Circle::Square()
    {

        std::cout << "The area of the figure: " << std::atan(1) * 4 * radius << std::endl;
    }

    void Circle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << 2*radius << " height " << 2*radius << std::endl;
    }
