#include <iostream>
#define Monday 1
#define Tuesday 2
#define Wednesday 3
#define Thursday 4
#define Friday 5
#define Saturday 6
#define Sunday 7
#define print(x) std::cout << #x << std::endl;

int main() {

    int number;

    std::cout << "Enter the day of the week (1-7): ";
    std::cin >> number;

    switch (number)
    {
        case Monday: print(Monday) ; break ;
        case Tuesday: print(Tuesday) ; break ;
        case Wednesday: print(Wednesday) ; break ;
        case Thursday: print(Thursday) ; break ;
        case Friday: print(Friday) ; break ;
        case Saturday: print(Saturday) ; break ;
        case Sunday: print(Sunday) ; break ;
        default : std::cout << "Error.";
    }


    return 0;
}
