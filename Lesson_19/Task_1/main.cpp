#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream text;
    std::string word,word_text;
    std::vector<std::string> words;
    int count(0);

    text.open("D:\\DDA\\TutorialC\\Lesson_19\\Task_1\\words.txt");
    std::cout << "The program searches for a word in the text . \nEnter the word: ";
    std::cin >> word;

    while (!text.eof())
    {
        text >> word_text;
        if (word_text==word) count++;
        words.push_back(word_text);
    }
    text.close();
    std::cout << "Number of words in the text :" << count ;

    return 0;
}
