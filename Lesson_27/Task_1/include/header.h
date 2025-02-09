#pragma once
#include <iostream>
#include <ctime>
#include <vector>


class Branch
{

private:
    Branch* parent = nullptr;
    std::vector<Branch*> children;
    std::string elfName = "None";

public:

    Branch();
    Branch(Branch* inParent);
    Branch* addChild();
    bool canBeOccupied();
    void occupy(std::string inElfName);
    Branch* getTopBranch();
    int countElves();
    int countNeighbors();
    void occupyChildren();
    Branch* findElfBranch(std::string inElfName);


};