#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clapTrap("CT-01");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(2);
    clapTrap.beRepaired(5);

    std::cout << "\033[34m" << std::endl << "Testing the basics" << "\033[0m" << std::endl;
    ClapTrap clap("Warrior");
    clap.attack("Target");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "\033[34m" << std::endl << "Testing the copy constructor" << "\033[0m" << std::endl;
    ClapTrap original("Original");
    ClapTrap copy = original; // Invoke copy constructor
    copy.attack("Another Target");

    std::cout << "\033[34m" << std::endl << "Testing the assignment operator" << "\033[0m" << std::endl;
    ClapTrap first("First");
    ClapTrap second("Second");
    second = first; // Copy assignment
    second.attack("Enemy");

    std::cout << "\033[34m" << std::endl << "Testing the energy points" << "\033[0m" << std::endl;
    ClapTrap tired("Tired");
    for (int i = 0; i < 10; i++) {
        tired.attack("the air"); // Do something harmless
    }
    tired.attack("Invisible Enemy");
    tired.beRepaired(1);

    std::cout << "\033[34m" << std::endl << "Testing the health" << "\033[0m" << std::endl;
    ClapTrap warrior("Warrior");
    warrior.takeDamage(10); // Assuming it starts with 10 hit points.
    warrior.attack("Enemy"); // Should be unable to attack.
    warrior.beRepaired(5); // Should not be able to repair beyond max hit points.

    std::cout << "\033[34m" << std::endl << "Testing with zero" << "\033[0m" << std::endl;
    ClapTrap zeroHero("ZeroHero");
    zeroHero.attack("Ghost"); // Should not reduce target's health.
    zeroHero.beRepaired(0); // Should not increase the ClapTrap's health.

    std::cout << std::endl;

    return 0;
}
