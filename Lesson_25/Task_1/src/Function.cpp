#ifndef TASK_1_FUNCTION_H
#define TASK_1_FUNCTION_H

#include "header.h"
#include <iostream>


struct coordinates;


void scalpel (coordinates XY)
{
    std::cout << "A cut was made between the points : A(" << XY.X << "," << XY.Y <<
              ") and O(" << XY.X_0 << "," << XY.Y_0 << ")" << std::endl;
}

void hemostat ()
{
    coordinates XY;
    std::cout << "A(X,Y):= ";
    std::cin >> XY.X >> XY.Y;
    std::cout << "A hemostat was made : A(" << XY.X << "," << XY.Y << ")" << std::endl;
}

void tweezers ()
{
    coordinates XY;
    std::cout << "A(X,Y):= ";
    std::cin >> XY.X >> XY.Y;
    std::cout << "Tweezers were made : A(" << XY.X << "," << XY.Y << ")" << std::endl;
}

void suture (coordinates XY)
{
    std::cout << "The suture was made between the points : A(" << XY.X << "," << XY.Y << ")" <<
              ") and O(" << "(" << XY.X_0 << "," << XY.Y_0 << ")" << std::endl;
}


#endif
