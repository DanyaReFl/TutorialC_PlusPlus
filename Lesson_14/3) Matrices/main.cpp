#include <iostream>
#define EXIT 0
#define EQUAL 1

bool Comparison(int firstMatrix[][4], int secondMatrix[][4])
{
    for (int i(0) ; i<4 ; i++)
    {
        for (int j(0) ; j<4 ; j++ )
        {
            if (firstMatrix[i][j]!=secondMatrix[i][j]) return EXIT;
        }

    }
    return EQUAL;
}

void transformation(int firstMatrix[][4])
{
    for (int i(0) ; i<4 ; i++)
    {
        for (int j(0) ; j<4 ; j++ )
        {
            if (j!=i) firstMatrix[i][j]=0;
        }

    }
}

int main() {

    int firstMatrix[4][4],secondMatrix[4][4];

    std::cout << "The program compares matrices and brings the matrix to a diagonal form if they are equal." << std::endl;
    for (int i(0) ; i<4 ; i++)
    {
        for (int j(0) ; j<4 ; j++ )
        {
            std::cout << "FirstMatrix["<<i+1<<"]["<<j+1<<"]=";
            std::cin>>firstMatrix[i][j];
        }

    }
    for (int i(0) ; i<4 ; i++)
    {
        for (int j(0) ; j<4 ; j++ )
        {
            std::cout << "SecondMatrix["<<i+1<<"]["<<j+1<<"]=";
            std::cin>>secondMatrix[i][j];
        }

    }
    if (Comparison(firstMatrix,secondMatrix)==EQUAL)
    {
        transformation(secondMatrix);
        std::cout<< "Diagonal matrix."<<std::endl;
        for (int i(0) ; i<4 ; i++)
        {
            for (int j(0) ; j<4 ; j++ )
            {
                std::cout << secondMatrix[i][j] <<" ";

            }
        std::cout<<std::endl;
        }
    }
    return 0;
}
