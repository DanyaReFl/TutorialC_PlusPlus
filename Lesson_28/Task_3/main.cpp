#include <iostream>
#include <ctime>
#include <mutex>
#include <vector>
#include <thread>

std::mutex mtx_waiter ;
std::mutex mtx_kitche ;
std::mutex mtx_delivery ;
int countDelivery(0);

void waiter( const std::string dish , std::vector<bool> *isOrder)
{
    mtx_waiter.lock();
    std::this_thread::sleep_for(std::chrono::seconds( ( ( rand() % 6 ) + 5 )));
    std::cout << "The order for the dish " << dish << " is accepted." << std::endl;
    isOrder->push_back(false);
    mtx_waiter.unlock();
}

void kitche( const std::string dish , std::vector<bool> *isOrder )
{
    mtx_kitche.lock();
    if (!isOrder->empty())
    {
        for(auto it : *isOrder) {
            if (!it)
            {
                std::cout << "Order " << dish << " is being prepared." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(((rand() % 11) + 5)));
                std::cout << "dish " << dish << " is cooked." << std::endl;
                it=true;
            }
        }

    }
    mtx_kitche.unlock();
}

void delivery(std::vector<bool> *isOrder)
{
    mtx_delivery.lock();
    if ( !isOrder->empty() )
    {
        int count(0);
        for (auto it: *isOrder)
        {
            if (it) count++;
        }
        if (count!=0)
        {
            std::cout << "Order on the way." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(30));
            std::cout << "Order delivered." << std::endl;
            countDelivery=count;
        }
    }
    mtx_delivery.unlock();
}

int main() {

    std::srand(time(nullptr));
    const std::string dish[5] = {"pizza", "soup", "steak", "salad", "sushi"};
    std::cout << "Simulation of the operation of an online restaurant kitchen!" << std::endl;
    std::vector<bool> isOrder;
    std::vector<std::thread> foodWaiter;
    while (true)
    {

        int j = rand() % 5;
        foodWaiter.emplace_back(waiter, dish[j] , &isOrder);
        foodWaiter.back().detach();

        std::vector<std::thread> foodKitche;
        foodKitche.emplace_back(kitche, dish[j] , &isOrder);
        foodKitche.back().join();

        std::vector<std::thread> foodDelivery;
        foodDelivery.emplace_back(delivery , &isOrder);
        foodDelivery.back().detach();
        if (countDelivery >= 10) break;

    }

    std::cout << "The restaurant has completed its work." ;


    return 0;
}
