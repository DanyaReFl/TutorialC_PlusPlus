#include <iostream>

void foo(int *ptr)
{
    for (int i(0) ; i<5 ; i++)
    {

        std::swap(ptr[i],ptr[9-i]);
    }
}

int main() {

    int mass[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptrI=mass;
    foo(ptrI);
    for (int i (0) ; i<10 ; i++ )
    {
        std::cout << mass[i];
    }
    return 0;
}
