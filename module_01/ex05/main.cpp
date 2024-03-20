#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << std::endl << "Usage: ./harlFilter <level>" << std::endl;
        std::cout << "levels : DEBUG, INFO, WARNING, ERROR" << std::endl << std::endl;
        return 1;
    }

    std::string level = argv[1];
    Harl harl;
    harl.complain(level);

    return 0;
}