#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
   assert( (speed>0) && (distance>0) );
   std::cout << "Time: "<< (distance/speed) << std::endl;
}

int main() {

    float distance, speed;

    std::cout << "The program determines the travel time." << std::endl;
    std::cout << "Enter the speed: ";
    std::cin >> speed;
    std::cout << "Enter the distance: ";
    std::cin >> distance;

    travelTime(distance,speed);
    return 0;
}
