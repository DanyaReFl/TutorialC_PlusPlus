#include "head.h"

std::vector<double> mass{0};

void write()
{
    mass.clear();
    int number;
    std::cout << "Enter 8 numbers into the buffer" ;
    for(int i(0) ; i < 8 ; i++)
    {
        std::cin >> number;
        mass.push_back(number);
    }
}

std::vector<double>* read() {
    return &mass;
}
