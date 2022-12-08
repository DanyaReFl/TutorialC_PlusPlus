#include <iostream>
#include <cpr/cpr.h>

int main()
{

    int start{0}, end{0};

    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),cpr::Header({{"Accept","text/html"}}));
    start = r.text.find("<h1>") + 4 ;
    end = r.text.find("</h1>");
    for ( ; start < end ; start ++ )
    {
        std::cout << r.text[start];
    }

    return 0;
}
