#include "header.h"

int main() {

    std::srand(time(nullptr));
    std::cout << "The program outputs all the abilities of the super dog." << std::endl;
    Dog dogSteve{10,"Steve"};
    dogSteve.run();
    dogSteve.voice();
    dogSteve.show_talents();
    return 0;

}
