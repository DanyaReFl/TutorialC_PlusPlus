#include "header.h"

MiddleManager::MiddleManager()
{
    std::cout << "Enter the name of the middle manager: " ;
    std::cin >> name ;
}

void MiddleManager::setTask(int id,int numberCommand,int size)
{
    std::srand(id+numberCommand);
    tasksCount = rand() % (size + 1);
    std::cout << "Manager "<< this->name <<" got to work." << std::endl;
}

int MiddleManager::getTaskCount () { return tasksCount ; }

int MiddleManager::getFreeEmployee(){return freeEmployeeNumber ; }

void MiddleManager::setFreeEmployee(int free){ freeEmployeeNumber = free ; }