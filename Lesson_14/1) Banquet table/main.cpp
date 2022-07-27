#include <iostream>

int main() {

    // Fork, spoon, knife and dessert spoon.
    int tableware[12][4]={{1,1,1,1}, //VIP
                          {1,1,1,1}, //VIP
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0},
                          {1,1,1,0}};

    // A plate for the first course , for the second and for dessert.
    int plates[12][3]={{1,1,1}, //VIP
                       {1,1,1}, //VIP
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0},
                       {1,1,0}};

    // Number of chairs.
    int chairs [12][1]={{1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1},
                        {1}};

    chairs[4][0]+=1; // Put another chair in the fifth place.
    tableware[7][1]-=1; // Stole a spoon.
    tableware[0][1]-=1; tableware[7][1]+=1; // VIP person shared a spoon.
    plates[0][2]-=1; // The waiter took one dessert plate from the VIP guest.

    return 0;
}
