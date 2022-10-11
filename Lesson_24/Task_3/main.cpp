#include <iostream>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

int main() {

    std::time_t time = std::time(nullptr);
    std::tm *time_tm = std::localtime(&time);
    std::tm timer ;

    std::cout << "Timer program!" << std::endl;
    std::cout << "Enter the time(M:S)(**:**): ";
    std::cin >> std::get_time(&timer,"%M:%S");
    while(true)
    {
        std::cout << timer.tm_min << ":" << timer.tm_sec<< std::endl;
        if ( ( timer.tm_min==0 ) && ( timer.tm_sec ==0) ) break;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (timer.tm_sec!=0) timer.tm_sec--;
        else { timer.tm_min-- ; timer.tm_sec=59 ;}
    }
    std::cout << "DING! DING! DING!" ;
    return 0;
}
