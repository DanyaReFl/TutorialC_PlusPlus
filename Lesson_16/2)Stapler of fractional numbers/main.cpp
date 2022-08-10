#include <iostream>

int main() {

    std::string integer, fractional ;
    double floating;


    std::cout << "Enter the integer part of the number: " ;
    std::cin >>integer;
    std::cout << "Enter the fractional part of the number: " ;
    std::cin >>fractional;
    floating = stod((integer + "." + fractional));
    std::cout << floating;

    return 0;
}
