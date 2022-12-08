#include <iostream>
#include <map>
#include <cpr/cpr.h>

void GetCpr(const std::map<std::string, std::string> &arguments)
{
    std::string service{"http://httpbin.org/get?"};
    for (auto it = arguments.begin(); it != arguments.end(); it++)
    {
        service +=it->first + "=" + it->second + "&";

    }
    service = service.substr(0,service.length()-1);
    cpr::Response r = cpr::Get(cpr::Url(service));
    std::cout << r.text << std::endl;
}

void PostCpr(const std::map<std::string, std::string> &arguments)
{
    std::vector<cpr::Pair> postQuery;
    for (const auto& it : arguments)
    {
        postQuery.emplace_back((std::string)it.first,(std::string)it.second);
    }
    cpr::Payload k = cpr::Payload(postQuery.begin(),postQuery.end());
    cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),k);
    std::cout << r.text << std::endl;
}

int main()
{

    std::string title , value ;
    std::map<std::string, std::string> arguments;

    std::cout << "The program makes \"get\" and \"post\" requests." << std::endl;

    while (true)
    {
        std::cout << "Enter an argument: ";
        std::cin >> title;
        if ( ( title == "get" ) || ( title == "post" ) ) break;
        std::cout << "Enter a value: " ;
        std::cin >> value;
        if ( ( value == "get" ) || ( value == "post" ) ) break;
        arguments.emplace(std::pair(title,value));
    }
    if ( ( title == "get" ) || ( value == "get" ) )
    {
        GetCpr(arguments);
    }
    else
    {
        PostCpr(arguments);
    }

    return 0;
}