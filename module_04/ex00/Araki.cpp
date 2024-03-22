#include "Araki.h"

Dog::Dog() {
    _type = "Araki";
    std::cout << "Araki default constructor called    - Probably it's god, but not all agrees on the matter" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Araki copy constructor called,     - but we all know he is unique" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Araki destructor called    - whaaat? No!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "\033[31mHEY 🫵  you're not a bonobo, I'm not a dalmatian, capisce bro ?\033[0m" << std::endl;
}
