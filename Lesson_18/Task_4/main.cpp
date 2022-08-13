#include <iostream>

bool flag (false);

void evenDigits(const long long n ,int &ans)
{
    while (flag==false)
    {
        if ((n/10)==0) flag=true;
        ((n % 10) % 2 == 0) ? evenDigits(n / 10, ++ans) : evenDigits(n / 10, ans);
    }
}

int main() {

    int ans(0);

    std::cout << "Counts the number of even numbers." << std::endl;

    evenDigits(922437203685482806, ans);
    std::cout << ans;

    return 0;
}
