#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

int main()
{
    std::string name;
    const std::string NAME_FILMS[5] = {"The Last Samurai","Once Upon a Time... in Hollywood",
                                  "Four Rooms","RocknRolla","Snatch"};

    std::ifstream disk("Film.json");
    if (!disk.is_open()) std::cout << "File opening error." << std::endl;
    else {
        nlohmann::json film[6];
        disk >> film[0];
        for (int i(1) ; i<6 ; i++){
            film[i] = film[0][NAME_FILMS[i-1]];
        }

        std::cout << "Enter the actor's first and last name:";
        std::getline(std::cin, name);

        for (int i(1); i < 6; i++){
            if (film[i][name] != nullptr)
                std::cout << "The name of the movie: " << NAME_FILMS[i - 1] << ".  Role in the film: " << film[i][name]
                          << std::endl;
        }
    }
    return 0;
}
