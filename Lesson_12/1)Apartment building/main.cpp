#include <iostream>

int main() {

    std::string nameResidents[10];
    int count;

    std::cout << "The program records all residents in an apartment building." << std::endl;
    std::cout << "Enter the last names of the tenants :" << std::endl;
    for (int i (0) ; i<10 ; i++ )
    {
        std::cin>>nameResidents[i];
    }
    for (int j (0) ; j<3 ; j++)
    {
        std::cout<<"Enter the apartment number: ";
        std::cin>>count;
        if ( (count <= 10) && (count >=1) )
        std::cout<<"Last name of the resident: "<<nameResidents[count-1]<<std::endl;
        else std::cout<<"There is no such apartment number."<<std::endl;
    }
    return 0;
}
