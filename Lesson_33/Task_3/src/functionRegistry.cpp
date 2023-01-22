#include "functionHeader.h"

template <typename A1 , typename A2>
void addRegistry(std::vector<Registry<A1,A2>> &array){
    A1 key ; A2 value;
    std::cout << "Enter the key: ";
    std::cin >> key;
    std::cout << "Enter a value: ";
    std::cin >> value;
    array.push_back(Registry<A1,A2>(key,value));
}

template <typename B1 , typename B2>
void removeRegistry(std::vector<Registry<B1,B2>> &array){
    B1 key;
    std::cout << "Enter the key: ";
    std::cin >> key;
    for (auto it = array.begin() ; it != array.end() ; it ++) if (it->key_ == key) { array.erase(it); it --; }
}

template <typename C1 , typename C2>
void printRegistry(std::vector<Registry<C1,C2>> &array){
    for (auto it = array.begin() ; it != array.end() ; it ++)
        std::cout << "Key: " << it->key_ << "\t" << "Value: " << it->value_ << std::endl;
}

template <typename D1 , typename D2>
void findRegistry(std::vector<Registry<D1,D2>> &array){
    D1 key;
    std::cout << "Enter the key: ";
    std::cin >> key;
    for (auto it = array.begin() ; it != array.end() ; it ++) if (it->key_== key) std::cout << it->value_ << "-";
    std::cout << std::endl;
}