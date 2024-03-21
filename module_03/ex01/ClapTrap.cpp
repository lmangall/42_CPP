#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[94mClapTrap " << _name << " has been created.\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[94mClapTrap " << _name << " has been created, he received his points\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "\033[94mClapTrap " << _name << " has been created through the copy creator.\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "\033[94mClapTrap " << _name << " has been assigned.\033[0m" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "\033[31mClapTrap " << _name << " has been destroyed.\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "\033[94mClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "\033[94mClapTrap " << _name << " has no energy or hit points to attack!\033[0m" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        std::cout << "\033[94mClapTrap " << _name << " took " << amount << " points of damage!\033[0m" << std::endl;
    } else {
        std::cout << "\033[94mClapTrap " << _name << " cannot take more damage!\033[0m" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "\033[94mClapTrap " << _name << " has been repaired for " << amount << " hit points!\033[0m" << std::endl;
    } else {
        std::cout << "\033[94mClapTrap " << _name << " has no energy to be repaired!\033[0m" << std::endl;
    }
}
