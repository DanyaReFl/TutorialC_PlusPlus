#include "Header.h"


    Square::Square ()
    {
        colorCentre();
        std::cout << "Enter the edge: " ;
        std::cin >> edge;
    }

    void Square::SquareS()
    {
        std::cout << "The area of the figure: " << edge * edge  << std::endl;
    }

    void Square::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << edge << " height " << edge << std::endl;
    }

