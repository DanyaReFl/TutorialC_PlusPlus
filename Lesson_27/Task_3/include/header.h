#pragma once
#include <iostream>

enum task
{
    none ,
    A ,
    B ,
    C
};

class middleManager;

class HeadCompany
{
private:
    std::string name;
public:

    HeadCompany();

    int getInstructions();

    bool getAllTask(int size , middleManager *man , int people);

};

class middleManager
{
private:
    std::string name ;
    int tasksCount ;
    int freeEmployeeNumber{0};
public:

    middleManager();

    void setTask(int id,int numberCommand,int size);

    int getTaskCount ();

    int getFreeEmployee();

    void setFreeEmployee(int free);

};

class subordinates
{
private:
    std::string name;
    task subTask{none};
public:

    subordinates();

    void setSubTask ();

};