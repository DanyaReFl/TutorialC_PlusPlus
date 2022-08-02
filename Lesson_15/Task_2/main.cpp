#include <iostream>

int main() {

    const short SIZE = 5;
    int mass[SIZE] ={2, 7, 11, 15,-8};
    int number,iNumber,jNumber;

    std::cout << "The program outputs two numbers , which in total are equal to the specified number." << std::endl;
    std::cout << "Enter the specified number: ";
    std::cin >> number;

    for (int i(0) ; (i<SIZE)  ; i++ )
    {
        for (int j(0) ; j<SIZE ; j++ )
        {
            if (mass[i]+mass[j]==number)
            {
                iNumber=i;
                jNumber=j;
                break;
            }
        }
    }
    std::cout << "Two numbers from the array: "<<mass[iNumber]<<"  "<<mass[jNumber];

    return 0;
}
