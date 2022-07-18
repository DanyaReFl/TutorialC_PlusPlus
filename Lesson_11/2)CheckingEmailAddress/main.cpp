#include <iostream>
#define INVALID false;
#define VALID true;

bool isInclude( std::string &str, int i , bool isFirstPart)
{
    if (isFirstPart)
    {
        if ( ( ( str[i] >= '0' ) && (str[i] <= '9') ) || ( ( str[i] >= 'A' ) && (str[i] <= 'Z') )
        || ( ( str[i] >= 'a' ) && (str[i] <= 'z')
        || (str[i] == '-') || (str[i] == '.') || (str[i] == '!')|| (str[i] == '#') || (str[i] == '$')
        || (str[i] == '%') || (str[i] == '&') || (str[i] == '\'') || (str[i] == '*') || (str[i] == '+')
        || (str[i] == '-') || (str[i] == '/') || (str[i] == '=') || (str[i] == '?') || (str[i] == '^')
        || (str[i] == '_') || (str[i] == '`') || (str[i] == '{') || (str[i] == '|') || (str[i] == '}')
        || (str[i] == '~') ) ) return VALID;
    }
    else
    {
        if ( ( ( str[i] >= '0' ) && (str[i] <= '9') ) || ( ( str[i] >= 'A' ) && (str[i] <= 'Z') )
        || ( ( str[i] >= 'a' ) && (str[i] <= 'z') ) || (str[i] == '-') || (str[i] == '.') ) return VALID;
    }
    return INVALID;
}

int  firstPartEmail(std::string &firstPart,int count )
{
    if ( firstPart[0]=='.' ) return INVALID;
    for ( ; (firstPart[count]!='@') && (firstPart.length()>count) ; count++ )
    {
        if ( (firstPart[count-1]=='.') && (firstPart[count]=='.') && (count!=0) ) { return INVALID; }
        else if ( !isInclude(firstPart,count ,true ) ) { return INVALID; }
    }
    if ( (count<1) || (count>64) || ( firstPart.length()==count ) ) { return INVALID; }
    else return count;
}

int  lastPartEmail(std::string &lastPart,int i){
    int j(1);
    if ( lastPart[(lastPart.length()-1)]=='.' ) { return INVALID; }
    for ( ; ( (lastPart.length()>(j+i)) && (lastPart[i+j]!='@') ) ; j++ )
    {
        if ( (lastPart[j+i-1]=='.') && (lastPart[j+i]=='.') && (j!=1) ) { return INVALID; }
        else if ( !isInclude(lastPart,j+i,false) ) { return INVALID; }
    }
    if ( (j<1) || (j>63) || (lastPart.length()!=i+j ) ) { return INVALID; }
    else return j;
}


int main() {

    std:: string email;
    int isEmail(0);

    std::cout << "The program checks the correctness of the entered email address." << std::endl;
    std::cout << "Enter the email address:";
    std::getline(std::cin,email);
    isEmail=firstPartEmail(email,isEmail);
    isEmail=lastPartEmail(email,isEmail);
    if ( isEmail==false ) std::cout << "Error. Invalid email.";
    else std::cout << "Email: " << email << " correct.";
    return 0;
}
