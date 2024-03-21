#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clapTrap("CT-01");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(2);
    clapTrap.beRepaired(5);

    return 0;
}
