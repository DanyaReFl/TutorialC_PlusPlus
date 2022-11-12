#include "header.h"

    Branch::Branch()
    {
        parent = nullptr;
    }

    Branch::Branch(Branch* inParent)
    {
        parent = inParent;
    }


    bool Branch::canBeOccupied()
    {
        return parent != nullptr;
    }


    void Branch::occupy(std::string inElfName)
    {
        if (elfName == inElfName) return;
        if (inElfName != "None")
        {
            if (elfName != "None")
            {
                std::cerr << "House already occupied!" << std::endl;
                return;
            }
            if (!canBeOccupied())
            {
                std::cerr << "This branch can't be occupied!" << std::endl;
                return;
            }
            elfName = inElfName;
        }
    }

    Branch* Branch::getTopBranch()
    {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }

    int Branch::countElves()
    {
        int count = elfName != "None" ? 1 : 0;
        for (int i = 0; i < children.size(); ++i)
        {
            count += children[i]->countElves();
        }
        return count;
    }

    int Branch::countNeighbors()
    {
        Branch* top = getTopBranch();
        if (top == nullptr) return 0;
        return top->countElves();
    }

    Branch* Branch::addChild()
    {
        Branch* child = new Branch(this);
        children.push_back(child);
        return child;
    }

    void Branch::occupyChildren()
    {
        if (canBeOccupied())
        {
            std::string inElfName;
            std::cout << "Elf name:";
            std::cin >> inElfName;
            occupy(inElfName);
        }
        for (int i = 0; i < children.size(); ++i)
        {
            Branch* child = children[i];
            child->occupyChildren();
        }
    }

    Branch* Branch::findElfBranch(std::string inElfName)
    {
        if (this->elfName == inElfName)
        {
            return this;
        }
        for (int i = 0; i < children.size(); ++i)
        {
            Branch *child = children[i]->findElfBranch(inElfName);
            if (child != nullptr)
            {
                return child;
            }
        }
        return nullptr;
    }
