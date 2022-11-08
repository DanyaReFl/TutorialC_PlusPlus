#include "Header.h"


    rectangle::rectangle()
    {
        colorCentre();
        std::cout << "Enter the width: " ;
        std::cin >> width;
        std::cout << "Enter the height: " ;
        std::cin >> height;
    }

    void rectangle::Square()
    {
        std::cout << "The area of the figure: " << width * height  << std::endl;
    }

    void rectangle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << width << " height " << height << std::endl;
    }
