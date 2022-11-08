#include "Header.h"

    circle::circle()
    {
        colorCentre();
        std::cout << "Enter the radius: " ;
        std::cin >> radius;
    }

    void circle::Square()
    {

        std::cout << "The area of the figure: " << std::atan(1) * 4 * radius << std::endl;
    }

    void circle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << 2*radius << " height " << 2*radius << std::endl;
    }
