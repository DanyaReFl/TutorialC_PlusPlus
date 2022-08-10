#include <iostream>
#include <sstream>


int main() {


    std::string buffer;

    double number1,number2;
    char action;

    std::cout << "Calculator program: enter two numbers and an operation, without spaces." << std::endl;
    std::cin >> buffer;
    std::stringstream buffer_stream(buffer);
    buffer_stream >> number1 >> action >> number2;

    switch (action)
    {
        case '+': std::cout << number1 <<"+"<< number2 <<"=" <<number1+number2; break;
        case '-': std::cout << number1 <<"-"<< number2 <<"=" <<number1-number2; break;
        case '*': std::cout << number1 <<"*"<< number2 <<"=" <<number1*number2; break;
        case '/': std::cout << number1 <<"/"<< number2 <<"=" <<number1/number2; break;
        default: std::cerr <<"Error.";
    }

    return 0;
}
