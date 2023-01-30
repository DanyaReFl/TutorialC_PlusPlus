#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

auto selectionNumber = [](const auto & list){
    std::unordered_set<int> value(list.begin(), list.end());
    return std::make_unique<std::vector<int>>(value.begin(),value.end());
};

int main() {
    const std::vector<int> listOfNumber {1,2,2,3,5,6,3,2,5,6,8,9,9};
    auto ptr_number_special = selectionNumber(listOfNumber);
    for (const auto it : *ptr_number_special) std::cout << it ;
    return 0;
}
