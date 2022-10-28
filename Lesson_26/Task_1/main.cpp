#include <iostream>
#include <ctime>
#include <fstream>
#include <cassert>

class Track
{
private:
    std::string name;
    std::time_t TIME = std::time(nullptr);
    std::tm* t = std::localtime(&TIME);
    std::string duration;
public:
    void SetName(std::string audioName){name=audioName;}
    void SetDuration(std::string audioDuration){duration=audioDuration;}
    std::string GetName(){return name;}
    std::tm* GetTime(){return t;}
    std::string GetDuration(){return duration;}

};

class audioPlayer
{
private:
    Track track;

};

int main() {

    std::srand(time(nullptr));
    Track audio[6];
    std::string audioName ,audioDuration;
    std::string command;
    bool isPlay(false),isPause(false);

    std::ifstream file("Data.txt");
    assert(file.is_open());
    for (int i(0) ; i<6 ; i++)
    {
        file>>audioName;
        audio[i].SetName(audioName);
        file>>audioDuration;
        audio[i].SetDuration(audioDuration);
    }

    std::cout << "Implementation of imitation of an audio player." << std::endl;
while(true) {

    std::cout << "Enter the command (play/pause/next/stop/exit) : ";
    std::cin >> command;

    if ((command == "Play") || (command == "play")) {
        std::cout << "Enter the name of the song:";
        std::cin >> audioName;
        if (!isPlay) {
            for (int j(0); j < 6; j++) {
                if (audioName == audio[j].GetName()) {
                    isPlay = true;
                    isPause = false;
                    std::cout << audio[j].GetName() << std::endl;
                    std::cout << audio[j].GetDuration() << std::endl;
                    std::cout << std::asctime(audio[j].GetTime()) << std::endl;
                    break;
                }
            }
            if(isPlay == false) { std::cout << "Song not found." << std::endl ; }
        }
    }
    else if ((command == "Pause") || (command == "pause")) {
        if ( isPlay && (!isPause) )
        {
            std::cout << "The song is paused.   " <<std::endl;
            isPause = true;
        }
    } else if ((command == "Next") || (command == "next")) {
        int k = rand() % 6;
        isPlay = true;
        isPause = false;
        std::cout << audio[k].GetName() << std::endl;
        std::cout << std::asctime(audio[k].GetTime()) << std::endl;
        std::cout << audio[k].GetDuration() << std::endl;
    } else if ((command == "Stop") || (command == "stop"))
    {
        if (isPlay) {
            std::cout << "The song is stopped." << std::endl;
            isPlay = false ;
            isPause = false ;
        }
    } else if ((command == "Exit") || (command == "exit")) {
        std::cout << "Exiting the program." << std::endl;
        break;
    } else {
        std::cout << "Command not found." << std::endl;
    }
}


    return 0;
}
