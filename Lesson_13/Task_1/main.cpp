#include <iostream>
#include <vector>

int main() {

    int count,numberDel;

    std::cout << "The program removes the entered number from the vector." << std::endl;
    std::cout << "Enter the numbers of elements in the vector: ";
    std::cin >> count;

    std::vector<int> mass(count);

    for (int i(0); count >i ; i++)
    {
        std :: cout << "Input numbers: ";
        std::cin >> mass[i];
    }

    std:: cout << "Input number to delete: ";
    std:: cin >> numberDel;

    for (int j(0) ; count >j ; )
    {
        if (mass[j]==numberDel) {
            std::swap(mass[j],mass[count-1]);
            mass.pop_back();
            count--;
        }
        else {
        std :: cout << mass[j];
        j++;}
    }

    return 0;
}
