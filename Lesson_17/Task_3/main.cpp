#include <iostream>



bool substr(const char *str , const char *sub)
{
    while(*str)
    {   const char* sSub = sub;
        while(*str && *str != *sub) str++;
        while(*str && *sSub && *str == *sSub){str++; sSub++;}
        if(*sSub == 0) return true;
    }
    return false;
}


int main() {

    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";

    std::cout << substr(a,b) << "  " << substr(a,c);


    return 0;
}
