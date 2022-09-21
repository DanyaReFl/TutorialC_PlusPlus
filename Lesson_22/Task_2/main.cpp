#include <iostream>
#include <map>
#include <string>


int main() {

    int number(0);
    std::multimap<std::string,int> pair;
    std::string name;

    std::cout << "Registration program." << std::endl;

    while (true)
    {
        std::cout << "Enter your last name or \"next\": " ;
        std::cin >> name;
        if (name == "next")
        {
            auto it = pair.begin();
            std::cout << it->first << std::endl;
            pair.erase(it);
        }
        else
        {
            pair.emplace(std::make_pair(name,number));
            number++;
        }
    }

    return 0;
}
