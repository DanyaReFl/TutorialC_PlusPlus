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
                                {"Producer","Sergey Selyanov and Maxim Ukhanov"} ,
                                {"Alexey Poluyan","Zhurov is the main role . Maniac policeman, captain"},
                                {"Agnia Kuznetsova","Angelica is the main role . Dubbing - Oksana Surnina"},
                                {"Leonid Gromov","Artem Nikolaevich Kazakov"}} ;
        file << film;
        std::cout << film << std::endl; ;
    }
    return 0;
}
