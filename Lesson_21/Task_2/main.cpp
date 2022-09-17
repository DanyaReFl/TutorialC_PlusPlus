#include <iostream>
#include <vector>

enum room_type
{
    bedroom=0,
    kitchen,
    bathroom,
    children,
    living
};

struct rooms
{
   room_type room_t;
   float square;
};

enum extensions
{
    bathhouse=0,
    barn,
    garage
};

struct house
{
    float square;
    extensions ext;
    bool pipe_bathhouse;
};

struct floor
{
    std::vector<rooms> room;
    float floor_height;
};

struct residen_build
{
    float square;
    floor floors[5];
    bool pipe;
};

struct village
{
    int number;
    residen_build home;
    std::vector<house> ext_home;
};


int main() {

    int size , number_house ,number_floor(0), type_room,room;
    float square, height(0);
    char answer[4];

    std::cout << "Data model for the village!" << std::endl;
    std::cout << "Enter the number of plots: ";
    std::cin >> size;
    village vil[size];
    int i(0);
    while( i != size )
    {

        vil[i].number=i+1;

        std::cout << "What are the extensions on the site((1)bathhouse,(2)barn,(3)garage)"
                     " enter a number without a space: ";
        std::cin >> number_house;

        while(number_house)
        {
            if ( (number_house%10)==3)
            {
                std::cout<<"Enter the area of the garage:";
                std::cin >> square;
                house newHouse={square,garage, false};
                vil[i].ext_home.push_back(newHouse);
                number_house=number_house /10;
            }
            if ( (number_house%10)==2)
            {
                std::cout<<"Enter the area of the barn:";
                std::cin >> square;
                house newHouse={square,barn,false};
                vil[i].ext_home.push_back(newHouse);
                number_house=number_house /10;
            }
            if ( (number_house%10)==1)
            {
                std::cout<<"Enter the area of the bathhouse:";
                std::cin >> square;
                std::cout << "There is a stove with a pipe in the bath(yes/no): ";
                std::cin >> answer;
                if (answer=="yes") { house newHouse={square,bathhouse,true};vil[i].ext_home.push_back(newHouse); }
                else { house newHouse={square,bathhouse,false}; vil[i].ext_home.push_back(newHouse); }
                number_house=number_house /10;
            }
        }


        std::cout << "Enter the area of the residential building:";
        std::cin >> square;
        vil[i].home.square=square;
        std::cout << "There is a stove with a pipe in the apartment building(yes/no):";
        std::cin >> answer;
        if (answer=="yes") vil[i].home.pipe=true;
        else vil[i].home.pipe=false;
        std::cout << "Number of floors: ";
        while( true ) {
            std::cin >> number_floor;
            if ((number_floor > 0) && (number_floor < 4)) break;
            else std::cout << "Error . There should be more floors from 1 to 3." << std::endl;
        }
        for (int j(0) ; j<number_floor ; j++)
        {
            std::cout << "Enter the height of the "<<j+1<<" floor: ";
            std::cin >> height;
            vil[i].home.floors[j].floor_height=height;

            std::cout << "Select the rooms that are on the floor ((1)bedroom,(2)kitchen,(3)bathroom,(4)children,(5)living): ";
            std::cin >> type_room;
            while (type_room>0)
            {
            room=type_room%10;

            switch (room) {
                case 1: {
                    std::cout << "Enter the area of the bedroom room:";
                    std::cin >> square;
                    rooms newRooms = {bedroom, square};
                    vil[i].home.floors[j].room.push_back(newRooms);
                    break;
                }
                case 2: {
                    std::cout << "Enter the area of the kitchen room:";
                    std::cin >> square;
                    rooms newRooms = {kitchen, square};
                    vil[i].home.floors[j].room.push_back(newRooms);
                    break;
                }
                case 3: {
                    std::cout << "Enter the area of the bathroom room:";
                    std::cin >> square;
                    rooms newRooms = {bathroom, square};
                    vil[i].home.floors[j].room.push_back(newRooms);
                    break;
                }
                case 4: {
                    std::cout << "Enter the area of the children room:";
                    std::cin >> square;
                    rooms newRooms = {children, square};
                    vil[i].home.floors[j].room.push_back(newRooms);
                    break;
                }
                case 5: {
                    std::cout << "Enter the area of the living room:";
                    std::cin >> square;
                    rooms newRooms = {living, square};
                    vil[i].home.floors[j].room.push_back(newRooms);
                    break;
                }
                default:
                    std::cout << "Error." << std::endl;
            }
                type_room/=10;
            }

        }
        i++;
    }

    return 0;
}
