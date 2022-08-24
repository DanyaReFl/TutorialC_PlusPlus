#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream file_reading("river.txt");
    std::vector <std::string> fish;
    std::string nameFish;
    std::string fish_river;
    int i(0);
    if (!file_reading.is_open()) std::cout << "Opening error." << std::endl;

    std::cout << "The program simulates fishing." << std::endl;
    std::cout << "Enter \"ex\" to exit." << std::endl;

    while(true)
    {
        file_reading.seekg(std::ios::beg);
        std::cout << "Enter the name of the fish: ";
        std::cin >> nameFish;
        if (nameFish=="ex") break;
        while(!file_reading.eof())
        {
            file_reading>>fish_river;
            if(fish_river==nameFish) { fish.push_back(nameFish); break;}
        }
        i++;
    }
    file_reading.close();
    std::ofstream file_record("basket.txt",std::ios::app);
    if (!file_record.is_open()) std::cout << "Opening error." << std::endl;
    for (std::vector<std::string>::iterator it = fish.begin() ; it!=fish.end() ; ++it)
    {
        file_record << *it << std::endl;
    }
    file_record.close();
    return 0;
}
