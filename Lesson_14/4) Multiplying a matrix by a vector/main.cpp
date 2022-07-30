#include <iostream>
#define SIZE 4

int main() {

    float matrixA[SIZE][SIZE], vectorB[SIZE], vectorC[SIZE]={0,0,0,0};

    std::cout << "The program calculates the product of a matrix by a vector." << std::endl;
    std::cout << "Enter the matrix elements :"<<std::endl;

    for (int i(0) ; i<SIZE ; i++ )
    {
        for (int j(0) ; j<SIZE ; j++ )
        {
            std::cout << "Matrix["<<i<<"]["<<j<<"]= ";
            std::cin >> matrixA[i][j];
        }
    }
    std::cout << "Enter the vector elements :"<<std::endl;
    for (int i(0) ; i<SIZE ; i++)
    {
        std::cout << "Vector["<<i<<"]= ";
        std::cin >> vectorB[i];
    }

    for (int i(0) ; i<SIZE ; i++ )
    {
        for (int j(0) ; j<SIZE ; j++ )
        {
            vectorC[i]+=(matrixA[i][j]*vectorB[j]);
        }
    }
    std::cout << "The result of the product :"<<std::endl;
    for (int i(0) ; i<SIZE ; i++)
    {
        std::cout << "Vector["<<i<<"]= "<<vectorC[i]<<std::endl;

    }

    return 0;
}
