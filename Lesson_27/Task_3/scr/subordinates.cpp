#include "header.h"

subordinates::subordinates()
{
    std::cout << "Enter the employee's name: " ;
    std::cin >> name;
}

void subordinates::setSubTask () {
    subTask = static_cast<task>(rand() % 3 + 1) ;
    switch (subTask)
    {
        case 1 : std::cout << "Employee "<< this->name <<" is working on a task: A" << std::endl; break;
        case 2 : std::cout << "Employee "<< this->name <<" is working on a task: B" << std::endl; break;
        case 3 : std::cout << "Employee "<< this->name <<" is working on a task: C" << std::endl; break;
    }

}
