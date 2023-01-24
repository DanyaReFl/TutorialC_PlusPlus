#include <iostream>
#include <map>
#include "boost/asio.hpp"

void addBasketShopping(const std::map<std::string,int> &store , std::map<std::string,int> &current ) {
    std::string productName;
    int productCount;
    bool isAdd{false};

    std::cout << "Enter the product name: ";
    std::getline(std::cin >> std::ws, productName);

    for (const auto &it: store) {
        if (it.first == productName) {
            std::cout << "Enter the quantity of the product: ";
            std::cin >> productCount;
            if ((current.find(productName)) != current.end()) {
                current[productName] += productCount;
                if (current[productName] > it.second) {
                    throw std::runtime_error(current[productName] > 0 ? "There is not so much product in stock." :
                                             "The quantity of the product cannot be negative.");
                }
                isAdd=true;
                break;
            } else if ((productCount > it.second) || (productCount <= 0)) {
                throw std::runtime_error(productCount > 0 ? "There is not so much product in stock." :
                                         "The quantity of the product cannot be negative.");
            }
            current.insert(std::make_pair(productName, productCount));
            isAdd=true;
            break;
        }
    }
    if (!isAdd) throw std::invalid_argument("The product was not found.");
}

void removeBasketShopping(const std::map<std::string,int> &store , std::map<std::string,int> &current) {
    std::string productName;
    int productCount;
    bool isRemove{false};

    std::cout << "Enter the product name: ";
    std::getline(std::cin >> std::ws, productName);

    for (const auto &it: store) {
        if (it.first == productName) {
            std::cout << "Enter the quantity of the product: ";
            std::cin >> productCount;
            if ((current.find(productName)) != current.end()) {
                current[productName] -= productCount;
                if (current[productName] < 0) throw std::runtime_error("The quantity of the product cannot be negative");
                if ((productCount > it.second) || (productCount <= 0)) {
                    throw std::runtime_error(productCount > 0 ? "There is not so much product in stock." :
                                             "The quantity of the product cannot be negative.");
                }
                isRemove=true;
            }
            else {
                throw std::invalid_argument("The product is not in the basket.");
            }
        }
    }
    if (!isRemove) throw std::invalid_argument("The product was not found.");
}


int main() {

    boost::asio::io_context io;
    boost::asio::steady_timer t(io , boost::asio::chrono::seconds(5));
    t.wait();
    
    const std::map<std::string,int> storeBasketShopping = { {"ball",3 } , {"teddy bear",2} , {"candies",10} ,{"toy car",2}};
    std::map<std::string,int> currentBasketShopping;
    std::string commandShop;


    while (true) {
        std::cout << "Enter the command(add/remove/exit): ";
        std::cin >> commandShop;
        if (commandShop == "add") {
            try {
                addBasketShopping(storeBasketShopping,currentBasketShopping);
            }
            catch (std::invalid_argument &error) {
                std::cerr << "Mistake." << error.what();
                break;
            }
            catch (std::runtime_error &error) {
                std::cerr << "Error when entering the quantity of the product. " << error.what();
                break;
            }
        }
        else if  (commandShop == "remove") {

            try {
                removeBasketShopping(storeBasketShopping,currentBasketShopping);
            }
            catch (std::runtime_error &error) {
                std::cerr << "Error when entering the quantity of the product. " << error.what();
                break;
            }
            catch (std::invalid_argument &error) {
                std::cerr << "Mistake." << error.what();
                break;
            }

        }
        else if (commandShop == "exit") { std::cout << "Exit" ; break; }

        else try {throw std::invalid_argument("There is no such command.");}
        catch (std::invalid_argument &error) {
            std::cerr << "Mistake." << error.what();
            break;
        }
    }


    return 0;
}
