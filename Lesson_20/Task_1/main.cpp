#include <iostream>
#include <fstream>
#include <cassert>

int main() {

    std::ofstream text("Statement.txt",std::ios::app);
    if (!text.is_open()) std::cout<< "Opening error."<<std::endl;
    std::string name;
    std::string date;
    std::string salary;

    std::cout << "Enter your first and last name: " << std::endl;
    std::getline(std::cin , name);
    for(int i=0; i< name.length(); i++) assert(name[i] >= (char)'a' && name[i] <= (char)'z' || name[i] >= (char)'A' && name[i] <= (char)'Z' || name[i]==' ');
    text<<name<<"  ";

    std::cout << "Enter the date of issue: "<< std::endl;
    std::getline(std::cin , date);
    for(int i=0; i< date.length(); i++) assert( std::stoi(date.substr(0, 2))<32 && std::stoi(date.substr(0, 2))>0 &&
    std::stoi(date.substr(3, 2))<13 && std::stoi(date.substr(3, 2))>0) ;
    text<<date<<"  ";

    std::cout << "Enter the payout amount: "<< std::endl;
    std::getline(std::cin , salary);
    for(int i=0; i< salary.length(); i++) assert(int(salary[i]) > 47 && int(salary[i]) < 59);
    text<<salary<<std::endl;
    text.close();
    return 0;
}
