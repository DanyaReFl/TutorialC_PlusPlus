#include <iostream>
#include <ctime>
#include <fstream>

int main() {

    std::ofstream file("File.txt",std::ios::trunc);
    int width,height;
    if (!file.is_open()) std::cout << "Opening error" << std::endl;
    std::srand(std::time(nullptr));
    std::cout << "The program draws a drawing from 0 and 1." << std::endl;
    std::cout << "Enter the width of the canvas: ";
    std::cin >> width;
    std::cout << "Enter the height of the canvas: ";
    std::cin >> height;

    for (int i(0) ; i<height ; i++)
    {
        file<<(rand()%2)<<" ";
        for(int j(0) ; j<width ; j++)
        {
            file<<(rand()%2)<<" ";
        }
        file<<std::endl;
    }
    file.close();
    return 0;
}
