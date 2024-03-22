#ifndef ARAKI_H
#define ARAKI_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    void makeSound() const;
};

#endif