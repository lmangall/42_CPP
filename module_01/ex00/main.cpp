#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Alfred_the_Zombie";
	Zombie *pointer_to_alfred = newZombie(name);
	pointer_to_alfred->announce();
	// Deleting the dynamically allocated Zombie calls the destructor
	delete pointer_to_alfred;

	randomChump("Bernard_the_Zombie");
}