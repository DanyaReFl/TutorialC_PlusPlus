#include <iostream>
#include <ctime>
#include <cstring>
#include <execution>
#define FISH 1
#define BOOTS 2

void setArray(int array[])
{
    int numberArray;
    array[std::rand()%9] = FISH;
    for (uint8_t i(0); i<3 ;)
    {
        numberArray=std::rand() % 9;
        if ((array[numberArray] != FISH) && (array[numberArray] != BOOTS) )
        {
            array[numberArray]=BOOTS;
            i++;
        }
    }
}

/*void printArray(int array[])
{
    for (uint8_t i (0) ; i<9 ; i++ )
    {
        if ( (i%3)==0 ) std::cout << std::endl;
        std::cout<< array[i] << "\t";
    }
}*/ //Output function

    int main() {
    const uint8_t SIZE_ARRAY = 9;
    int fishingSector , numberMoves{1};
    std::srand(std::time(nullptr));

    std::cout << "Fishing game." << std::endl;
    int mass [SIZE_ARRAY];

    while(true)
    {
        std::memset(mass,0,SIZE_ARRAY);
        setArray(mass);
        std::cout << "Enter the fishing sector(1-9): " ;
        std::cin >> fishingSector;
        try {
            if (mass[fishingSector]==BOOTS) throw "BOOTS";
            else if (mass[fishingSector]==FISH) throw "FISH";
        }
        catch (const char * x){
            if (x=="BOOTS") std::cerr << "You caught the boot. \nYou lose." << std::endl;
            else if (x=="FISH") std::cerr << "Have you caught a fish. \nIt took you " << numberMoves
            << " moves."<< std::endl;
            break;
        }
        numberMoves++;
    }


    return 0;
}
