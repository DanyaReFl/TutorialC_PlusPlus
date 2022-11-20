#include <iostream>
#include <ctime>
#include <mutex>
#include <thread>

std::mutex order;
std::mutex delivery;
static int countDelivery(0);

void kitcheAndDelivery( const std::string dish )
{
    order.lock();
    std::cout << "Order " << dish << " is being prepared." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds( ( ( rand() % 11) + 5 ) ));
    std::cout << "dish " << dish << " is cooked" << std::endl;
    order.unlock();
    delivery.lock();
    std::cout << "Order on the way." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(30));
    countDelivery++;
    std::cout << "Order delivered." << std::endl;
    delivery.unlock();
}

int main() {
    std::srand(time(nullptr));
    const std::string dish[5] = {"pizza","soup","steak","salad","sushi"} ;
    std::cout << "Simulation of the operation of an online restaurant kitchen!" << std::endl;

    while (true)
    {
    int i = ( rand() % 5 ) ;
    std::this_thread::sleep_for(std::chrono::seconds( ( ( rand() % 6 ) + 5 )));
    std::cout << "The order for the dish " << dish[i] << " is accepted." << std::endl;
    std::thread food(kitcheAndDelivery,dish[i]);
    food.detach();
    if ( food.joinable() ) food.join();
    if (countDelivery>=10) break;
    }

    return 0;
}
