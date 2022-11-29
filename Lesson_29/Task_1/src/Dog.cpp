#include "TalentAndDog_Class.h"

    Dog::Dog (std::string str):name(std::move(str)){};

    void Dog::addTalent(Talent *talent)
    {
        AllDogTalent.push_back(talent);
    }

    void Dog::show_talents() const
    {
        for (auto it : AllDogTalent)
        {
            it->talent();
        }
    }
