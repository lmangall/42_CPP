#include "ScavTrap.hpp"
#include <iostream>

//This implementation showcases how ScavTrap inherits from ClapTrap and modifies certain behaviors to reflect its own characteristics, such as different hit points, energy points, attack damage, and an additional behavior (guardGate). The output from running these tests should demonstrate the unique messages from ScavTrap as well as the inherited functionalities from ClapTrap.

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[34mScavTrap is born! (from default constructor)\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "\033[34mScavTrap " << _name << " is born! (from parametrized constructor)\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "\033[34mScavTrap copy constructor called.\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "\033[34mScavTrap copy assignment operator called.\033[0m" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "\033[33mScavTrap " << _name << " is destroyed.\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "\033[34mScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "\033[34mScavTrap " << _name << " is now in Gate keeper mode.\033[0m" << std::endl;
}