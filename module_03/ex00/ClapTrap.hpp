#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other); // Copy constructor
    ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif