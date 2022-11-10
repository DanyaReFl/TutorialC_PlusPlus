#include "header.h"

int main()
{

    srand(time(nullptr));
    int sizeBigBranch = (rand () % 3 ) + 3 ;
    int sizeMiddleBranch = (rand () % 2 ) + 2 ;
    std::string findName;
    Branch *treeElf[5];

    std::cout << "Realization of the village of elves" << std::endl;

    for (auto it : treeElf)
    {
        it = new Branch(nullptr);
        for ( int i (0) ; i < sizeBigBranch ; i ++ )
        {
            Branch BigBranch = it->addChild();
            for (int j (0) ; j < sizeMiddleBranch ; j ++ )
            {
                BigBranch.addChild();
            }
        }
        it->occupyChildren();
    }

    std::cout << "Enter the name of the elf to search for: " ;
    std::cin >> findName ;



    return 0;
}
