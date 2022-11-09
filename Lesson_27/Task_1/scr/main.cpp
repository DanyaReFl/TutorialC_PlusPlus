#include "header.h"

int main()
{

    srand(time(nullptr));
    std::string findName;

    std::cout << "Realization of the village of elves" << std::endl;

    branch *tree = new branch [5];
    for (int i(0) ; i<5 ; i++ )
    {
        tree->setChildrenAndParent();
        tree++;
    }

    std::cout << "Enter a name to search for the elf: " ;
    std::cin >> findName ;

    for (int j(0) ; j<5 ; j++ )
    {
        branch *find = tree->findName(findName);
        if ( find == nullptr )
        {
            std::cout << "Number of elf neighbors :" << find->getCount() << std::endl;
            break;
        }
        tree++;
    }

    return 0;
}
