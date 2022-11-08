#include "Header.h"


    square::square ()
    {
        colorCentre();
        std::cout << "Enter the edge: " ;
        std::cin >> edge;
    }

    void square::Square()
    {
        std::cout << "The area of the figure: " << edge * edge  << std::endl;
    }

    void square::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << edge << " height " << edge << std::endl;
    }

