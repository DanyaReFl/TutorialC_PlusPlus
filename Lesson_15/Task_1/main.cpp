#include <iostream>


int main() {
    const short SIZE = 9;
    int mass[SIZE] ={-2,1,-3,4,-1,2,1,-5,4};
    int sum,i_max,j_max,sum_max(0);

    std::cout << "The program finds indexes between which the maximum sum in the array." << std::endl;

    for (int i(0) ; i< SIZE ; i++)
    {
        sum=mass[i];

        for (int j =i+1 ; j < SIZE ; j++)
        {
            sum+=mass[j];
            if (sum>sum_max)
            {
                sum_max=sum;
                j_max=j;
                i_max=i;
            }
        }
    }
    std::cout << "Indexes : "<<i_max<<"  "<<j_max;

    return 0;
}
