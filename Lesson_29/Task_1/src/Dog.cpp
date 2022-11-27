#include "header.h"

    Dog::Dog (int number , std::string str):age(number),name(std::move(str))
    {
        uint8_t numberTalent = ( rand() % 3 ) + 1 ;
        if (numberTalent==3)
        {
            Talent *DogT = new Swimming;
            dogTalent.push_back(DogT);
            DogT = new Dancing;
            dogTalent.push_back(DogT);
            DogT = new Counting;
            dogTalent.push_back(DogT);
        }
        else if (numberTalent==2)
        {
            uint8_t num = rand() % 3;
            switch (num)
            {
                case 0 :
                {
                    Talent *DogT = new Swimming;
                    dogTalent.push_back(DogT);
                    DogT = new Dancing;
                    dogTalent.push_back(DogT);
                    break;
                }
                case 1 :
                {
                    Talent *DogT = new Swimming;
                    dogTalent.push_back(DogT);
                    DogT = new Counting;
                    dogTalent.push_back(DogT);
                    break;
                }
                case 2 :
                {
                    Talent *DogT = new Dancing;
                    dogTalent.push_back(DogT);
                    DogT = new Counting;
                    dogTalent.push_back(DogT);
                    break;
                }
            }
        }
        else
        {
            uint8_t num = rand() % 3;
            switch (num)
            {
                case 0 :
                {
                    Talent *DogT = new Swimming;
                    dogTalent.push_back(DogT);
                    break;
                }
                case 1 :
                {
                    Talent *DogT = new Dancing;
                    dogTalent.push_back(DogT);
                    break;
                }
                case 2 :
                {
                    Talent *DogT = new Counting;
                    dogTalent.push_back(DogT);
                    break;
                }
            }
        }
    }
    void Dog::voice() { std::cout << "Bark!" << std::endl; }
    void Dog::run() { std::cout << "The dog is running!" << std::endl; }
    void Dog::show_talents()
    {
        for (auto it : dogTalent)
        {
            it->getTalent();
        }
    }
