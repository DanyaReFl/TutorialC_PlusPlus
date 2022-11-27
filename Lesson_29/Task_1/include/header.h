#pragma once
#include <iostream>
#include <vector>
#include <ctime>

class Talent
{
public:
    virtual void getTalent() = 0;
};

class Swimming : public Talent
{
public:
    void getTalent() override
    {
        std::cout << "It can Swim!" << std::endl;
    }
};

class Dancing : public Talent
{
public:

    void getTalent() override
    {
        std::cout << "It can Dance!" << std::endl;
    }
};

class Counting : public Talent
{
public:

    void getTalent() override
    {
        std::cout << "It can Count!" << std::endl;
    }
};

class Dog
{
private :
    const int age;
    const std::string name;
    std::vector<Talent*> dogTalent;
public:
    Dog (int number , std::string str);
    void voice();
    void run();
    void show_talents();
};
