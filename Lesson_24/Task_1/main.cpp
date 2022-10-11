#include <iostream>
#include <ctime>
#include <map>


int main() {

    std::time_t t ;
    std::string command;
    std::string nameTask;
    std::map<double,std::string> myMap;
    bool work(false);
    double diff;

    std::cout << "Time tracking program." << std::endl;

    while (true)
    {
        std::cout << "Enter the command(begin/end/status/exit): ";
        std::cin >> command;
        if (command=="exit") break;
        else if (command=="begin")
        {
            if (work)
            {
                work=false;
                diff=((std::clock()-t)/(double)CLOCKS_PER_SEC)/360;
                myMap.insert(std::make_pair(diff,nameTask));
            }
            std::cout << "Enter the name of the task: ";
            std::cin >> nameTask;
            t=std::clock();
            work=true;
        }
        else if (command=="end")
        {
            if (work)
            {
                work=false;
                diff=((std::clock()-t)/(double)CLOCKS_PER_SEC)/360;
                myMap.insert(std::make_pair(diff,nameTask));
            }
        }
        else if (command=="status")
        {
            for(auto it :myMap)
            {
                std::cout<< "Task: "<< it.second << " Time spend: "<< it.first << std::endl;
            }
            if (work)
                std::cout << "Now the task is being performed: " << nameTask << std::endl;
        }
        else std::cout << "Error." << std::endl;
    }

    return 0;
}
