#include "head.h"

void print()
{
    auto mass=read();
    for (auto it : *mass)
    {
        std::cout << it << " ";
    }
    std::cout<<std::endl;
}