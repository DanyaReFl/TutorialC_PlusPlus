#include <iostream>
#include <vector>

class Number{
private:
    std::vector<size_t> integers_;
public:
    Number() = default;
    Number(std::initializer_list<size_t> integers):integers_(integers){}
    void getNumbersInteger(){
        std::cout << "Integer: ";
        for (const auto &it : integers_){
            std::cout << it << " ";
        }
    }
};
int main() {

    Number count { 1 , 2 , 3 , 4 , 5 };
    count.getNumbersInteger();
    return 0;

}
