#include <iostream>
#include <cpr/cpr.h>

int main()
{
    std::string command;

    while (true)
    {
        std::cout << "Enter the command: " << std::endl;
        std::cin >> command;
        if ( ( command == "Post" ) || ( command == "post" ) )
        {
            cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout << r.text << std::endl;
        }
        else if ( ( command == "Get" ) || ( command == "get" ) )
        {
            cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << r.text << std::endl;
        }
        else if ( ( command == "Put" ) || ( command == "put" ) )
        {
            cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout << r.text << std::endl;
        }
        else if ( ( command == "Delete" ) || ( command == "delete" ) )
        {
            cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout << r.text << std::endl;
        }
        else if ( ( command == "Exit" ) || ( command == "exit" ) ) break;
        else
        {
            std::cout << "No command found." << std::endl;
        }
    }
}
