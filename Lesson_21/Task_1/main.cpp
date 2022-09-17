#include <iostream>
#include <fstream>
#include <cassert>

struct list
{
    std::string name;
    std::string last_name;
    std::string date;
    std::string money;
};

int main() {

    std::string command ;
    list fields;

    std::cout << "Accounting statement program." << std::endl;
    std::cout << "Enter the command(add/list): " ;
    std::cin >> command;

    if (command=="add")
    {
        list field{};

        std::ofstream text("record.txt",std::ios::app);
        if (!text.is_open()) std::cout<<"error opening.";

        std::cout << "Enter your first and last name:";
        std::cin >> field.name >> field.last_name;
        for(int i=0; i< field.name.length(); i++) assert(field.name[i] >= (char)'a' && field.name[i] <= (char)'z'
        || field.name[i] >= (char)'A' && field.name[i] <= (char)'Z' || field.name[i]==' ');

        std::cout << "Enter the date:";
        std::cin >> field.date;
        for(int i=0; i< field.date.length(); i++) assert( std::stoi(field.date.substr(0, 2))<32
        && std::stoi(field.date.substr(0, 2))>0 && std::stoi(field.date.substr(3, 2))<13
        && std::stoi(field.date.substr(3, 2))>0) ;

        std::cout << "Enter the amount:";
        for(int i=0; i< field.money.length(); i++) assert(int(field.money[i]) > 47 && int(field.money[i]) < 59);
        std::cin >> field.money;
        text<<field.name<<" "<<field.last_name<<" "<<field.date<<" "<<field.money<<std::endl;

    }
    else if (command=="list")
    {
        std::ifstream text("record.txt");
        if (!text.is_open()) std::cout<<"error opening.";

        while(!text.eof())
        {
            text >> fields.name >> fields.last_name >> fields.date >> fields.money;
            std::cout << fields.name <<" "<< fields.last_name <<" "<< fields.date <<" "<< fields.money<<std::endl;
        }
    }
    else std::cout << "Input error.";

    return 0;
}
