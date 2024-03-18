#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie	*newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}