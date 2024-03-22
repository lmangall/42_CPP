#include "Animal.h"
#include "Araki.h"
#include <iostream>

int main() {
    const Dog* someAnimal = new Dog();
    const Dog* anotherAnimal = new Dog();
    std::cout << someAnimal->getType() << " " << std::endl;
    std::cout << anotherAnimal->getType() << " " << std::endl;
    someAnimal->makeSound(); //will output the cat sound!
    anotherAnimal->makeSound(); //will output Araki's message

    delete someAnimal;
    delete anotherAnimal;


    return 0;
}
