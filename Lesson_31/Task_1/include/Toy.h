#pragma once
#include <iostream>
#include <utility>

class Toy
{
private:
    std::string name;
public:
    explicit Toy (std::string outName): name(std::move(outName)) { std::cout << "Constructor Toy" << std::endl; };
    explicit Toy() : name("SomeToyName") {  std::cout << "Constructor Toy" << std::endl; };
    std::string getName () const {return name;}
};