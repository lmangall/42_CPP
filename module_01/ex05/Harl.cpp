#include <iostream>
#include <string>
#include "Harl.hpp"


Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}
void Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error" << std::endl;
}

/**
 * @brief Calls a complaint function based on the specified level.
 * 
 * This function maps a given string `level` to one of Harl's private member functions:
 * debug, info, warning, or error. Each function corresponds to a different level of
 * severity for a complaint. Once the matching level is found, the corresponding
 * complaint function is called.
 * 
 * @param level A string representing the severity level of the complaint. Valid values
 * are "DEBUG", "INFO", "WARNING", and "ERROR".
 */
void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// Array of pointers to member functions
    void (Harl::*ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    bool found = false;

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
 			// dereferences the member function pointer and calls the function on 'this' object
            // 'this' is a pointer to the current object, so 'this->*ptrs[i]' accesses the member function pointed by ptrs[i] and calls it
            (this->*ptrs[i])();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Harl: \"" << level << "\" is not a valid complaint level." << std::endl;
    }
}