#include <iostream>
#include <thread>
#include <mutex>

std::mutex train_stop;

void function( int time , const char trainName)
{
    std::cout << "Train " << trainName << " left the station." << std::endl ;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::string command;
    std::cout << "The train " << trainName << " is waiting for an empty seat." << std::endl;
    train_stop.lock();
    std::cout << "The train " << trainName << " is at the station ." << std::endl ;
    do
    {
        std::cout << "Waiting for the \"depart\" command: " << std::endl;
        std::cin >> command;
    }while ( command != "depart" );
    std::cout << "Train " << trainName << " left the station." << std::endl ;
    train_stop.unlock();
}


int main()
{

    int timeA , timeB , timeC ;
    const char A('A') , B('B') , C('C');

    std::cout << "Simulation of the station operation." << std::endl;
    std::cout << "Enter the travel time for A train: " ;
    std::cin >> timeA;
    std::cout << "Enter the travel time for B train: " ;
    std::cin >> timeB;
    std::cout << "Enter the travel time for C train: " ;
    std::cin >> timeC;

    std::thread trainA (function , timeA , A ) ;
    std::thread trainB (function , timeB , B ) ;
    std::thread trainC (function , timeC , C ) ;
    trainA.join(); trainB.join(); trainC.join();
    return 0;
}
