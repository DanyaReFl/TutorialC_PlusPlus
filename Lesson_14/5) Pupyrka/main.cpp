#include <iostream>
#define SIZE 12
#define INIT {1,1,1,1,1,1,1,1,1,1,1,1}
#define ERROR 0
#define CORRECT 1

void screen (bool pupyrka[][SIZE])
{
    for (int i(0) ; i<SIZE ; i++ )
    {
        for (int j(0) ; j<SIZE ; j++ )
        {
            if (pupyrka[i][j]) std::cout<<"O  ";
            else std::cout<<"X  ";
        }
        std::cout<<std::endl;
    }
}

bool Check(int number)
{
    if ( (number > 12) || (number < 1) )
    {
        std::cout << "Error. Incorrect input of coordinates.";
        return ERROR;
    }
    else return CORRECT;
}

void bursting(bool pup[][SIZE],int X_0,int Y_0,int X,int Y,int &count)
{
    for (int i=(Y_0-1) ; i<=(Y-1) ; i++)
    {
        for (int j=(X_0-1) ; j<=(X-1) ; j++)
        {
            if (pup[i][j])
            {
                std::cout <<"Pop!  ";
                count++;
                pup[i][j]=false;
            }
        }
    }
    std::cout<<std::endl;
}

int main() {

    bool pupyrka[SIZE][SIZE]={INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT,INIT};
    int count(0),X_0,Y_0,X,Y;

    std::cout << "The program for bursting the pupyrka!" << std::endl;

    while (count!=144) {
        screen(pupyrka);
        std::cout << "Enter the coordinates for the rectangular area (X:1-12 and Y:1-12): " << std::endl;
        std::cout << "X_0= ";
        std::cin >> X_0;
        if (!Check(X_0)) continue;
        std::cout << "Y_0= ";
        std::cin >> Y_0;
        if (!Check(Y_0)) continue;
        std::cout << "X= ";
        std::cin >> X;
        if (!Check(X)) continue;
        std::cout << "Y= ";
        std::cin >> Y;
        if (!Check(Y)) continue;
        if ( (X-X_0<0) || (Y-Y_0<0) )
        {
            std::cout << "Error. Incorrect input of coordinates.";
            continue;
        }
        bursting(pupyrka,X_0,Y_0,X,Y,count);

    }
    screen(pupyrka);
    return 0;
}
