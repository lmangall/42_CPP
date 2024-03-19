#include <iostream>
#include <string>
#include "Harl.hpp"


Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

Harl::error(void)
{
	std::cout << "Error" << std::endl;
}


Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"
	};

	void (Harl::*ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

