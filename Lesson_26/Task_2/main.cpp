#include <iostream>
#include <vector>
#include <map>

class UserBook
{
private:
    std::multimap<std::string,std::string> user;
public:

    std::multimap<std::string,std::string> getUser() {return user;}

    void add()
    {
        std::string name,phone;
        std::cout << "Enter a name: ";
        std::cin >> name;
        std::cout << "Enter phone number: ";
        while (true) {
            std::cin >> phone;
            if ((phone[0] == '+') && (phone[1] == '7') && (phone.length() == 12)) {
                user.insert(std::make_pair(name,phone));
                std::cout << "Name and phone number added to the address book." << std::endl;
                break;
            } else std::cout << "Invalid number format." << std::endl;
        }

    }
};

class Phone
{
private:
    UserBook book;
public:

    UserBook getBook(){return book;}

    void addBook()
    {
        book.add();
    }

    bool check () {
        std::string str;
        std::cout << "Enter the user's name or phone number: ";
        std::cin >> str;
        if ((str[0] == '+') && (str[1] == '7') && (str.length() == 12)) {
            for (auto it: book.getUser())
                if (it.second == str) return true;

            return false;
        } else {
            for (auto it : book.getUser())
            {
                if (it.first==str) return true;
            }
            return false;
        }
    }

    void call()
    {
        if (check()) std::cout << "CALL..." << std::endl;
        else std::cout << "Error." << std::endl;
    }

    void sms()
    {
        if (check())
        {
            std::string str;
            std::cout << "Enter a message: " ;
            std::cin >> str;
            std::cout << "The message has been sent." << std::endl;
        }
        else std::cout << "Error." << std::endl;
    }

};



int main()
{

    std::string command;
    Phone myPhone;

    std::cout << "Mobile phone simulator program!" << std::endl;

    while (true)
    {
        std::cout << "Enter the command(add/call/sms/exit) : " ;
        std::cin >> command;

        if ( (command=="add") || (command=="Add") )
        {
            myPhone.addBook();
        }
        else if ( (command=="call") || (command=="Call") )
        {
            myPhone.call();
        }
        else if ( (command=="sms") || (command=="Sms") )
        {
            myPhone.sms();
        }
        else if ( (command=="exit") || (command=="Exit") )
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
    }

    return 0;
}