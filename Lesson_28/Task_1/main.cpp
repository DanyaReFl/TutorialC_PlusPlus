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
    std::vector<int> time{1,1,1,1,1,1};
    std::map<std::string, double>::iterator it = namesSpeed.begin();
    std::thread Swimmer_1( Swimming_1 , it->second , it->first , &time[0] ) ; it++;
    std::thread Swimmer_2( Swimming_1 , it->second , it->first , &time[1] ) ; it++;
    std::thread Swimmer_3( Swimming_1 , it->second , it->first , &time[2] ) ; it++;
    std::thread Swimmer_4( Swimming_1 , it->second , it->first , &time[3] ) ; it++;
    std::thread Swimmer_5( Swimming_1 , it->second , it->first , &time[4] ) ; it++;
    std::thread Swimmer_6( Swimming_1 , it->second , it->first , &time[5] ) ; it++;
    Swimmer_1.join(); Swimmer_2.join(); Swimmer_3.join(); Swimmer_4.join(); Swimmer_5.join(); Swimmer_6.join();
    std::sort(time.begin(),time.end());
    std::cout << std::endl;
    for (auto it : time)
    {
        std::cout << it << " sec " << std::endl;
    }
    return 0;
}
