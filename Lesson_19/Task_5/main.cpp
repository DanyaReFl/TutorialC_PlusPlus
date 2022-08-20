#include <iostream>
#include <fstream>


int main() {

    std::ifstream text;
    int player(0),viewers(0),offset;
    bool mass[13]{0};
    std::string answer,question("");
    char buff[200];

    std::cout << "You are welcomed by the game \"What? Where? When?\"!" << std::endl;
    text.open("D:\\DDA\\TutorialC\\Lesson_19\\Task_5\\www.txt",std::ios::binary);

    while( ( player < 6 ) && ( viewers < 6 ) )
    {
        text.seekg(std::ios::beg);
        std::cout << "Enter the offset relative to the first question: "<<std::endl;
        std::cin >> offset;
        offset = (offset) % 13;
        while (mass[(offset)%13] == true) offset = (offset + 1) % 13;

        for (int i(0) ; i<(2*(offset)) ; i++ )
        {
            text.getline(buff,sizeof(buff));
        }

        text.getline(buff,sizeof(buff));
        std::cout << buff;
        std::cin >> answer;
        text>>question;
        if(answer==question) player++;
        else viewers++;
        mass[offset]=true;
        std::cout<<std::endl;
    }
    if (player==6) std::cout <<"Player won.";
    else std::cout <<"Viewers won.";
    text.close();
    return 0;
}
