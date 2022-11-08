#include "header.h"

middleManager::middleManager()
{
    std::cout << "Enter the name of the middle manager: " ;
    std::cin >> name ;
}

void middleManager::setTask(int id,int numberCommand,int size)
{
    std::srand(id+numberCommand);
    tasksCount = rand() % (size + 1);
    std::cout << "Manager "<< this->name <<" got to work." << std::endl;
}

int middleManager::getTaskCount () { return tasksCount ; }

int middleManager::getFreeEmployee(){return freeEmployeeNumber ; }

void middleManager::setFreeEmployee(int free){ freeEmployeeNumber = free ; }