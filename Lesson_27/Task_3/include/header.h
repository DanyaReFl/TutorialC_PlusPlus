#pragma once
#include <iostream>

enum Task
{
    none ,
    A ,
    B ,
    C
};

class MiddleManager;

class HeadCompany
{
private:
    std::string name;
public:

    HeadCompany();

    int getInstructions();

    bool getAllTask(int size , MiddleManager *man , int people);

};

class MiddleManager
{
private:
    std::string name ;
    int tasksCount ;
    int freeEmployeeNumber{0};
public:

    MiddleManager();

    void setTask(int id,int numberCommand,int size);

    int getTaskCount ();

    int getFreeEmployee();

    void setFreeEmployee(int free);

};

class Subordinates
{
private:
    std::string name;
    Task subTask{none};
public:

    Subordinates();

    void setSubTask ();

};