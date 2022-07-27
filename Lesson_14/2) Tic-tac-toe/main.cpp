#include <iostream>
#define SIZE 3
#define WIN 1

void fieldOutput(char mass[][SIZE])
{
    for (int i(0); i<(SIZE) ; i++)
    {
        for (int j(0); j<(SIZE) ; j++)
        {
            if (j==0) if (mass[i][j]==' ') std::cout << "["<<((i*3)+(j)+1)<<"]"<<"   |   ";
                      else std::cout << mass[i][j] <<"   |   ";
            else if (j==2) if (mass[i][j]==' ') std::cout << "   |   " << "["<<(j+1)*(i+1)<<"]";
                           else std::cout << "   |   " << mass[i][j];
            else if (mass[i][j]==' ') std::cout << "["<<(i*j)+2*(j+i)<<"]";
                 else std::cout << mass[i][j];
        }
        std::cout<<"\n"<<std::endl;
    }
};

bool win(char ticTacToe[][SIZE],int number)
{
   if (number<4) {
       if ( ( ticTacToe[0][0] == ticTacToe[0][1] ) && ( ticTacToe[0][1] == ticTacToe[0][2] ) ) return WIN;
       else if ( ( ticTacToe[0][number-1] == ticTacToe[1][number-1] ) && ( ticTacToe[1][number-1] == ticTacToe[2][number-1] ) ) return WIN;
       else return 0;
   }
    else if (number<7) {
        if ( ( ticTacToe[1][0] == ticTacToe[1][1] ) && ( ticTacToe[1][1] == ticTacToe[1][2] ) ) return WIN;
        else if ( ( ticTacToe[0][number-4] == ticTacToe[1][number-4] ) && ( ticTacToe[1][number-4] == ticTacToe[2][number-4] ) ) return WIN;
        else return 0;
    }
    else  {
        if ( ( ticTacToe[2][0] == ticTacToe[2][1] ) && ( ticTacToe[2][1] == ticTacToe[2][2] ) ) return WIN;
        else if ( ( ticTacToe[0][number-7] == ticTacToe[1][number-7] ) && ( ticTacToe[1][number-7] == ticTacToe[2][number-7] ) ) return WIN;
        else return 0;
    }
}

bool enterMotion(char ticTacToe[][SIZE], char game_name)
{
    int number;
    bool isCorrect;
    do {
        fieldOutput(ticTacToe);
        std::cout << "The first player walks:  ";
        std::cin >> number;
        isCorrect = true;
        if ((number < 10) && (number > 0)) {
            if (number < 4) {
                if (ticTacToe[0][number - 1] != ' ') {
                    std::cout << "Error. Enter the number again." << std::endl;
                    isCorrect = false;
                } else {
                    ticTacToe[0][number - 1] = game_name;
                    if (win(ticTacToe, number) == WIN) return WIN;
                }
            } else if (number < 7) {
                if (ticTacToe[1][number - 4] != ' ') {
                    std::cout << "Error. Enter the number again." << std::endl;
                    isCorrect = false;
            } else {
                ticTacToe[1][number - 4] = game_name;
                if (win(ticTacToe, number) == WIN) return WIN;
            }
        } else if (number < 10) {
            {
                if (ticTacToe[2][number - 7] != ' ') {
                    std::cout << "Error. Enter the number again." << std::endl;
                    isCorrect = false;
                } else {
                    ticTacToe[2][number - 7] = game_name;
                    if (win(ticTacToe, number) == WIN) return WIN;
                }
            }
        } else {
            std::cout << "Error. Enter the number again." << std::endl;
            isCorrect = false;
        }
    }
    }while (isCorrect==false);
    return 0;
}




int main() {

    char ticTacToe[SIZE][SIZE]={{' ',' ',' '},
                                {' ',' ',' '},
                                {' ',' ',' '}};

    int count (0);
    char game_name('X');

    std::cout << "You are welcomed by the game tic tac toe!" << std::endl;
    std::cout << "Enter the cell number for the move." << std::endl;

    while ( count != (SIZE*SIZE) )
    {
        if (enterMotion(ticTacToe,game_name)==WIN)
        {
            fieldOutput(ticTacToe);
            std::cout << "Congratulations on your victory.";
            if (game_name == 'X') std::cout << " Player one.";
            else std::cout << " Player two.";
            break;
        }
        else
        {
            if (game_name == 'X') game_name = 'O';
            else game_name = 'X';
            count++;
        }
    }

return 0;
}