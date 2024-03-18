#include "Zombie.hpp"
#include <string>

// This function instantiates an object of the Zombie class
// with a specific name, and invokes a method on that object.
void	randomChump(std::string name)
{
	Zombie oneZombie(name);

	// The method call oneZombie.announce(); invokes the announce method on the oneZombie object.
	// This method is defined within the Zombie class
	oneZombie.announce();
}