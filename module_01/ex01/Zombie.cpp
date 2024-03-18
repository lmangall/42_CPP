#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <sstream> // For std::stringstream


// Inside the constructors, destructor, and the announce function,
// 'this' is used to print the memory address of the current Zombie object.

Zombie::Zombie()
{
    std::cout << "A zombie has been created with the default constructor @ " << this << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
    std::cout << _name << " has been named with the parameterized constructor @ " << this << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed @ " << this << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ... @ " << this << std::endl;
}
