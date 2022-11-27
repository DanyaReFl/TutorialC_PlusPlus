#include <iostream>
#include <map>
#include <thread>
#include <vector>
#include <algorithm>

void Swimming_1(int speed , std::string name , int *time )
{
    for ( ; ((*time)*speed) <= 100 ; (*time) ++ )
    {
        std::cout << "Swimmer " << name << " swam: " << (speed * (*time)) << " m." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{

    const short SIZE = 6 ;

    std::map < std::string , double > namesSpeed ;

    for (int i (1) ; i <= 6 ; i ++ )
    {
        std::string name;
        double speed;
        std::cout << "Enter the name of " << i << " swimmer" << std::endl;
        std::cin >> name ;
        do{
        std::cout << "Enter the speed of " << i << " swimmer" << std::endl;
        std::cin >> speed ;
        }while( speed <= 0 );
        namesSpeed.insert(std::make_pair(name,speed));
    }
    std::map<std::string, double>::iterator it = namesSpeed.begin();
    std::vector<int> time{1,1,1,1,1,1};

    std::vector<std::thread> swims;
    for (uint8_t i = 0; i < SIZE; i++)
    {
        swims.emplace_back(Swimming_1 , it->second , it->first , &time[0]);
        it++;
    }

    for (uint8_t i = 0; i < SIZE; i++)
        swims.at(i).join();

    std::sort(time.begin(),time.end());
    std::cout << std::endl;
    for (auto it : time)
    {
        std::cout << it << " sec " << std::endl;
    }
    return 0;
}
