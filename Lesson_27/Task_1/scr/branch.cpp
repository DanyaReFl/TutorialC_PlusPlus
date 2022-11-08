#include "header.h"

branch::branch()
{
    std::cout << "Enter the name of the elf: " ;
    std::cin >> name ;
    if ( ( name == "none" ) || ( name == "None" ) ) name = {""} ;
}

branch* branch::findName (std::string findName )
{
    for (int i(0) ; i < this->sizeBranch ; i++ )
    {
        if (this->children->name == findName ) return this->children ;
        else
        {
            for (int j(0) ; j < this->children->children->sizeBranch ; j++ )
            {
                if (this->children->children->name == findName ) return this->children->children ;
                this->children->children++ ;
            }
        }
        this->children++ ;
    }
    return nullptr ;
}

int branch::getCount ()
{
    if ( this->children == nullptr ) return this->parent->sizeBranch ;
    else this->sizeBranch ;
}

void branch::setChildrenAndParent()
{
    this->sizeBranch = ( rand() % 3 ) + 3 ;
    this->children = new branch[ this->sizeBranch ] ;
    for (int i(0); i < this->sizeBranch ; i++)
    {
        this->children->parent = nullptr ;
        this->children->sizeBranch = ( rand() % 2 ) + 2 ;
        this->children->children = new branch [this->children->sizeBranch] ;
        for (int k(0) ; k < this->children->sizeBranch ; k++ )
        {
            this->children->children->parent = this->children->children;
            this->children->children->children = nullptr;
            this->children->children++;
        }
        this->children++;
    }
}