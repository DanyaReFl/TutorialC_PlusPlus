#include "head.h"

void compute()
{
    double sum{0};
    auto buff=read();
    for (auto it : *buff)
    {
        sum+=it;
    }
    std::cout << "Buffer amount: " << sum << std::endl;
}
