#include <iostream>
#include <vector>

int main() {

    float sum(0);
    std::vector<float> prices {4.5, 6.5, 3.5, 8.0};
    std::vector<int> items {1, 2, 0, 3};

    std::cout << "The program outputs the total cost." << std::endl;


    for (int i(0) ; i<items.size() ; i++ )
    {
        sum+=prices[items[i]];
    }
    std:: cout << "Total cost: "<< sum;
    return 0;
}
