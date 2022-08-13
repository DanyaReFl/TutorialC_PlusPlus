#include <iostream>

int ins;

int rabbit (const int step ,const int i=3)
{
    return step==0 ? 1 : step<0 || i<1? 0 : rabbit(step-i ,ins) + rabbit(step, i-1);
}

int main() {

    int step;

    std::cout << "The program counts the number of options to jump up to n steps."<< std::endl;
    std::cout << "Enter the step number and step K: ";
    std::cin >> step >> ins;
    std::cout << rabbit(step,ins);

    return 0;
}
