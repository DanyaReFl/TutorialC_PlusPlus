#include <iostream>

int rabbit (const int n, int &count)
{
    return n==0 ? ++count : n<0  ? 0 : rabbit(n-3, count) + rabbit(n-2, count)+rabbit(n-1, count);
}

int main() {

    int step,count(0);

    std::cout << "The program counts the number of options to jump up to n steps."<< std::endl;
    std::cout << "Enter the step number: ";
    std::cin >> step ;
    rabbit(step,count);
    std::cout << count;

    return 0;
}
