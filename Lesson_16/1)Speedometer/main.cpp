#include <iostream>
#include <sstream>

int main() {

    const short MAX_SPEED(150);
    char text[50];

    float speed(0.f);
    float diffSpeed;

    std::cout << "The car's digital speedometer , welcomes you." << std::endl;

    do
    {
        std::cout << "Enter the speed difference: ";
        std::cin >> diffSpeed;
        speed+=diffSpeed;
        if (speed<=0) break;
        else if (speed > MAX_SPEED) speed = MAX_SPEED;
        std::sprintf(text, "The speedometer shows %.1f", speed);
        std::cout << text << std::endl;

    }while (speed>0);

    return 0;
}
