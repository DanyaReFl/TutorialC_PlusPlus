#include "Header.h"


    Rectangle::Rectangle()
    {
        colorCentre();
        std::cout << "Enter the width: " ;
        std::cin >> width;
        std::cout << "Enter the height: " ;
        std::cin >> height;
    }

    void Rectangle::Square()
    {
        std::cout << "The area of the figure: " << width * height  << std::endl;
    }

    void Rectangle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << width << " height " << height << std::endl;
    }
