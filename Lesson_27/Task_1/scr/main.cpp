#include "header.h"

int main()
{

    srand(time(nullptr));
    std::string findName;

    std::cout << "Realization of the village of elves" << std::endl;

    branch *tree = new branch [5];
    for (int i(0) ; i<5 ; i++ )
    {
        (tree+i)->setChildrenAndParent();
    }

    std::cout << "Enter a name to search for the elf: " ;
    std::cin >> findName ;

    for (int j(0) ; j<5 ; j++ )
    {
        branch *find = (tree + j)->findName(findName);
        if ( find != nullptr )
        {
            std::cout << "Number of elf neighbors :" << find->getCount() << std::endl;
            break;
        }
    }

    delete []tree;

    return 0;
}
