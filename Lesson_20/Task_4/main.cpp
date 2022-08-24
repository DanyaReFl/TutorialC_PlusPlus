#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>


int main()
{
    std::srand(std::time(nullptr));
    std::vector<int> money(1000);
    int number(0);
    char ch;

    std::ifstream bank("ATM_machine.txt",std::ios::binary);
    if (!bank.is_open()) std::cout << "Opening error." << std::endl;
    if (!bank.eof())
    {
        for (std::vector<int>::iterator it = money.begin(); it != money.end(); ++it)
        bank>>*it;
    }
    bank.close();

    std::cout << "The program simulates an ATM. \n+ to deposit cash. \n- for cash withdrawal." << std::endl;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    if (ch=='+')
    {
        std::ofstream bank("ATM_machine.txt");

            for (std::vector<int>::iterator it = money.begin(); it != money.end(); ++it)
            {
                *it=rand()%4;
                switch (*it)
                {
                    case 0: *it=100;    break;
                    case 1: *it=500;    break;
                    case 2: *it=1000;   break;
                    case 3: *it=5000;   break;
                }
                bank<<*it<<std::endl;
            }
        bank.close();
    }
    else if (ch=='-')
    {
        std::cout << "Enter the withdrawal amount:" ;
        std::cin >> number;
        for (std::vector<int>::iterator it = money.end()-1; ; --it)
        {
            if (it==money.begin())
            {
                std::cout << "The operation is impossible";
                break;
            }
            else if (number!=0)
            {
                if (number<*it) continue;
                number-=*it;
                money.erase(it);
            }
            else
            {
                std::ofstream bank("ATM_machine.txt",std::ios::trunc);
                for (std::vector<int>::iterator it = money.begin(); it != money.end(); ++it)
                    bank<<*it<<std::endl;
                bank.close();
                break;
            }

        }
    }
    else std::cout << "Error.";

    return 0;
}
