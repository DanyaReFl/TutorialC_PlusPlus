#include <iostream>
#include <vector>


int main() {

    std::vector<int> mass ={-100,-50, -10, -5, 1, 3, 10, 15 , 80};
    std::vector<int> massAbs;
    massAbs.reserve(10);
    int count(mass.size()-1);

    std::cout << "The program sorts the array modulo a number ." << std::endl;


    for (; mass[count]>=0 ; count--)
    {
        massAbs.insert(massAbs.begin(),mass[count]);
    }
    for (; count>=0 ; count-- )
    {
        for (int i(0) ; i<massAbs.size() ; i++)
        {
            if (abs(mass[count])<massAbs[i] )
            {
                massAbs.insert(massAbs.begin()+i,mass[count]);
                break;
            }
            else if(i+1==massAbs.size())
            {
                massAbs.push_back(mass[count]);
                break;
            }
        }
    }
    for (int i(0) ; i<massAbs.size() ; i++)
    {
        std::cout << massAbs[i] << "  ";
    }
    return 0;
}
