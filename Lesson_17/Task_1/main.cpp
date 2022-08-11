#include <iostream>


void swap(int *a , int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}


int main() {

    int a = 10;
    int b = 20;
    std::cout << "program swaps the contents of these pointers." << std::endl;
    std::cout << a << " " << b << std::endl;
    swap(&a, &b);
    std::cout << a << " " << b;
    return 0;
}
