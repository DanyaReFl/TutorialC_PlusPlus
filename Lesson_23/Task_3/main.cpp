#include <iostream>
#include <map>

#define F_1(X) for (int i(1) ; i<=10 ; i++)
#define F_2(X) for (auto it = train.end() ; it!=train.begin() ; --it)

int main() {

    std::map<int,int> train;
    int number,sum(0);

    F_1(train)
    {
            std::cout << "Enter the number of people in the train car "<<i<<" : ";
            std::cin >> number;
            sum+=number;
            train.insert(std::make_pair(number, i));
    }
    F_2(train)
    {
        std::cout << it->first << std::endl ;
    }
    std::cout << "Sum = "<<sum;

    return 0;
}
