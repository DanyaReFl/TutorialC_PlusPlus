#include <iostream>


int main() {

    float mas[15];


    std::cout << "The program sorts an array of 15 elements." << std::endl;
    for (int i (0) ; i<15 ; i++ ) {

        std::cout << "Enter "<< i+1 <<" element:" ;
        std::cin>>mas[i];
        int r=i;
        for ( int j = i-1  ; (j>=0)  ; j--)
        {

            if  (mas[r]>mas[j]) {
                std::swap(mas[j], mas[r]);
                r=j;

            }
        }

    }
    std::cout << "Sorted array: " ;
    for (int count (0) ; count <15 ; count ++ )
    {
        std::cout << mas[count] << "  ";
    }
    return 0;
}
