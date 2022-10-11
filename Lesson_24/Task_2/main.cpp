#include <iostream>
#include <ctime>
#include <vector>

struct person
{
    int year , month , day;
    std::string name ;
};

int main() {

    std::time_t time = std::time(nullptr);
    std::tm *t = std::localtime(&time);
    std::vector<person> characters;
    person birthday;

    std::cout << "The program calculates the nearest birthday!" << std::endl;

    while (true)
    {
        person character;
        std::cout << "Enter a friend's name: ";
        std::cin >> character.name;

        if(character.name=="end") break;

        std::cout << "Enter your date of birth (day/month/year): ";
        std::cin >> character.day >> character.month >> character.year;
        characters.push_back(character);
    }

    for (auto it : characters)
    {
        if ( (it.month < t->tm_mon) ) continue;
        else if ( (it.month >= t->tm_mon) )
        {
            if ( (it.month == t->tm_mon) && (it.day == t->tm_mday) ) std::cout << "Congratulate "<< it.name <<" on his birthday today." << std::endl;
            else if   ( ( (birthday.month == it.month) && (birthday.day >= it.day) ) ||  (birthday.month > it.month))
                birthday=it;
            else continue;
        }
    }

    std::cout <<birthday.name<<" upcoming birthday is "<<birthday.month<<"/"<<birthday.day<< std::endl;
    return 0;
}
