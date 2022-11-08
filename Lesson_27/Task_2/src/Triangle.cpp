#include "Header.h"



    triangle::triangle ()
    {
        colorCentre();
        std::cout << "Enter the edge: " ;
        std::cin >> edge;
    }

    void triangle::Square()
    {
        std::cout << "The area of the figure: " << edge * edge * std::sqrt(3) / 4 << std::endl;
    }

    void triangle::desShape()
    {
        std::cout << "Rectangle describing the shape: width " << edge << " height " << edge * std::sqrt(3) / 2 << std::endl;
    }

