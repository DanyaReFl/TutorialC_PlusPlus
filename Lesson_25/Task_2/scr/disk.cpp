#include "head.h"

void save()
{
    auto mass = read();
    std::ofstream file("data.txt",std::ios::trunc);
    assert(file.is_open());
    for(auto it : *mass)
    {
        file<<it<<std::endl;
    }
    file.close();
}

void load()
{
    auto mass = read();
    double num;
    std::ifstream file("data.txt");
    assert(file.is_open());
    mass->clear();
    do
    {
        file>>num;
        mass->push_back(num);
    }
    while(!file.eof());
    mass->pop_back();
    file.close();
}