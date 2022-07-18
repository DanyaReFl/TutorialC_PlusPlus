#include <iostream>
#define VALID 1;
#define INVALID 0;

int octet(std::string ip, int i)
{
    int j(0);
    for (; ( (ip[i]!='.') ) && (ip.length()>i) ; i++){
        if ( (ip[i]<'0') || (ip[i]>'9') ) return INVALID;
        j++;

    }
    if  ( (ip[i-j]=='0' ) && (ip[i-j+1]!='.') ) return INVALID;
    if (j==3) {
        if ( ( ((ip[i-3]-'0')*100)+((ip[i-2]-'0')*10)+(ip[i-1]-'0') )>255) { return  INVALID ; }
        else return i;
    }
    else if (j>3) return 0;
    else if (j==0) return 0;
    else return i;
}

bool isValid(std::string ip)
{
    int countPoint (0);
    for (int i=0 ; ip.length()>i ; i++)
    {
        i=octet(ip,i);
        if (i==0) { return  INVALID ; }
        else countPoint++;
    }
    if ( (ip[ip.length()-1]=='.' ) || (countPoint!=4) ) { return  INVALID ; }
    else return VALID;
}


int main() {

    std::string ip;

    std::cout << "The program checks the IP address for validity." << std::endl;
    std::cout << "Enter the Ip-address(IPv4): ";
    std::getline(std::cin,ip);
    if (isValid(ip)) std::cout << "The IP-address is valid.";
    else std::cout << "The IP-address is invalid..";

    return 0;
}