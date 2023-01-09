#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>


int main()
{
    std::ofstream file("Film.json");
    if (!file.is_open()) std::cout << "Error opening." << std::endl;
    else
    {
        nlohmann::json film = { {"Country", "Russia"} ,{"Year of production","2007"} ,{"Studio","STV Film Company"} ,
                                {"Scriptwriter","Alexey Balabanov"} ,{"Film director","Alexey Balabanov"} ,
                                {"Producer","Sergey Selyanov and Maxim Ukhanov"} } ;
        file << film;
        std::cout << film ;
    }
    return 0;
}
