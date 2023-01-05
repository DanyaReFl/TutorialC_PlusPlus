#include "shared_ptr_toy.h"


shared_ptr_toy::shared_ptr_toy()
{
    object = new Toy;
    count=0;
    std::cout << "Constructor shared_ptr_toy" << std::endl;
}

shared_ptr_toy::shared_ptr_toy(std::string name)
{
    object = new Toy(std::move(name));
    count=0;
    std::cout << "Constructor shared_ptr_toy" << std::endl;
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    std::cout << "operator =  shared_ptr_toy" << std::endl;
    if (this==&other) return *this;
    if (object!= nullptr) delete object;
    object = new Toy (*other.object);
    count++;
    std::cout << "Count: " << count << std::endl;
    return *this;
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other):object(other.object)
{
    std::cout << "Copy constructor shared_ptr_toy" << std::endl;
    count++;
    std::cout << "Count: " << count << std::endl;
}

shared_ptr_toy::~shared_ptr_toy()
{
    std::cout << "Destructor shared_ptr_toy" << std::endl;
    if ((object != nullptr) && (count == 0))
    {
        delete[] object;
    }
    else count--;
    std::cout << "Count: " << count << std::endl;
}

Toy& shared_ptr_toy::make_shared_toy(std::string nameToy)
{
    std::cout << "make_shared_toy(name) shared_ptr_toy" << std::endl;
    Toy* Toys = new Toy(std::move(nameToy));
    return  *Toys;
}

Toy& shared_ptr_toy::make_shared_toy(Toy& OtherToy)
{
    std::cout << "make_shared_toy(Toy) shared_ptr_toy" << std::endl;
    Toy* Toys = new Toy(OtherToy.getName());
    return *Toys;
}

Toy* shared_ptr_toy::operator->()
{
    return object;
}