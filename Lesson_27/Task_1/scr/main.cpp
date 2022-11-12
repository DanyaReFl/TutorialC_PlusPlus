#include "header.h"

int main()
{

    srand(time(nullptr));
    int sizeBigBranch = ( rand () % 3 ) + 3 ;
    int sizeMiddleBranch = ( rand () % 2 ) + 2 ;
    unsigned short const SIZE = 5 ;
    std::string findName;
    std::cout << "Realization of the village of elves" << std::endl;

    Branch **bigBranch;
    bigBranch = new Branch*[SIZE];

    for (int i (0) ; i < SIZE ; i ++ )
    {
        bigBranch[i] = new Branch[sizeBigBranch];
        for (int j (0) ; j < sizeBigBranch ; j ++ )
        {
            for (int k (0) ; k < sizeMiddleBranch ; k ++ ) bigBranch[i][j].addChild();
            bigBranch[i][j].occupyChildren();
        }
    }


    std::cout << "Enter the name of the elf to search for: " ;
    std::cin >> findName ;

    for (int i (0) ; i < SIZE ; i ++ )
    {
        for (int j(0); j < sizeBigBranch; j++)
        {
            Branch *findBranch = bigBranch[i][j].findElfBranch(findName);
            if (findBranch != nullptr)
            {
                std::cout << findBranch->countNeighbors();
                break;
            }
        }
    }



    return 0;
}
