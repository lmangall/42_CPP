#include "Zombie.hpp"
#include <iostream>



// It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
// zombies, giving each one of them the name passed as parameter. The function returns a
// pointer to the first zombie.
// Implement your own tests to ensure your zombieHorde() function works as expected.
// Try to call announce() for each one of the zombies.
// Don’t forget to delete all the zombies and check for memory leaks.


int main(void){
	
	Zombie *PointerToFirstZombie = zombieHorde(5, "SeveralZombies");

	for (int i = 0; i < 5; i++){
		std::cout << "Zombie" << i << "is announcing himself:";
		PointerToFirstZombie[i].announce();
	}
	delete[] PointerToFirstZombie;
	return 0;
}