#include <iostream>
template < typename A >
void inputArray(A &array , const size_t SIZE_ARRAY){
    std::cout << "Enter the array elements." << std::endl;
    for (uint8_t i = 0; i < SIZE_ARRAY; ++i){
        std::cout << "Array[" << i+1 << "]:=" ; std::cin >> array[i];
    }
}
template < typename B >
void calculateArray(const B &array , const size_t SIZE_ARRAY){
    double sum{0};
    for (uint8_t i = 0; i < SIZE_ARRAY; ++i) sum += array[i];
    std::cout << "The arithmetic mean of the array: " << static_cast<double>(sum/SIZE_ARRAY)<< std::endl;
}
template < typename C >
void printArray(const C &array , const size_t SIZE_ARRAY){
    std::cout << "Array: ";
    for (uint8_t i = 0; i < SIZE_ARRAY; ++i){
        std::cout << array[i] << "  ";
    }
}
int main() {
    const size_t SIZE_ARRAY = 8;
    double arrayArithmetic[SIZE_ARRAY];
    std::cout << "The arithmetic mean number in the array." << std::endl;
    inputArray(arrayArithmetic,SIZE_ARRAY);
    calculateArray(arrayArithmetic,SIZE_ARRAY);
    printArray(arrayArithmetic,SIZE_ARRAY);
    return 0;
}
