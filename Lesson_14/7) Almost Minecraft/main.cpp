#include <iostream>
#define SIZE 5

void horizontalSlice(int level[][SIZE][SIZE*2],int slice)
{
    for (int i (0) ; i<SIZE ; i++)
    {
        for (int j(0); j < SIZE; j++)
        {
            if (level[i][j][slice])
                std::cout << "1 ";
            else std::cout << "0 ";
        }
        std::cout<<std::endl;
    }
}

int main() {

    int massLevel[SIZE][SIZE][SIZE*2]{0};
    int level,slice;

    std::cout << "You are welcomed by the game \"Almost Minecraft\"!" << std::endl;
    std::cout << "Input matrix of heights: "<< std::endl;
    for (int i (0) ; i<SIZE ; i++)
    {

        for (int j (0) ; j<SIZE ; j++)
        {
            std::cout <<"Matrix["<<i+1<<"]["<<j+1<<"]=";
            std::cin >> level;
            if (level >9 || level<0)
            {
                std::cout << "Error." << std::endl;
                j--;
                continue;
            }
            for (int k (0); k<=level; k++)
            {
                massLevel[i][j][k] = 1;
            }
        }
    }
    do
    {
        std::cout << "input slice:";
        std::cin >> slice;
        if (slice > 9 || slice < 0)
        {
            std::cout << "Input Error.";
            continue;
        }
        horizontalSlice(massLevel,slice);
    } while (slice!=-1);

    return 0;
}
