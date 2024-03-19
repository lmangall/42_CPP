#include <string>
#include "Weapon.hpp"


// Member initializer list, used in a constructor to directly initialize member variables 
// before the constructor's body executes
Weapon::Weapon::Weapon(const std::string& type) : _type(type) {}


Weapon::~Weapon() {}

const std::string& Weapon::getType() const{
	// reference ref = this->type
	// return ref
	return _type;
}

void Weapon::setType(const std::string& newType) {
    _type = newType;
}
