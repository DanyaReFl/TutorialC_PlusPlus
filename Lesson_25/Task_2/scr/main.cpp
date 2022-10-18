#include <iostream>
#include "head.h"

int main()
{
    std::string command;

    std::cout << "You are welcomed , by the computer simulator project!" << std::endl;

    while (true)
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "sum") {
            compute();
        } else if (command == "save") {
            save();
        } else if (command == "load") {
            load();
        } else if (command == "display") {
            print();
        } else if (command == "input") {
            readln();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Error. Please repeat the input." << std::endl;
        }
    }

    return 0;
}
