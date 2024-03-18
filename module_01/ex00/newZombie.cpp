#include "Zombie.hpp"
#include <iostream>
#include <string>

//a Zombie object is dynamically allocated on the heap and its pointer is returned.
Zombie	*newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);// Dynamically allocated on the heap
	return (zombie);
}