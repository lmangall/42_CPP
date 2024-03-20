#include <string>
#include <iostream>
#include "HumanB.hpp"

	HumanB::HumanB(std::string name) : _name(name) {}

	HumanB::~HumanB(){}

	void HumanB::setWeapon(Weapon &weapon){
		this->_weapon = &weapon;
		//HumanB._weapon = &weaponType;       //   would that be possible ?
	}


	void HumanB::attack(){
    if (_weapon == 0)
        std::cout << _name << " attacks without any physical weapon, we presume he believes in god and is really courageous, or just feeling lucky, we don't really knw, he's a complex character" << std::endl;
    else
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
}
