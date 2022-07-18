#include <iostream>
#define SIZE 15

int main() {

    int numbers[SIZE] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int sum(0) , min(numbers[0]);
    std::cout << "The program determines the repeating numbers in the array." << std::endl;

    for (int i(0); i<15 ; i++ )
    {
        sum+=numbers[i];
        if (min>numbers[i]) min = numbers[i];
    }
    std::cout << "Repeating numbers in sequence: "<<sum-( (2*min+SIZE-2)*(SIZE-1)/2 );
    return 0;
}
