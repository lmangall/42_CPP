#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been created, he received his points" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << _name << " has been created through the copy creator." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " has been assigned." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy or hit points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot take more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy to be repaired!" << std::endl;
    }
}
