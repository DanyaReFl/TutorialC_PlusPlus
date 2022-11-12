#include "Header.h"



int main()
{
    std::string command;

    std::cout << "The program calculates the area of the shape and finds a rectangle that describes it." << std::endl;
    while(true)
    {
        std::cout << "Enter the shape(rectangle,square,triangle,circle): ";
        std::cin >> command;
        if (command=="rectangle")
        {
            Rectangle figure ;
            figure.Square();
            figure.desShape();
            break;
        }
        else if (command=="square")
        {
            Square figure;
            figure.SquareS();
            figure.desShape();
            break;
        }
        else if (command=="triangle")
        {
            Triangle figure;
            figure.Square();
            figure.desShape();
            break;
        }
        else if (command=="circle")
        {
            Circle figure;
            figure.Square();
            figure.desShape();
            break;
        }
        else
        {
            std::cout << "Mistake. There is no such figure in the list ." << std::endl;
        }
    }
    return 0;
}
