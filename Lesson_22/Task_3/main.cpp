#include <iostream>
#include <map>
#include <string>


int main() {

    std::string first,second;
    std::map<char,int> s1, s2;

    std::cout << "The program determines whether the first line is an anagram of the second." << std::endl;
    std::cout << "Enter two lines: ";
    std::cin >> first >> second;

    for (int i(0) ; i < first.size() ; i++)
    {
        ++s1[first[i]];
    }
    for (int j(0) ; j < second.size() ; j++)
    {
        ++s2[second[j]];
    }
    if ( s1 == s2 ) std::cout << "The first line is an anagram of the second.";
    else std::cout << "The first line is NOT an anagram of the second.";


    return 0;
}
