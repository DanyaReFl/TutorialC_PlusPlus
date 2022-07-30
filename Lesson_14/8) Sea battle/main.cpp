#include <iostream>

#define SIZE 10
#define diff_X X-X_0
#define diff_Y Y-Y_0
#define countWin 20

bool isShip(bool field[][SIZE],int sizeShip)
{
    int X_0,Y_0,X,Y;
    std::cout << "Enter the coordinates of the beginning: ";
    std::cin >> X_0 >> Y_0;
    if (sizeShip==1)
    {
        if (field[X_0][Y_0])
        {
            std::cout << "Error input (there is already a ship in this cell)."<< std::endl;
            return false ;
        }
        else
        {
            field[X_0][Y_0]=true;
            return true;
        }
    }
    else if ( (sizeShip >1) && (sizeShip <5) )
    {
        std::cout << "Enter the coordinates of the end: ";
        std::cin >> X >> Y;

        if ( ((diff_X)!=0) && (diff_Y)==0)
        {
            if ( (diff_X+1)!=sizeShip)
            {
                std::cout << "Input error (size)."<< std::endl;
                return false ;
            }
            else
            {
                for (int i=X_0 ; i < X ; i++)
                {
                    if (field[i][Y])
                    {
                        std::cout << "Error input (there is already a ship in this cell)."<< std::endl;
                        return false ;
                    }
                    else field[i][Y]=true;
                }
                return true;
            }
        }

        else if ( ((diff_Y)!=0) && (diff_X)==0)
        {
            if ( (diff_Y+1)!=sizeShip)
            {
                std::cout << "Input error (size)."<< std::endl;
                return false ;
            }
            else
            {
                for (int i = X_0; i < X; i++) {
                    if (field[i][Y]) {
                        std::cout << "Error input (there is already a ship in this cell)." << std::endl;
                        return false;
                    } else field[i][Y] = true;
                }
                return true;
            }
        }

        else return false ;
    }

    else return false ;
}

void placeShip(bool field[][SIZE])
{
    for (int i(0) ; i<4 ; i++ )
    {
        std::cout << "Single - deck ship ["<<i+1<<"]:"<<std::endl;
        while(!isShip(field,1));
    }
    for (int i(0) ; i<3 ; i++ )
    {
        std::cout << "Single - deck ship ["<<i+1<<"]:"<<std::endl;
        while(!isShip(field,2));
    }
    for (int i(0) ; i<2 ; i++ )
    {
        std::cout << "Single - deck ship ["<<i+1<<"]:"<<std::endl;
        while(!isShip(field,3));
    }

        std::cout << "Single - deck ship ["<<1<<"]:"<<std::endl;
        while(!isShip(field,4));

}

bool attackShip(bool field[][SIZE])
{
    int X,Y;
    std::cout<<"Enter coordinates X:";
    std::cin >> X;
    std::cout<<"Enter coordinates Y:";
    std::cin >> Y;

    if ( (X>=0) && (X<=10) && (Y>=0) && (Y<=10) && (field[X][Y]))
    {
        std::cout << "Hitting the ship!!!" << std::endl;
        field[X][Y]=false;
        return true;
    }
    else
    {
        std::cout << "Miss!" <<std::endl;
        return false;
    }
}

int main() {

    bool field_1[SIZE][SIZE]{0},field_2[SIZE][SIZE]{0};
    int numberShipOne(countWin),numberShipTwo(countWin);

    std::cout << "The game \"Sea Battle\" welcomes you!" << std::endl;
    std::cout << "First player fill in the field!"<< std::endl;
    placeShip(field_1);
    std::cout << "Second player fill in the field!"<< std::endl;
    placeShip(field_2);

    while (true)
    {
        std::cout << "First player attack!!!"<<std::endl;
        if (attackShip(field_2))
            numberShipTwo-=1;
        if (numberShipTwo==0)
        {
            std::cout << "The first player WON!!!";
            return 0;
        }
        std::cout << "Second player attack!!!"<<std::endl;
        if (attackShip(field_1))
            numberShipOne-=1;
        if (numberShipOne==0)
        {
            std::cout << "The second player WON!!!";
            return 0;
        }
    }

    return 0;

}
