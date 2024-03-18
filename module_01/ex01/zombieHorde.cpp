#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name) {

    // Allocate memory for N Zombie objects in a single allocation
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++) {
        new(&zombies[i]) Zombie(name); // Placement new for each zombie
    }

    return zombies; // Return pointer to the first zombie
}

// It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
// zombies, giving each one of them the name passed as parameter. The function returns a
// pointer to the first zombie.

// Zombie* zombieHorde( int N, std::string name )
// {
// 	for (int i = 0; i < N; i++)
// 	{
// 		Zombie *zombie = new Zombie(name);
// 	}
// 	return (zombie);
// }