#include <iostream>
#include <fstream>
#include <cassert>


int main() {

    std::ifstream text;
    std::string path;
    const int size=40;
    char buffer[size]{0};

    std::cout << "Enter the path: " ;
    std::cin >> path;
    text.open(path,std::ios::binary);
    assert(text.is_open());
    text.read(buffer,sizeof(buffer)-1);
    std::cout<<buffer;
     while (!text.eof())
    {
        text.read(buffer,text.gcount());
        if (text.gcount()==size-1) std::cout<<buffer ;
        else{
            for (int i(0) ; i<text.gcount() ; i++)
            {
                std::cout<<buffer[i];
            }
        }

    }
    text.close();
    return 0;
}
