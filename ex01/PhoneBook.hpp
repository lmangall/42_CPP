#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <cstddef> // For std::size_t

//The class declaration is in .hpp


class PhoneBook {
private:
    Contact contacts[8];
    std::size_t currentSize;
public:
    PhoneBook(); // Constructor declaration
    void addContact(const Contact& newContact);
    const Contact& getContact(int index) const;
    std::size_t getSize() const;
};

#endif






// PhoneBook class has at least two public methods: addContact and searchContacts,