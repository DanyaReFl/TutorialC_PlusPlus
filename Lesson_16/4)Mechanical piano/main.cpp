#include <iostream>



enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {

    int notes[12][5]={};
    int melody[12];

    std::cout << "The program outputs the received melody." << std::endl;

    for (int i (0) ; i<12 ; i++)
    {
        std::cout << "Enter a note from 1-7:" ;
        std::cin >> melody[i];
        for  (int j (0) ; melody[i]>0 ; j++)
        {
            notes[i][j]+=1<<((melody[i]-1)%10);
            melody[i]/=10;
        }
    }

    for (int i (0) ; i<12 ; i++)
    {
        for (int j(4) ; j>=0 ; j-- ) {
            if (notes[i][j]!=0) {
                if (notes[i][j] & DO) {
                    std::cout << "DO ";
                }
                if (notes[i][j] & RE) {
                    std::cout << "RE ";
                }
                if (notes[i][j] & MI) {
                    std::cout << "MI ";
                }
                if (notes[i][j] & FA) {
                    std::cout << "FA ";
                }
                if (notes[i][j] & SOL) {
                    std::cout << "SOL ";
                }
                if (notes[i][j] & LA) {
                    std::cout << "LA ";
                }
                if (notes[i][j] & SI) {
                    std::cout << "SI ";
                }
            }
        }
    }


    return 0;
}
