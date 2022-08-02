#include <iostream>
#include <iterator>
#include <vector>

int main() {

    int number;
    std::vector<int> mass;
    mass.reserve(10);
    std::cout << "The program outputs the fifth ascending number among the entered ones." << std::endl;

    do
    {
    std::cout << "Enter a number: " ;
    std::cin >> number;
    if (number==-2) break;
    else if (number==-1)
    {
        if (mass.size()<5)
        {
            std::cout << "The array does not have five elements, fill in more."<<std::endl;
            continue;
        }
        else
        {
            std::cout << "Array element: " << mass[4] << std::endl;
            continue;
        }

    }
    else {
        {
            if (mass.size() == 0 )
            {
                mass.push_back(number);
                continue;
            }
            for (int i(0); i < mass.size(); i++)
            {
                if (number < mass[i])
                {
                    mass.insert(mass.begin() + i, number);
                    break;
                }
                else if ((i+1)==mass.size())
                {
                    mass.push_back(number);
                    break;
                }
            }

            }
        }
    } while (true);


    return 0;
}
