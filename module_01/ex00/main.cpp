#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Alfred_the_Zombie";
	//A Zombie named "Alfred_the_Zombie" is created on the heap. 
	//This is done by calling newZombie, which returns a pointer to the dynamically allocated Zombie. 
	//The object is manually deleted after use:
	Zombie *pointer_to_alfred = newZombie("Alfred_the_Zombie"); // Heap
	pointer_to_alfred->announce();
	// Deleting the dynamically allocated Zombie calls the destructor
	delete pointer_to_alfred;

	randomChump("Bernard_the_Zombie");
}