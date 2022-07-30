#include <iostream>
#define SIZE 5

int main() {

    int snake[SIZE][SIZE];
    std::cout << "The program outputs a sequence in the form of a snake!" << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            //snake[i][j] = (i * SIZE + j) * (i % 2) + (i * SIZE + 4 - j) * ((i + 1) % 2);
            snake[i][j] = (i * SIZE + j) * ((i + 1) % 2)/*algorithm for even(i)*/
                    + (i * SIZE +4- j) * (i % 2);/*algorithm for odd(i)*/
            std::cout << snake[i][j] <<"  " ;
        }
        std::cout<<std::endl;
    }

    return 0;
}
