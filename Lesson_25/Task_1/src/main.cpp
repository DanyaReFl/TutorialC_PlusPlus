#include <iostream>
#include "header.h"


int main() {

    coordinates sur{};
    coordinates sub{};

    std::cout << "You are welcomed , by the simulator of operations!" << std::endl;

    std::cout << "Enter the coordinates for working with the scalpel: " << std::endl;
    std::cout << "A(X,Y):= ";
    std::cin >> sur.X >> sur.Y;
    std::cout << "O(X,Y):= ";
    std::cin >> sur.X_0 >> sur.Y_0;
    scalpel(sur);

    std::cout << "Enter the hemostat coordinates: " << std::endl;
    hemostat();

    std::cout << "Enter the tweezers coordinates: " << std::endl;
    tweezers();

    while (true)
    {
        std::cout << "Enter the coordinates for working with the suture: " << std::endl;
        std::cout << "A(X,Y):= ";
        std::cin >> sub.X >> sub.Y;
        std::cout << "O(X,Y):= ";
        std::cin >> sub.X_0 >> sub.Y_0;
        if ((sub.X == sur.X) && (sub.Y == sur.Y) && (sub.X_0 == sur.X_0) && (sub.Y_0 == sur.Y_0)) { suture(sur); break ;}
    }

    std::cout << "The operation was completed successfully!" ;

    return 0;
}
