#pragma once
#include <iostream>
#include <vector>

class Swimming;
class Dancing;
class Counting;

class Talent
{
public:
    virtual void talent()=0;
};

class Swimming : public Talent
{
public:
    virtual void talent() override
    {
        std::cout << "It can Swim!" << std::endl;
    }
};

class Dancing : public Talent
{
public:
    virtual void talent() override
    {
        std::cout << "It can Dance!" << std::endl;
    }
};

class Counting : public Talent
{
public:
    virtual void talent() override
    {
        std::cout << "It can Count!" << std::endl;
    }
};

class Dog
{
private :
    const std::string name;
    std::vector<Talent*> AllDogTalent;
public:
    Dog (std::string str);
    void show_talents() const ;
    void addTalent(Talent *talent);
};
