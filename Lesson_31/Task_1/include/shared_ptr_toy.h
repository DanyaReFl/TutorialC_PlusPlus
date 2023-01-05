#pragma once
#include "Toy.h"

class shared_ptr_toy
{
private:
    Toy *object;
    static uint8_t count ;
public:
    explicit shared_ptr_toy();
    explicit shared_ptr_toy(std::string name);
    shared_ptr_toy& operator=(const shared_ptr_toy& other);
    shared_ptr_toy(const shared_ptr_toy& other);
    ~shared_ptr_toy();
    static Toy& make_shared_toy(std::string nameToy);
    static Toy& make_shared_toy(Toy& OtherToy);
    Toy* operator->();
};

