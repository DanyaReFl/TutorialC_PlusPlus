#include "functionRegistry.cpp"

int main() {
    std::vector<Registry<int,std::string>> arrayRegistry;
    std::string commandRegistry;

    std::cout << "Data registry on templates." << std::endl;
    while (true) {
        std::cout << "Enter the command(add/remove/print/find/exit): ";
        std::getline(std::cin >> std::ws , commandRegistry) ;
        if (commandRegistry=="add") addRegistry(arrayRegistry);
        else if (commandRegistry=="remove") removeRegistry(arrayRegistry);
        else if (commandRegistry=="print") printRegistry(arrayRegistry);
        else if (commandRegistry=="find") findRegistry(arrayRegistry);
        else if (commandRegistry=="exit") {std::cout << "The program has finished its work."; break;}
        else std::cout << "There is no such command." << std::endl;
    }
    return 0;
}
