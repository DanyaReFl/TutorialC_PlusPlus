#include <iostream>
#include <fstream>
#include <cassert>

int main() {

    std::ifstream filePng;
    std::string fileName;
    char isPng[4];

    std::cout << "The program determines whether the file belongs to PNG." << std::endl;
    std::cin >> fileName;
    filePng.open(fileName,std::ios::binary);
    assert(filePng.is_open());
    filePng.read(isPng, sizeof(isPng));
    if ((static_cast<int>(isPng[0])==-119) && (isPng[1]=='P') && (isPng[2]=='N') && (isPng[3]=='G'))
        std::cout << "This file belongs to png files.";
    else std::cout << "This is not a png file.";
    filePng.close();
    return 0;
}
