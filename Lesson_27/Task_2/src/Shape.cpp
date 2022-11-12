#include "Header.h"

void Shape::colorCentre()
{
    int number;
    while (true)
    {
        std::cout << "Enter the shape color(0-none,1-red,2-orange,3-yellow,4-green,5-cyan,6-blue,7-purple). Enter a number: ";
        std::cin >> number;
        if ( ( number >= 0 ) && ( number <= 7 ) ) break;
        else std::cout << "There is no such color." << std::endl;
    }
    this->colorShape = static_cast<Color>(number);
    std::cout << "Enter the center of the shape:" << std::endl;
    std::cout << "X= ";
    std::cin >> this->centreShape.x;
    std::cout << "Y= ";
    std::cin >> this->centreShape.y;
};