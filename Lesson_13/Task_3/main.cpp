#include <iostream>
#include <vector>
int main() {

    bool is(false);
    int n;
    int position(0);
    std::vector<int> base(20);

    std::cout << "Storage program for integer values." << std::endl;
    std::cout << "Input number: " ;
    std::cin>>n;
    while (n!=-2)
    {
        if (n==-1)
        {
            if (is)
                for ( int i=position ; i<base.size() ; i++ ){
                std::cout <<base[i]<< " ";
            }
            for ( int i(0) ; i<position ; i++ ){
                std::cout <<base[i]<< " ";
            }
            std::cout<<std::endl;
        }

        else
        {
            base[position] = n;
            position++;
            if (position==20) {
                position = 0;
                is=true;
            }

        }
        std::cout << "Input number: " ;
        std::cin >> n;
    }
    return 0;
}
