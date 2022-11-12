#include "Header.h"



    Triangle::Triangle ()
    {
        colorCentre();
        std::cout << "Enter the edge: " ;
        std::cin >> edge;
    }

    void Triangle::Square()
    {
        std::cout << "The area of the figure: " << edge * edge * std::sqrt(3) / 4 << std::endl;
    }

    void Triangle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << edge << " height " << edge * std::sqrt(3) / 2 << std::endl;
    }

