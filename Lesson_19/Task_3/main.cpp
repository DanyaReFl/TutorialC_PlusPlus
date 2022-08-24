#include <iostream>
#include <fstream>

int main() {

    std::ifstream text;
    double number,sum(0),max;
    std::string name,str,findName;

    std::cout << "The program counts the total amount of funds paid and the maximum amount ." << std::endl;
    text.open("D:\\DDA\\TutorialC\\Lesson_19\\Task_3\\text.txt");
    system("cd");
    if (!text.is_open()) std::cout << "Opening error.";
    while (!text.eof())
    {
        text >> name >> str;
        text >> number;
        sum += number;
        if (number>max)
        {
            max=number;
            findName= name + " " + str;
        }
        text>>str;
    }
    std::cout<<sum<<std::endl;
    std::cout<<findName;
    text.close();
    return 0;
}
