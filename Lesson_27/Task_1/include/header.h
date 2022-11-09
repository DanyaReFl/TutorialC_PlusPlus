#pragma once
#include <iostream>
#include <ctime>


class branch
{
private:
    branch * parent ;
    branch * children ;
    std::string name{""};
    int sizeBranch {0};
public:

    branch();

    branch * findName (std::string findName );

    int getCount ();

    void setChildrenAndParent();

};