#include "TalentAndDog_Class.h"

int main() {

    std::cout << "The program outputs all the abilities of the super dog." << std::endl;
    Dog dogSteve{"Steve"};
    dogSteve.addTalent(new Counting);
    dogSteve.addTalent(new Dancing);
    dogSteve.show_talents();
    return 0;

}
