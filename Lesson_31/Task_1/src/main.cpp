#include "shared_ptr_toy.h"
#include "Toy.h"

int main()
{
    Toy *e1 = new Toy ;
    shared_ptr_toy e2 ("Bear");
    Toy e3 = shared_ptr_toy::make_shared_toy(*e1);
    Toy e4 = shared_ptr_toy::make_shared_toy("Bear");
    shared_ptr_toy e5 = e2;
    shared_ptr_toy e6 (e5);
    shared_ptr_toy e7 ("lala");
    e5=e7;
    std::cout << e2->getName() << std::endl;
    std::cout << e5->getName() << std::endl;
    std::cout << e6->getName() << std::endl;
    std::cout << e7->getName() << std::endl;
    return 0;
}
