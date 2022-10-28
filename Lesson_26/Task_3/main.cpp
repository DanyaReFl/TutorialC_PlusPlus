#include <iostream>
#include <vector>

class Desktop
{
private:

    int monitor_x = (80) ;
    int monitor_y = (50) ;
    int window_x = 0 ;
    int window_y = 0 ;
    int width = 20 ;
    int height = 10 ;

public:

    void setWindow()
    {
        int win;
        std::cout << "Enter the coordinates" << std::endl;
        while (true) {
            std::cout << "X= ";
            std::cin >> win;
            if ( ( win + width ) <= monitor_x ) break;
            else std::cout << "The window does not fit on the monitor." << std::endl;
        }
        window_x=win;

        while (true) {
            std::cout << "Y= ";
            std::cin >> win;
            if ( ( win + height ) <= monitor_y ) break;
            else std::cout << "The window does not fit on the monitor." << std::endl;
        }
        window_y=win;
    }

    void resize()
    {
        int resize;
        while (true)
        {
            std::cout << "Enter the width: ";
            std::cin >> resize;
            if ( ( resize >= 0 ) && ( ( resize + window_x ) <= monitor_x ) ) break;
            else std::cout << "The window does not fit on the monitor." << std::endl;
        }
        width = resize;

        while (true)
        {
            std::cout << "Enter the height: ";
            std::cin >> resize;
            if ( ( resize >= 0 ) && ( ( resize+window_y ) <= monitor_y ) ) break;
            else std::cout << "The window does not fit on the monitor." << std::endl;
        }
        height = resize;
    }

    void display()
    {
        for (int win_y ( 0 ) ; win_y < ( monitor_y ) ; win_y++ )
        {
            for (int win_x ( 0 ) ; win_x < ( monitor_x ) ; win_x++ )
            {
                if ( ( win_x >= window_x ) && ( win_x <= ( width + window_x ) ) &&
                ( win_y >= window_y ) && ( win_y <= ( height + window_y ) ) )
                    std::cout << "1" ;
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    std::string command;
    Desktop myDesk;

    std::cout << "Desktop window management programs." << std::endl;

    while ( true )
    {
        std::cout << "Enter the command(move/resize/display/close): ";
        std::cin >> command;

        if ( ( command == "move" ) || ( command == "Move" ) )
        {
            myDesk.setWindow();
        }
        else if ( ( command == "resize" ) || ( command == "Resize" ) )
        {
            myDesk.resize();
        }
        else if ( ( command == "display" ) || ( command == "Display" ) )
        {
            myDesk.display();
        }
        else if ( ( command == "close" ) || ( command == "Close" ) )
        {
            std::cout << "Exiting the program." << std::endl; break;
        }

        else std::cout << "Command input error." << std::endl;

    }

    return 0;
}
