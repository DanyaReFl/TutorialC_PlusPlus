#include <iostream>
#include <map>
#include <string>


int main() {

    std::string name,number;
    int command;
    std::map<std::string, std::string> guide;

    std::cout << "The telephone directory program welcomes you!" << std::endl;

    while (true)
    {
        std::cout << "Enter the command (1)add (2)phone search (3)search by last name:" ;
        std::cin >> command;
        if (command==1)
        {
            std::cout <<"Enter phone number: ";
            std::cin >> number;
            std::cout <<"Enter last name: ";
            std::cin >> name;
            guide[number]=name;
        }
        else if (command==2)
        {
            std::cout << "Enter the phone number to search: ";
            std::cin >> number;
            std::cout << guide[number] << std::endl;
        }
        else if (command==3)
        {
            std::cout <<"Enter last name to search: ";
            std::cin >> name;
            for (auto it : guide)
            {
                if (it.second==name)
                {
                    std::cout << it.first << std::endl;
                }
            }
        }
        else  { std::cout << "Error."; break; }
    }
    return 0;
}
