#include "header.h"

HeadCompany::HeadCompany()
{
    std::cout << "Enter the name of the head of the company: ";
    std::cin >> name;

}

int HeadCompany::getInstructions()
{
    int number;
    std::cout << "Enter an integer identifier: ";
    std::cin >> number;
    return number;
}

bool HeadCompany::getAllTask(int size , middleManager *man , int people )
{
    int sumTask{0};
    for (int i (0) ; i < size ; i++ )
    {
        sumTask+=man[i].getFreeEmployee();
    }
    if ( sumTask == ( size * people ) ) return false;
    else true ;
}